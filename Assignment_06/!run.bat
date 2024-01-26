@echo off
cls

@echo Compiling Executable
gcc -Wall -Wextra -Wconversion -Werror -pedantic -o main.exe main.c products.c file.c

@echo Test_1
main.exe tests/test_1.txt > output.txt
diff output.txt sample-output/1.txt --strip-trailing-cr

@echo Test_2
main.exe tests/test_2.txt > output.txt
diff output.txt sample-output/2.txt --strip-trailing-cr

@echo Test_3
main.exe tests/test_3.txt > output.txt
diff output.txt sample-output/3.txt --strip-trailing-cr

@echo Test_4
main.exe tests/test_4.txt > output.txt
diff output.txt sample-output/4.txt --strip-trailing-cr

@echo Test_5
main.exe tests/test_5.txt > output.txt
diff output.txt sample-output/5.txt --strip-trailing-cr

@echo Test_6
main.exe tests/test_6.txt > output.txt
diff output.txt sample-output/6.txt --strip-trailing-cr

@echo Test_7
main.exe tests/test_7.txt > output.txt
diff output.txt sample-output/7.txt --strip-trailing-cr

@echo Test_8
main.exe tests/test_8.txt > output.txt
diff output.txt sample-output/8.txt --strip-trailing-cr