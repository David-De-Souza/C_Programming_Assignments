#pragma once

typedef struct _Credentials
{
    char username[50];
    char password[50];
} Credentials;

// Function to celar the credentials binary file
void ClearCredentials();

// Function to store credentials in the binary file
void StoreCredentials(Credentials *credentials);

// Function to display stored credentials from the binary file
void DisplayCredentials();

// Function to modify the password for a given username
void ModifyPassword(const char *username, const char *newPassword);