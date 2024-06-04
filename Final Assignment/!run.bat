@echo off
cls 

gcc -Wall -Werror -Wconversion -Wextra -pedantic -o GameOfLife.exe main.c game.c map.c

@rem GameOfLife.exe 8 blinker.txt 5 5
@rem GameOfLife.exe 8 beacon.txt 6 6
@rem GameOfLife.exe 8 toad.txt 6 6
@rem GameOfLife.exe 100 glider.txt 30 30
@rem GameOfLife.exe 200 glider_gun.txt 40 30