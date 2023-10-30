#include <stdio.h>
#include <stdlib.h>
#include "solution.h"

int main(int argc, char *argv[])
{
    (void)argc;
    int input = atoi(argv[1]);

    printf("Fibonnaci elements = %d\n", input);
    for (int i = 0; i <= input; ++i)
    {
        printf(" %d", Fibonnaci(i));
    }
    printf("\n");

    return 0;
}