# Colors
RED    := \033[31m
GREEN  := \033[32m
YELLOW := \033[33m
RESET  := \033[0m

CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -pedantic-errors -g

# This wrapper prevents a student from merely exiting zero on any function...
expected_retcode := $(shell bash -c 'echo $$(((RANDOM % 250) + 5))')

score: ../../src/list_implementations/* ../../src/benchmarks/benchmark_functions.hpp
	@printf "$(YELLOW)Compiling test$(RESET)\n"
	${CXX} ${CXXFLAGS} -I ../../src/include -I ../../src/benchmarks -I ../../.admin_files/ unit.cpp -o unit.out
	@actual_retcode=$$(./unit.out "$(expected_retcode)" 2>feedback) && \
	[ $$actual_retcode -eq "$(expected_retcode)" ] && (echo 100 >score; \
	printf "$(GREEN)Test successful$(RESET)\nScore: %s" "$$(cat score)") \
	|| printf "$(RED)Test failed$(RESET)\n"
	@[ -z "$$(cat feedback)" ] || printf "$(YELLOW)Feedback: $(RESET)\n%s" "$$(cat feedback)"

.PHONY: debug
debug:
	gdb --quiet --command=.gdb_commands --args unit.out 123


