@echo off
cls

@echo Compiling Executable
gcc -Wall -Wextra -Wconversion -Werror -pedantic -o main.exe main.c hash_table.c file.c

@echo test 1
main.exe 1.txt > out.txt
diff out.txt tests/outputs/1.txt --strip-trailing-cr

@echo test 2
main.exe 2.txt > out.txt
diff out.txt tests/outputs/2.txt --strip-trailing-cr

@echo test 3
main.exe 3.txt > out.txt
diff out.txt tests/outputs/3.txt --strip-trailing-cr

@echo test 4
main.exe 4.txt > out.txt
diff out.txt tests/outputs/4.txt --strip-trailing-cr

@echo test 5
main.exe 5.txt > out.txt
diff out.txt tests/outputs/5.txt --strip-trailing-cr

@echo test 6
main.exe 6.txt > out.txt
diff out.txt tests/outputs/6.txt --strip-trailing-cr