#pragma once

#include <stdlib.h>

#define DEFAULT_CAPACITY 10

/*!
    @fn CreateVector(size_t* size, size_t* capacity)

    @brief This function handles the creation of dynamically allocated vectors

    @param size         The initial current size of the created vector
    @param capacity     The current max capacity of the created vector

    @return             A pointer to the heap allocated memory for the created vector
*/
int* CreateVector(size_t* size, size_t* capacity);

/*!
    @fn PushBack(int** vector, size_t* size, size_t* capacity, int value)

    @brief This function creates a new element and pushes it to the back of the specified vector
        This function resizes the array when the max capacity has been reached

    @param vector       A pointer to the memory address of the vector in memory
    @param size         The current size of the created vector
    @param capacity     The current max capacity of the created vector
    @param value        The value to assign the new element
*/
void PushBack(int** vector, size_t* size, size_t* capacity, int value);

/*!
    @fn GetElement(const int* vector, size_t size, size_t index)

    @brief This function accesses the vector to retrieve the value at a specified index

    @param vector       A pointer to the vector in memory
    @param size         The current size of the created vector
    @param index        The index to retrieve the value from

    @return             The value found at the index of the vector
*/
int GetElement(const int* vector, size_t size, size_t index);

/*!
    @fn DeleteVector(int* vector)

    @brief This function frees up the heap allocation for the vector

    @param vector       A pointer to the vector in memory
*/
void DeleteVector(int* vector);

/*!
    @fn PrintVector(const int* vector, size_t size)

    @brief A helper function to iterate over the elements of the vector and print them

    @param vector       A pointer to the vector in memory
    @param size         The current size of the created vector
*/
void PrintVector(const int* vector, size_t size);