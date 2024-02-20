#include "credentials.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* filename = "Credentials.bin";

void ClearCredentials()
{
    FILE *file = fopen(filename, "w");
    fclose(file);
}

void StoreCredentials(Credentials *credentials)
{
    FILE *file = fopen(filename, "ab"); // Open file in binary append mode

    if (file == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write credentials to the file
    fwrite(credentials, sizeof(Credentials), 1, file);

    // Close the file
    fclose(file);
}


void DisplayCredentials()
{
    FILE *file = fopen(filename, "rb"); // Open file in binary read mode

    if (file == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Credentials credentials;

    // Read and display credentials until the end of the file
    while (fread(&credentials, sizeof(Credentials), 1, file) == 1)
    {
        printf("Username: %s\n", credentials.username);
        printf("Password: %s\n", credentials.password);
        printf("\n");
    }

    // Close the file
    fclose(file);
}


void ModifyPassword(const char *username, const char *newPassword)
{
    FILE *file = fopen(filename, "r+b"); // Open file in binary read-write mode

    if (file == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Credentials credentials;

    // Search for the username in the file
    while (fread(&credentials, sizeof(Credentials), 1, file) == 1)
    {
        if (strcmp(credentials.username, username) == 0) 
        {
            // Found the username, update the password
            strncpy(credentials.password, newPassword, sizeof(credentials.password));
            fseek(file, -(long)sizeof(Credentials), SEEK_CUR); // Move back to the beginning of the record
            fwrite(&credentials, sizeof(Credentials), 1, file);
            break;
        }
    }

    // Close the file
    fclose(file);
}