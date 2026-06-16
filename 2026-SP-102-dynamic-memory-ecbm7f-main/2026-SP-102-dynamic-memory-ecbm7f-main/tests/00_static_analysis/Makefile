pass: ../../src/*.cpp ../../src/*.h
	cppcheck --enable=warning,style --suppressions-list=../../.admin_files/cppcheck_suppressions.txt --error-exitcode=1 --exitcode-suppressions=../../.admin_files/cppcheck_exitcode_suppressions.txt --language=c++ $^ && echo 100 >pass
