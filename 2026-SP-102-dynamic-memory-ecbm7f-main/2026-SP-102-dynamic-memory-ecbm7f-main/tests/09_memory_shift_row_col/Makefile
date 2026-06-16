SOURCES := $(wildcard ../../src/*.cpp)
FUNC_SOURCES := ${filter-out ../../src/main.cpp, ${SOURCES}}

CPP = g++
CFLAGS = -Wall -Wextra -Wpedantic -pedantic-errors -g

pass: ../../src/*.cpp
	${CPP} ${CFLAGS} unit.cpp ${FUNC_SOURCES} -o unit.out
	@valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./unit.out && echo 100 > pass \
	|| (echo "Memory test failed. Use 'make debug' for more information." && exit 1)

.PHONY: debug
debug:
	valgreen ./unit.out
