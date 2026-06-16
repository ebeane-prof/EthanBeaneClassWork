# Colors
RED    := \033[31m
GREEN  := \033[32m
YELLOW := \033[33m
RESET  := \033[0m

CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -pedantic-errors -g

score: ../../src/list_implementations/*
	@printf "$(YELLOW)Compiling test$(RESET)\n"
	${CXX} ${CXXFLAGS} -I ../../src/include unit.cpp -o unit.out
	@valgrind --quiet --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./unit.out 2> feedback && (echo 100 >score; \
	printf "$(GREEN)Test successful$(RESET)\nScore: %s" "$$(cat score)") \
	|| printf "$(RED)Test failed$(RESET)\n"
	@[ -z "$$(cat feedback)" ] || printf "$(YELLOW)Feedback: $(RESET)\n%s" "$$(cat feedback)"

.PHONY: debug
debug:
	valgreen ./unit.out


