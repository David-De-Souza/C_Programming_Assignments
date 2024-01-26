#include "products.h"

// Function to add a product name
void AddProductName(char products[][MAX_NAME_LENGTH], int *numProducts, const char* addName)
{
    if (*numProducts < MAX_PRODUCTS)
    {
        // Add the product to the list



        printf("%s added successfully.\n", addName);
    }
    else
    {
        printf("Maximum number of products reached.\n");
    }
}

// Function to display all product names in lexicographical order
void DisplayProductNames(char products[][MAX_NAME_LENGTH], int numProducts)
{
    if (numProducts == 0)
    {
        printf("No product names available.\n");
        return;
    }

    // Copy product names to a temporary array
    char sortedNames[MAX_PRODUCTS][MAX_NAME_LENGTH];


    // Sort the products (in lexographical order)


    // Display sorted product names

}

// Function to search for a product name
void SearchProductName(char products[][MAX_NAME_LENGTH], int numProducts, const char *searchName)
{
    int found = 0;



    if (!found)
    {
        printf("\n%s not found.\n", searchName);
    }
}

// Function to remove a product name
void RemoveProductName(char products[][MAX_NAME_LENGTH], int *numProducts, const char *removeName)
{
    int found = 0;



    if (!found)
    {
        printf("\nProduct name not found. No removal performed.\n");
    }
}