#include "vector.h"
#include <stdio.h>

int* CreateVector(size_t* size, size_t* capacity)
{
    int* vector = ; // allocate memory

    // check if the memory was allocated
    if (vector == NULL)
    {
        fprintf(stderr, "Memory allocation error during initialization.\n");
        exit(EXIT_FAILURE);
    }

    // initialize size and capacity

    // return the allocated vector
    return vector;
}

void PushBack(int** vector, size_t* size, size_t* capacity, int value)
{
    // checks if the size has reached the capacity
    if (*size == *capacity)
    {
        // resize the vector if it is full
        *capacity *= 2;
        *vector = ; // resize vector

        // check if the memory was reallocated
        if (*vector == NULL)
        {
            fprintf(stderr, "Memory allocation error during resizing.\n");
            exit(EXIT_FAILURE);
        }
    }

    // add the new element to the end of the vector


    // increment the size

}

int GetElement(const int* vector, size_t size, size_t index)
{
    // check if the index is within the range of the vector
    if ()
    {
        return ; // return the element at index
    }
    else
    {
        // throw index out of bounds error
        fprintf(stderr, "Index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
}

void DeleteVector(int* vector)
{
    // free the allocated memory
}

void PrintVector(const int* vector, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}