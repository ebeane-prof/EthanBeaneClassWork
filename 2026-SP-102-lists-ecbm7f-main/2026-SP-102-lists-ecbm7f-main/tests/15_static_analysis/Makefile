# Colors
RED    := \033[31m
GREEN  := \033[32m
YELLOW := \033[33m
RESET  := \033[0m

score: ../../src/list_implementations/*.ipp ../../src/include/*.hpp
	@cppcheck --enable=warning,style --suppressions-list=../../.admin_files/cppcheck_suppressions.txt --error-exitcode=1 --exitcode-suppressions=../../.admin_files/cppcheck_exitcode_suppressions.txt --language=c++ $^ 2> feedback \
	&& (echo 100 >score; printf "$(GREEN)Test successful$(RESET)\nScore: %s" "$$(cat score)") \
	|| printf "$(RED)Test failed$(RESET)\n"
	@[ -z "$$(cat feedback)" ] || printf "$(YELLOW)Feedback: $(RESET)\n%s" "$$(cat feedback)"


.PHONY: debug
debug: ../../src/list_implementations/*.ipp
	@cppcheck --verbose --enable=warning,style --suppressions-list=../../.admin_files/cppcheck_suppressions.txt --error-exitcode=1 --exitcode-suppressions=../../.admin_files/cppcheck_exitcode_suppressions.txt --language=c++ $^
