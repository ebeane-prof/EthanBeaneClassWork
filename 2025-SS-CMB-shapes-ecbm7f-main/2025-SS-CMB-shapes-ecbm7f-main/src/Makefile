HEADERS := $(wildcard *.h *.hpp)
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:%.cpp=../target/%.o)

CPP = g++
CFLAGS = -Wall -Wextra -Wpedantic -pedantic-errors -g

../target/main.out: ${OBJECTS}
	${CPP} ${CFLAGS} ${OBJECTS} -o ../target/main.out
	@rm -f ../target/*.o

../target/%.o: %.cpp ${HEADERS}
	${CPP} ${CFLAGS} -c $< -o $@
