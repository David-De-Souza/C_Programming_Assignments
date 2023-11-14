#include <stdio.h>
#include "Binary.h"

void PrintBinaries(char bin1[BIT_COUNT], char bin2[BIT_COUNT], char result[BIT_COUNT], char operator)
{
    printf("  ");
    for (int i = 0; i < BIT_COUNT; ++i)
    {
        printf("%c", bin1[i]);
    }
    printf("\n%c ", operator);

    for (int i = 0; i < BIT_COUNT; ++i)
    {
        printf("%c", bin2[i]);
    }
    printf("\n----------\n  ");

    for (int i = 0; i < BIT_COUNT; ++i)
    {
        printf("%c", result[i]);
    }
    printf("\n");
}