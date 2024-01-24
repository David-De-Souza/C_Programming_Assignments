#include "products.h"

// Function to add a product name
void AddProductName(char products[][MAX_NAME_LENGTH], int *numProducts, const char* addName)
{
    if (*numProducts < MAX_PRODUCTS)
    {
        strcpy(products[*numProducts], addName);
        (*numProducts)++;
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
    for (int i = 0; i < numProducts; i++)
    {
        strcpy(sortedNames[i], products[i]);
    }

    // Bubble Sort
    for (int i = 0; i < numProducts - 1; i++)
    {
        for (int j = 0; j < numProducts - i - 1; j++)
        {
            if (strcmp(sortedNames[j], sortedNames[j + 1]) > 0)
            {
                // Swap function
                char temp[MAX_NAME_LENGTH];
                strcpy(temp, sortedNames[j]);
                strcpy(sortedNames[j], sortedNames[j + 1]);
                strcpy(sortedNames[j + 1], temp);
            }
        }
    }

    // Display sorted product names
    printf("\nDisplaying Product Names:\n");
    for (int i = 0; i < numProducts; i++)
    {
        printf("%s\n", sortedNames[i]);
    }
}

// Function to search for a product name
void SearchProductName(char products[][MAX_NAME_LENGTH], int numProducts, const char *searchName)
{
    int found = 0;
    for (int i = 0; i < numProducts; i++)
    {
        if (strcmp(products[i], searchName) == 0)
        {
            printf("\nProduct found: %s\n", products[i]);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n%s not found.\n", searchName);
    }
}

// Function to remove a product name
void RemoveProductName(char products[][MAX_NAME_LENGTH], int *numProducts, const char *removeName)
{
    int found = 0;
    for (int i = 0; i < *numProducts; i++)
    {
        if (strcmp(products[i], removeName) == 0)
        {
            // Shift elements to fill the gap
            for (int j = i; j < *numProducts - 1; j++)
            {
                strcpy(products[j], products[j + 1]);
            }
            (*numProducts)--;
            printf("\n%s removed successfully.\n", removeName);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nProduct name not found. No removal performed.\n");
    }
}