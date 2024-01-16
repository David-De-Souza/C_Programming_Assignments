#include "vector.h"
#include <stdio.h>

int* CreateVector(size_t* size, size_t* capacity)
{
    int* vector = (int*)malloc(DEFAULT_CAPACITY * sizeof(int));

    if (vector == NULL) {
        fprintf(stderr, "Memory allocation error during initialization.\n");
        exit(EXIT_FAILURE);
    }

    *size = 0;
    *capacity = DEFAULT_CAPACITY;

    return vector;
}

void PushBack(int** vector, size_t* size, size_t* capacity, int value)
{
    if (*size == *capacity) {
        // Resize the vector if it's full
        *capacity *= 2;
        *vector = (int*)realloc(*vector, *capacity * sizeof(int));

        if (*vector == NULL) {
            fprintf(stderr, "Memory allocation error during resizing.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Add the new element to the end of the vector
    (*vector)[*size] = value;
    (*size)++;
}

int GetElement(const int* vector, size_t size, size_t index)
{
    if (index < size) {
        return vector[index];
    } else {
        fprintf(stderr, "Index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
}

void PrintVector(const int* vector, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void DeleteVector(int* vector)
{
    free(vector);
}