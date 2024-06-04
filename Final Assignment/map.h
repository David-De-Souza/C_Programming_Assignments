#pragma once

typedef struct _Map
{
    char* data;
    int width;
    int height;
} Map;

Map CreateMap(int w, int h);

int GetValueAtPosition(Map* map, int x, int y);

void SetValueAtPosition(Map* map, int x, int y, int value);

void DisplayMap(Map* map);

void ClearMap(Map* map);

void DeleteMap(Map* map);