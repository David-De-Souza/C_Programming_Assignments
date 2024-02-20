#pragma once

#include <stdio.h>

typedef struct _FileData
{
    int count;
    char** data;
} FileData;

FileData LoadInputData(char* filePath);
void FreeInputData(FileData data);