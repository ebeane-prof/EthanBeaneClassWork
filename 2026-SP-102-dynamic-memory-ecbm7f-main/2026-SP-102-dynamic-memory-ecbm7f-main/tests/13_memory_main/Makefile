pass: ../../src/*.cpp
	cd ../../src && $(MAKE)
	@valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./../../target/main.out < std.in >std.out && echo 100 > pass \
	|| (echo "Memory test failed. Use 'make debug' for more information." && exit 1)

.PHONY: debug
debug:
	valgreen ./../../target/main.out < std.in
