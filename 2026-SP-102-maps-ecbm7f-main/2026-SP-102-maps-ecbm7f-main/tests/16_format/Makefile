# Colors
RED    := \033[31m
GREEN  := \033[32m
YELLOW := \033[33m
RESET  := \033[0m

score: ../../src/map_implementations/*.ipp
	@clang-format --dry-run --Werror --ferror-limit=1 $^ 2> feedback \
	&& (echo 100 >score; printf "$(GREEN)Test successful$(RESET)\nScore: %s" "$$(cat score)") \
	|| printf "$(RED)Test failed$(RESET)\n"
	@[ -z "$$(cat feedback)" ] || printf "$(YELLOW)Feedback: $(RESET)\n%s" "$$(cat feedback)"


.PHONY: debug
debug: ../../src/map_implementations/*.ipp
	@clang-format --verbose --dry-run --Werror $^

