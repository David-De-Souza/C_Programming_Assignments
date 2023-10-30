@echo off
cls

gcc -Wall -Wextra -Wconversion -Werror -pedantic -o main.exe main.c
main.exe 0 > output/out.txt
diff output/out.txt sample_output/fib_0.txt --strip-trailing-cr

main.exe 1 > output/out.txt
diff output/out.txt sample_output/fib_1.txt --strip-trailing-cr

main.exe 2 > output/out.txt
diff output/out.txt sample_output/fib_2.txt --strip-trailing-cr

main.exe 3 > output/out.txt
diff output/out.txt sample_output/fib_3.txt --strip-trailing-cr

main.exe 4 > output/out.txt
diff output/out.txt sample_output/fib_4.txt --strip-trailing-cr

main.exe 5 > output/out.txt
diff output/out.txt sample_output/fib_5.txt --strip-trailing-cr

main.exe 6 > output/out.txt
diff output/out.txt sample_output/fib_6.txt --strip-trailing-cr

main.exe 7 > output/out.txt
diff output/out.txt sample_output/fib_7.txt --strip-trailing-cr

main.exe 8 > output/out.txt
diff output/out.txt sample_output/fib_8.txt --strip-trailing-cr

main.exe 9 > output/out.txt
diff output/out.txt sample_output/fib_9.txt --strip-trailing-cr

main.exe 10 > output/out.txt
diff output/out.txt sample_output/fib_10.txt --strip-trailing-cr
