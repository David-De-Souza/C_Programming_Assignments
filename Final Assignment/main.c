#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define STEP_DELAY 50 // ms

int main(int argc, char* argv[])
{
    (void)argc;
    int cycles = atoi(argv[1]);

    char file[50] = "tests/input/";
    strcat(file, argv[2]);

    int width = atoi(argv[3]);
    int height = atoi(argv[4]);

    Game game = CreateGame(width, height);
    game.current = &game.buffer1;
    game.previous = &game.buffer2;

    LoadGame(&game, file);

    for (int i = 0; i < cycles; ++i)
    {
        system("clear");
        Update(&game);
        SwapMapBuffers(&game);
        DisplayMap(game.current);
        Sleep(STEP_DELAY);
    }

    DeleteGame(&game);

    return 0;
}