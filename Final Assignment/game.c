#include <stdio.h>

#include "game.h"

Game CreateGame(int _w, int _h)
{

}

void LoadGame(Game* game, const char* filepath)
{
    FILE* p_file;
    p_file = fopen(filepath, "r");
    char line[100];
    int y = 0;
    while (fscanf(p_file, "%s", line) == 1)
    {
        int x = 0;
        while (line[x] != '\0')
        {
            SetValueAtPosition(&game->buffer1, x, y, line[x] - 48);
            ++x;
        }
        ++y;
    }
    fclose(p_file);
}

void DeleteGame(Game* game)
{

}

int NeighbourCount(Map* map, int row, int col)
{
}

void Update(Game* game)
{
    
}

void SwapMapBuffers(Game* game)
{
    Map* temp = game->current;
    game->current = game->previous;
    game->previous = temp;
}