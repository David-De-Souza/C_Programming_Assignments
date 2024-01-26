#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 10
#define MAX_NAME_LENGTH 50

/*!
    @fn AddProductName(char products[][MAX_NAME_LENGTH], int *numProducts, const char* addName)

    @brief This function adds a product to the list of products

    @param products     The list of products
    @param numProducts  A pointer to the product count variable
    @param addName      The string name of the new product
*/
void AddProductName(char products[][MAX_NAME_LENGTH], int *numProducts, const char* addName);

/*!
    @fn DisplayProductNames(char products[][MAX_NAME_LENGTH], int numProducts)

    @brief This function sorts the products (in lexographical order) and prints them

    @param products     The list of products
    @param numProducts  The number of products in the list
*/
void DisplayProductNames(char products[][MAX_NAME_LENGTH], int numProducts);

/*!
    @fn SearchProductName(char products[][MAX_NAME_LENGTH], int numProducts, const char *searchName)

    @brief This function searches the list for the product

    @param products     The list of products
    @param numProducts  The number of products in the list
    @param searchName   The string name of the product to search for
*/
void SearchProductName(char products[][MAX_NAME_LENGTH], int numProducts, const char *searchName);

/*!
    @fn RemoveProductName(char products[][MAX_NAME_LENGTH], int *numProducts, const char *removeName)

    @brief This function removes a product by name from the list of products

    @param products     The list of products
    @param numProducts  A pointer to the product count variable
    @param removeName   The string name of the product to remove
*/
void RemoveProductName(char products[][MAX_NAME_LENGTH], int *numProducts, const char *removeName);