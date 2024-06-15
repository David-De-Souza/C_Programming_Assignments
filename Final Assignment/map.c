#include <stdio.h>
#include <stdlib.h>

#include "map.h"

Map CreateMap(int w, int h)
{

}

int GetValueAtPosition(Map* map, int x, int y)
{

}

void SetValueAtPosition(Map* map, int x, int y, int value)
{

}

void DisplayMap(Map* map)
{
    // print top bar
    printf("\u2554");
    for (int i = 0; i < map->width; ++i)
        printf("\u2550\u2550");
    printf("\u2557\n");

    for (int j = 0; j < map->height; ++j)
    {
        // print side bar
        printf("\u2551");

        for (int i = 0; i < map->width; ++i)
        {
            if (GetValueAtPosition(map, i, j) == 1)
            {
                printf("\u2584 ");
            }
            else
            {
                printf("  ");
            }
        }

        // print side bar
        printf("\u2551\n");
    }

    // print bottom bar
    printf("\u255A");
    for (int i = 0; i < map->width; ++i)
        printf("\u2550\u2550");
    printf("\u255D\n");
}

void ClearMap(Map* map)
{
    for (int j = 0; j < map->height; ++j)
    {
        for (int i = 0; i < map->width; ++i)
        {
            SetValueAtPosition(map, i, j, 0);
        }
    }
}

void DeleteMap(Map* map)
{

}