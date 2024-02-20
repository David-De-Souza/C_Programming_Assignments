@echo off
cls

@echo Compiling Executable
gcc -Wall -Wextra -Wconversion -Werror -pedantic -o main.exe main.c credentials.c file.c

@echo test 1
main.exe inputs/1.txt > output.txt
diff tests/outputs/1.txt output.txt --strip-trailing-cr

@echo test 2
main.exe inputs/2.txt > output.txt
diff tests/outputs/2.txt output.txt --strip-trailing-cr

@echo test 3
main.exe inputs/3.txt > output.txt
diff tests/outputs/3.txt output.txt --strip-trailing-cr

@echo test 4
main.exe inputs/4.txt > output.txt
diff tests/outputs/4.txt output.txt --strip-trailing-cr