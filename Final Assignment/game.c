#include <stdio.h>

#include "game.h"

Game CreateGame(int _w, int _h)
{
    Game newGame;
    newGame.buffer1 = CreateMap(_w, _h);
    newGame.buffer2 = CreateMap(_w, _h);
    return newGame;
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
    DeleteMap(&(game->buffer1));
    DeleteMap(&(game->buffer2));
}

int NeighbourCount(Map* map, int row, int col)
{
    int count = 0;

    // Iterate through neighboring rows
    for (int j = -1; j <= 1; j++)
    {
        // Iterate through neighboring columns
        for (int i = -1; i <= 1; i++)
        {
            // Skip the center cell (current cell)
            if (i == 0 && j == 0)
                continue;

            // Calculate the new row and column for the neighbor
            int newRow = row + j;
            int newCol = col + i;

            // Check if the neighbor is within the grid bounds
            if (newRow >= 0 && newRow < map->width && newCol >= 0 && newCol < map->height)
            {
                // Increment count if the neighbor is alive (value is 1)
                count += GetValueAtPosition(map, newRow, newCol);
            }
        }
    }
    return count;
}

void Update(Game* game)
{
    int _h = game->current->height;
    int _w = game->current->width;

    ClearMap(game->previous);

    for (int j = 0; j < _h; ++j)
    {
        for (int i = 0; i < _w; ++i)
        {
            int neighbours = NeighbourCount(game->current, i, j);
            //printf("%d, ", neighbours);

            if (GetValueAtPosition(game->current, i, j) == 1)
            {
                //printf("%d, ", neighbours);
                if (neighbours < 2) // underpopulation
                {
                    SetValueAtPosition(game->previous, i, j, 0);
                }
                else if (neighbours == 2 || neighbours == 3) // lives on
                {
                    SetValueAtPosition(game->previous, i, j, 1);
                }
                else if (neighbours > 3) // overpopulation
                {
                    SetValueAtPosition(game->previous, i, j, 0);
                }
            }
            else
            {
                if (neighbours == 3) // reproduction
                {
                    //printf("%d, %d\n", i, j);
                    SetValueAtPosition(game->previous, i, j, 1);
                }
            }
        }
        //printf("\n");
    }
}

void SwapMapBuffers(Game* game)
{
    Map* temp = game->current;
    game->current = game->previous;
    game->previous = temp;
}