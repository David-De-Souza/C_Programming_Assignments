#include "file.h"
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR_COUNT 20
#define MAX_INSTRUCTIONS 30

FileData LoadInputData(char* filePath)
{
    FILE* pFile;
    pFile = fopen(filePath, "r");

    char** input_data = (char**)malloc(MAX_INSTRUCTIONS * sizeof(char*));
    for (int i = 0; i < MAX_INSTRUCTIONS; ++i)
    {
        input_data[i] = (char*)malloc(MAX_CHAR_COUNT * sizeof(char));
    }

    int index = 0;
    while(fscanf(pFile, "%s", input_data[index]) == 1)
    {
        ++index;
    }
    fclose(pFile);

    FileData data;
    data.count = index;
    data.data = input_data;

    return data;
}

void FreeInputData(FileData data)
{
    for (int i = 0; i < data.count; ++i)
    {
        free(data.data[i]);
    }
    free(data.data);
}