in_file = std.in
out_file = std.out
goal_file = std.goal

differ = delta --side-by-side --width $$(tput cols) --navigate --max-line-length 0 --wrap-max-lines unlimited $(out_file) $(goal_file)
pass: ../../src/*
	cd ../../src && $(MAKE)
	./../../target/main.out <std.in >std.out
	python3 ../../.admin_files/fuzzydiffer.py std.goal std.out >pass \
	|| $(differ)

.PHONY: debug
debug: ../../src/*
	cd ../../src && $(MAKE)
	gdb --quiet --command=.gdb_commands --args ./../../target/main.out
