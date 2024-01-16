@echo off
cls

@echo Compiling Executable
gcc -Wall -Wextra -Wconversion -Werror -pedantic -o main.exe main.c vector.c

@echo Running Executable
main.exe > output.txt

@echo Diffing Output
diff output.txt sample-output.txt --strip-trailing-cr