#include "products.h"
#include "file.h"

char** AllocateInstructionsMemory()
{
    char** memory = (char**)malloc(sizeof(char*) * MAX_INSTRUCTIONS);
    for (int i = 0; i < MAX_INSTRUCTIONS; ++i)
    {
        memory[i] = (char*)malloc(sizeof(char) * MAX_CHAR_COUNT);
    }
    return memory;
}

void FreeInstructionsMemory(char** memory)
{
    for (int i = 0; i < MAX_INSTRUCTIONS; ++i)
    {
        free(memory[i]);
    }
    free(memory);
}

int main(int argv, char* argc[])
{
    (void)argv;

    // allocating some heap memory for the instructions set
    char** instructions = AllocateInstructionsMemory();

    // read in the instructions from file
    int count = ReadInstructionsFile(argc[1], instructions);

    int numProducts = 0;
    char products[MAX_PRODUCTS][MAX_NAME_LENGTH];

    // loop through all the instructions one by one, and execute the corresponding functions
    for (int i = 0; i < count; ++i)
    {
        char* current = instructions[i];

        if (strcmp(current, "Add-Product") == 0)
        {
            AddProductName(products, &numProducts, instructions[++i]);
        }
        else if (strcmp(current, "Display-Products") == 0)
        {
            DisplayProductNames(products, numProducts);
        }
        else if (strcmp(current, "Search-Product") == 0)
        {
            SearchProductName(products, numProducts, instructions[++i]);
        }
        else if (strcmp(current, "Remove-Product") == 0)
        {
            RemoveProductName(products, &numProducts, instructions[++i]);
        }
    }

    // freeing up the memory allocated at the start
    FreeInstructionsMemory(instructions);
    return 0;
}