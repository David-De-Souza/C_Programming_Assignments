#include "credentials.h"
#include "file.h"
#include <stdio.h>
#include <string.h>

int main(int argv, char* argc[])
{
    (void)argv;

    // Reading in the instruction set
    char path[50] = "tests/";
    strcat(path, argc[1]);
    FileData instructions = LoadInputData(path);

    // Clearing credentials file before test
    ClearCredentials();

    int instructionIndex = 0;
    while (instructionIndex < instructions.count)
    {
        const char* currentInstruction = instructions.data[instructionIndex];
        if (strcmp(currentInstruction, "Store") == 0)
        {
            Credentials newCredentials;
            strcpy(newCredentials.username, instructions.data[++instructionIndex]);
            strcpy(newCredentials.password, instructions.data[++instructionIndex]);
            StoreCredentials(&newCredentials);
        }
        else if (strcmp(currentInstruction, "Modify") == 0)
        {
            ModifyPassword(instructions.data[instructionIndex+1], instructions.data[instructionIndex+2]);
            instructionIndex += 2;
        }
        else if (strcmp(currentInstruction, "Display") == 0)
        {
            DisplayCredentials();
        }
        ++instructionIndex;
    }

    FreeInputData(instructions);

    return 0;
}
