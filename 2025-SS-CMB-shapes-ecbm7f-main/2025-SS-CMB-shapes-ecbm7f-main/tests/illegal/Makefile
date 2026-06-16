differ = delta --side-by-side --navigate --max-line-length 0 --wrap-max-lines unlimited

pass: ../../src/*
	cd ../../src/ && $(MAKE)
	./../../target/main.out argfile.in >argfile.out
	$(differ) argfile.goal argfile.out && echo 100 >pass \
	|| ([[ "$$IS_PIPELINE" ]] && exit 1 \
	|| (echo "Press enter to debug:" && read && $(MAKE) debug && exit 1))

.PHONY: debug
debug:
	gdb --quiet --command=.gdb_commands --args ../../target/main.out argfile.in argfile.out

