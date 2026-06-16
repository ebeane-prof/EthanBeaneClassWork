language := "cpp"
code := $(wildcard src/*)
test_directories := $(wildcard tests/*)
test_targets := $(addsuffix /pass,$(test_directories))
existing_passes := $(wildcard tests/*/pass)
out_files := $(wildcard tests/*/*.out)
out_files += $(wildcard tests/*/out.*)

define start-test =
	@export TERM=screen-256color && tput smso && tput setaf 4 && \
	echo -e "\n============= make test: $(patsubst %/pass,%/,$@) =============" && \
	tput rmso && tput sgr0
endef

define continue =
	[[ "$$IS_PIPELINE" ]] || (echo -en '\nPress `Enter` to continue:' && read)
endef

define start-section =
	@export TERM=screen-256color && tput smso && tput setaf 4 && \
	echo -e "\n============= make $@ =============" && \
	tput rmso && tput sgr0
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
	@echo -e "This autograder is designed to guide you through the programming process."
	@echo -e "Do NOT assume that the autograder should be the primary way you run your code!"
	@echo -e "You should run code manually, by executing it directly at the terminal,"
	@echo -e "so that you understand how it is executed, and how input and output are handled."
	@echo -e "When debugging, you should read the tests themselves,"
	@echo -e "and run the tests (or their commands) manually!"
	@echo -e "Remember these tests easily run in the class container or VM,"
	@echo -e 'but `git` commands should generally be run in your host terminal.\n'
	@grep -E '^[a-zA-Z0-9 -]+:.*#'  Makefile | sort | while read -r l; \
	do tput setaf 4 && echo -en "$$(echo $$l | cut -f 1 -d':'): " && \
	tput sgr0 && echo "$$(echo $$l | cut -f 2- -d'#')"; done
	@$(continue)

tests/%/pass: $(code)
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)

tests/02_memory_create_delete/pass: $(code) tests/01_unit_create_grid/pass
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)

tests/03_unit_basic_shift_row/pass: $(code) tests/01_unit_create_grid/pass
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)
	
tests/04_unit_multiple_shift_row/pass: $(code) tests/01_unit_create_grid/pass
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)

tests/05_unit_reverse_shift_row/pass: $(code) tests/01_unit_create_grid/pass
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)

tests/06_unit_basic_shift_col/pass: $(code) tests/01_unit_create_grid/pass
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)
	
tests/07_unit_multiple_shift_col/pass: $(code) tests/01_unit_create_grid/pass
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)
	
tests/08_unit_reverse_shift_col/pass: $(code) tests/01_unit_create_grid/pass
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)

tests/09_memory_shift_row_col/pass: $(code) tests/03_unit_basic_shift_row/pass tests/06_unit_basic_shift_col/pass
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)

tests/10_stdio_frog/pass: $(code) $(code) $(patsubst %, %/pass, $(wildcard tests/*unit*))
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)

tests/11_stdio_multiple_puzzles/pass: $(code) $(patsubst %, %/pass, $(wildcard tests/*unit*))
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)

tests/12_stdio_big_puzzle/pass: $(code) $(patsubst %, %/pass, $(wildcard tests/*unit*))
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)

tests/13_memory_main/pass: $(code) $(patsubst %, %/pass, $(wildcard tests/*stdio*)) 
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory
	$(continue)

prechecks: # Runs all the autograder's dependency and integrity checks.
	$(start-section)
	@bash ./.admin_files/dependency_checks.sh $(language)
	@bash ./.admin_files/check_hashes.sh

build: $(code) # Builds your main code only (does not build not any unit tests).
	$(start-section)
	cd src && $(MAKE) --no-print-directory

run: build # Builds and runs main code. If args in: `make run myargs="arg1 argN"`. If std/keyboard in: `make run <std.in`.
	$(start-section)
	./target/main.out $(myargs)

test: prechecks $(test_targets) # Runs test code, generating score logfiles. To run past failing tests, use: `make test --keep-going`.
	@#$(MAKE) grade

summary: # Summarizes which tests you are passing and failing. Assumes you first run `make test`.
	$(start-section)
	@echo -e 'For any failing tests, cd into the test directory, read the test files, and type `make` or `make debug`:'
	@export TERM=screen-256color && \
	for dir in tests/*; \
	do (cd "$$dir"; echo -en "$$dir -- test score was: "; \
	[ -f pass ] \
	&& (tput setaf 2 && cat pass && tput sgr0) \
	|| (tput setaf 1 && echo "failed" && tput sgr0)); done

grade: prechecks # Only computes your grade. Assumes you first run `make test`.
	$(start-section)
ifdef existing_passes
	@echo -e 'To see details of which tests you are passing, see `make summary`.\n'
	@cat $(existing_passes) >scores
	@python3 -c "print(round(($$(paste --serial --delimiter=+ scores)) / $$(ls tests/ | wc -w)))" >grade
	@rm scores
	@echo -e "This is your calculated score:"
	@export TERM=screen-256color && tput smso && cat grade && tput rmso
	@echo "Your ACTUAL grade may differ from what you see above, unless you:"
	@echo '0. Cleaned up before testing: `make clean; make test --keep-going; make summary; make grade`'
	@echo "1. Make sure all of your local changes are pushed to <git-classes.mst.edu>."
	@echo "2. In the web-browser, navigate to the correct assignment repository."
	@echo "3. On the left navigation menu, click 'Build' > 'Jobs'."
	@echo "4. On that jobs page, click the 'Status' icon for the LATEST job."
	@echo "5. View this output itself in that web interface."
	@echo "That is where you can see your OFFICIAL grade!"
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
	@rm -f $(out_files)
	@rm -rf .mypy_cache __pycache__ *.out *.o *.hi .gdb_history
	@rm -rf build/*
	@rm -rf target/*
	@rm -rf .admin_files/.mypy_cache .admin_files/__pycache__ .admin_files/*.hi .admin_files/*.o
	@rm -rf */.mypy_cache */__pycache__ */*.out */*.o */*.hi
	@rm -rf */*/.mypy_cache */*/__pycache__ */*/*.out */*/*.o */*/*.hi */*/.gdb_history */*/*.log
