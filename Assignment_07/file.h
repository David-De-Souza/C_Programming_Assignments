#pragma once

#include <stdio.h>

struct InputData
{
    int count;
    char** data;
};

struct InputData LoadInputData(char* filePath);
void FreeInputData(struct InputData input);