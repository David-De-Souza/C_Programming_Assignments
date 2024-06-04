#pragma once
#include "map.h"

typedef struct _Game
{
    Map buffer1;
    Map buffer2;
    Map* current;
    Map* previous;
} Game;

Game CreateGame(int _w, int _h);
void LoadGame(Game* game, const char* filepath);
void DeleteGame(Game* game);
int NeighbourCount(Map* map, int x, int y);
void Update(Game* game);
void SwapMapBuffers(Game* game);