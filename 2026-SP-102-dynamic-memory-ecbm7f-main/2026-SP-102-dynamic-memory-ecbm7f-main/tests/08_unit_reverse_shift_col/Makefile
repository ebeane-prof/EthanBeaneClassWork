SOURCES := $(wildcard ../../src/*.cpp)
FUNC_SOURCES := ${filter-out ../../src/main.cpp, ${SOURCES}}

CPP = g++
CFLAGS = -Wall -Wextra -Wpedantic -pedantic-errors -g

# This wrapper prevents a student from merely exiting zero on any function...
expected_retcode := $(shell bash -c 'echo $$(((RANDOM % 250) + 5))')

pass: ../../src/*
	${CPP} ${CFLAGS} -I ../../src/ -I ../../.admin_files/ -I . unit.cpp ${FUNC_SOURCES} ../../.admin_files/*.hpp -o unit.out
	@rm -f *.o
	@actual_retcode=$$(./unit.out "$(expected_retcode)") && \
	[ $$actual_retcode -eq "$(expected_retcode)" ] && echo 100 >pass \
	|| (tput setaf 1 && echo "Test failed. Use 'make debug'" && tput sgr0 && exit 1)

.PHONY: debug
debug:
	gdb --quiet --command=.gdb_commands --args unit.out 123

