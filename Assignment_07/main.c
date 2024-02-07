#include "hash_table.h"
#include "file.h"

int main(int argv, char* argc[])
{
    (void)argv;

    // Create a hash table
    struct HashTable hashtable;

    // Initialize the table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable.table[i] = NULL;
    }

    // Reading in the desired input file
    char path[50] = "tests/inputs/";
    strcat(path, argc[1]);
    struct InputData input = LoadInputData(path);

    // Insert some key-value pairs
    for (int i = 0; i < input.count; ++i)
    {
        char* token1 = strtok(input.data[i], ":");
        char* token2 = strtok(NULL, "");
        Insert(&hashtable, token1, atoi(token2));
    }

    // Reading in the instruction set
    strcpy(path, "tests/instructions/");
    strcat(path, argc[1]);
    struct InputData instructions = LoadInputData(path);

    int instructionIndex = 0;
    while (instructionIndex < instructions.count)
    {
        const char* currentInstruction = instructions.data[instructionIndex];
        if (strcmp(currentInstruction, "Print") == 0)
        {
            // Printing the table
            printf("\n");
            Print(&hashtable);
            printf("\n");
        }
        else if (strcmp(currentInstruction, "Get") == 0)
        {
            currentInstruction = instructions.data[++instructionIndex];
            printf("Get data at key %s: %d\n", currentInstruction, Get(&hashtable, currentInstruction));
        }
        ++instructionIndex;
    }
 
    Delete(&hashtable);

    // Releasing the allocated memory
    FreeInputData(input);
    FreeInputData(instructions);

    return 0;
}