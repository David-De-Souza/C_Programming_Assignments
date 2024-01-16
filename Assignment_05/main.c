#include "vector.h"
#include <stdio.h>

int main()
{
    // Test Case 1: Adding elements to the vector
    printf("Test Case 1: Adding elements to the vector\n");
    size_t size1, capacity1;
    int* vector1 = CreateVector(&size1, &capacity1);

    for (int i = 0; i < 10; i++)
    {
        PushBack(&vector1, &size1, &capacity1, i * 2);
    }

    printf("vector 1: ");
    PrintVector(vector1, size1);
    DeleteVector(vector1);
    printf("\n");

    // Test Case 2: Accessing elements in the vector
    printf("Test Case 2: Accessing elements in the vector\n");
    size_t size2, capacity2;
    int* vector2 = CreateVector(&size2, &capacity2);

    for (int i = 0; i < 5; i++)
    {
        PushBack(&vector2, &size2, &capacity2, i * 3);
    }

    printf("vector 2: ");
    PrintVector(vector2, size2);

    printf("Element at index 2: %d\n", GetElement(vector2, size2, 2));

    DeleteVector(vector2);
    printf("\n");

    // Test Case 3: Resizing of the vector
    printf("Test Case 3: Resizing of the vector\n");
    size_t size3, capacity3;
    int* vector3 = CreateVector(&size3, &capacity3);

    for (int i = 0; i < 15; i++)
    {
        PushBack(&vector3, &size3, &capacity3, i * 5);
    }

    printf("vector 3: ");
    PrintVector(vector3, size3);
    DeleteVector(vector3);
    printf("\n");

    return 0;
}