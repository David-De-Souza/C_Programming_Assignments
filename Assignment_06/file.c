#include "file.h"
#include <string.h>

int ReadInstructionsFile(char* filePath, char** instructions)
{
    FILE* pFile;
    pFile = fopen(filePath, "r");

    int index = 0;
    while(fscanf(pFile, "%s", instructions[index]) == 1)
    {
        ++index;
    }
    fclose(pFile);
    return index;
}