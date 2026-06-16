language := "cpp"
code := $(wildcard src/*)
test_directories := $(wildcard tests/*)
test_targets := $(addsuffix /score,$(test_directories))
feedback_files := $(addsuffix /feedback,$(test_directories))
dependency_files := $(wildcard tests/*/.depends)
existing_passes := $(wildcard tests/*/score)
out_files := $(wildcard tests/*/*.out)
out_files += $(wildcard tests/*/out.*)

# Color Codes
RED    := \033[31m
GREEN  := \033[32m
YELLOW := \033[33m
CYAN   := \033[36m
BOLD   := \033[1m
RESET  := \033[0m

define start-test =
	@printf "\n$(BOLD)$(CYAN)============= make test: $(patsubst %/score,%/,$@) =============$(RESET)\n"
endef

define continue =
	[[ "$$IS_PIPELINE" ]] || (echo -en '\nPress `Enter` to continue:' && read)
endef

define start-section =
	@printf "\n$(BOLD)$(CYAN)============= make $@ =============$(RESET)\n"
endef

define check-deps
	@for dep in $(filter %/score, $^); do \
		if [ ! -f "$$dep" ]; then \
			printf "$(YELLOW)Skipping $(@D): dependency '$$dep' failed.$(RESET)\n"; \
			exit 0; \
		fi; \
	done
endef

define run-test
	cd $(@D) && $(MAKE) --no-print-directory
endef

.PHONY: all help prechecks build run test grade clean

all: # Runs the whole testing pipeline. Since it is the first target, `make` by itself runs `make all`.
	$(start-section)
	@$(MAKE) help --no-print-directory
	@$(MAKE) clean --no-print-directory
	-@$(MAKE) test --keep-going --no-print-directory
	@$(MAKE) summary --no-print-directory
	@$(MAKE) grade --no-print-directory

help: # Show help for each of the commented Makefile recipes.
	$(start-section)
	@grep -E '^[a-zA-Z0-9 -]+:.*#'  Makefile | sort | while read -r line; do \
	target=$${line%%:*}; \
	desc=$${line#*\#}; \
	printf "$(CYAN)%s: $(RESET)%s\n" "$$target" "$$desc"; \
	done

# This establishes the dependency relationships for the tests
-include tests/.dependencies

# Generates the dependency graph from '.depends' files in test directories
tests/.dependencies: $(dependency_files)
	@printf "$(CYAN)Generating test dependency graph...$(RESET)\n"
	@rm -f $@
	@for dir in $(test_directories); do \
		if [ -f "$$dir/.depends" ]; then \
			while read -r dep; do \
				[ -z "$$dep" ] || [ "$${dep#\#}" != "$$dep" ] && continue; \
				echo "$$dir/score: tests/$$dep/score" >> $@; \
			done < "$$dir/.depends"; \
		fi; \
	done

tests/%/score: $(code)
	$(start-test)
	$(check-deps) && $(run-test)

prechecks: # Runs all the autograder's dependency and integrity checks.
	$(start-section)
	@bash ./.admin_files/dependency_checks.sh $(language)
	@bash ./.admin_files/check_hashes.sh

build: $(code) # Builds your main code only (does not build not any unit tests).
	$(start-section)
	@cd src && $(MAKE) --no-print-directory

run: build # Builds and runs main code. If args in: `make run myargs="arg1 argN"`. If std/keyboard in: `make run <std.in`.
	$(start-section)
	@./target/main.out $(myargs)

test: prechecks $(test_targets) # Runs test code, generating score logfiles. To run past failing tests, use: `make test --keep-going`.
	@# Only rebuilds the dependencies (all of the 'score' files)

summary: # Summarizes which tests you are passing and failing. Assumes you first run `make test`.
	$(start-section)
	@echo -e 'For any failing tests, cd into the test directory, read the test files, and type `make` or `make debug`:'
	@for dir in tests/*; \
	do (cd "$$dir"; echo -en "$$dir -- test score was: "; \
	[ -f score ] \
	&& printf "$(GREEN)%s$(RESET)\n" "$$(cat score)" \
	|| printf "$(RED)failed$(RESET)\n"); done

grade: prechecks # Only computes your grade. Assumes you first run `make test`.
	$(start-section)
ifdef existing_passes
	@cat $(existing_passes) >scores
	@python3 -c "print(round(($$(paste --serial --delimiter=+ scores)) / $$(ls tests/ | wc -w)))" >grade
	@rm scores
	@echo -e "This is your calculated score:"
	@printf "$(BOLD)%s$(RESET)\n" "$$(cat grade)"
	@[[ "$$IS_PIPELINE" ]] || (printf "$(YELLOW)Your ACTUAL grade may differ from what you see above!$(RESET)\n" && \
	printf "Here is how to find your official grade:\n$(CYAN)https://cs-mst-docs.git-pages.mst.edu/workflow-docs/student/git/#checking-your-official-grade$(RESET)\n")
	@gradevar=$$(cat grade) && \
	([[ "$$IS_PIPELINE" ]] || rm grade) && \
	(( 70 < $$gradevar ))
else
	@echo "You have no passes yet. Run: make test"
	@[[ "$$IS_PIPELINE" ]] && (echo 0 >grade && exit 1)
endif

clean: # Cleans up all the generated logfiles and outfiles.
	$(start-section)
	@rm -f target/.rustc_info.json
	@rm -f $(test_targets)
	@rm -f $(feedback_files)
	@rm -f $(out_files)
	@rm -rf .mypy_cache __pycache__ *.out *.o *.hi .gdb_history
	@rm -rf build/*
	@rm -rf target/*
	@rm -rf .admin_files/.mypy_cache .admin_files/__pycache__ .admin_files/*.hi .admin_files/*.o
	@rm -rf */.mypy_cache */__pycache__ */*.out */*.o */*.hi
	@rm -rf */*/.mypy_cache */*/__pycache__ */*/*.out */*/*.o */*/*.hi */*/.gdb_history */*/*.log
