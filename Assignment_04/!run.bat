@echo off
cls

gcc -Wall -Wextra -Wconversion -Werror -pedantic -o main.exe main.c Binary.c

main.exe 00000001 + 00000001 > output/out.txt
diff output/out.txt sample_output/add_01.txt --strip-trailing-cr

main.exe 00001101 + 00001011 > output/out.txt
diff output/out.txt sample_output/add_02.txt --strip-trailing-cr

main.exe 01010101 + 00100001 > output/out.txt
diff output/out.txt sample_output/add_03.txt --strip-trailing-cr

main.exe 0000000A + 00000001 > output/out.txt
diff output/out.txt sample_output/add_04.txt --strip-trailing-cr

main.exe 00000001 + 0000000B > output/out.txt
diff output/out.txt sample_output/add_05.txt --strip-trailing-cr

main.exe 00000011 - 00000001 > output/out.txt
diff output/out.txt sample_output/sub_01.txt --strip-trailing-cr

main.exe 00011101 - 00101011 > output/out.txt
diff output/out.txt sample_output/sub_02.txt --strip-trailing-cr

main.exe 01101101 - 00101011 > output/out.txt
diff output/out.txt sample_output/sub_03.txt --strip-trailing-cr

main.exe 0000000A - 00000001 > output/out.txt
diff output/out.txt sample_output/sub_04.txt --strip-trailing-cr

main.exe 00000001 - 0000000B > output/out.txt
diff output/out.txt sample_output/sub_05.txt --strip-trailing-cr