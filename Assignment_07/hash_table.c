#include "hash_table.h"

// Hash function to calculate the index for a given key
int HashFunction(const char *key)
{
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash = (hash * 31 + key[i]) % TABLE_SIZE;
    }

    return hash;
}

// Function to insert a key-value pair into the hash table
void Insert(HashTable *hashtable, const char *key, int value)
{
    int index = HashFunction(key);

    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Copy the key and set the value
    strncpy(newNode->key, key, sizeof(newNode->key));
    newNode->value = value;
    newNode->next = NULL;

    // Insert the node into the linked list at the specified index
    if (hashtable->table[index] == NULL)
    {
        hashtable->table[index] = newNode;
    }
    else
    {
        newNode->next = hashtable->table[index];
        hashtable->table[index] = newNode;
    }
}

// Function to retrieve the value associated with a key from the hash table
int Get(HashTable *hashtable, const char *key)
{
    int index = HashFunction(key);

    // Search for the key in the linked list at the specified index
    Node *current = hashtable->table[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
        current = current->next;
    }

    // Key not found
    return -1;
}

void Print(HashTable* hashtable)
{
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        printf("[%d]", i);
        Node* current = hashtable->table[i];

        while (current)
        {
            printf("->%d", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

void Delete(HashTable* hashtable)
{
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        Node* current = hashtable->table[i];
        Node* previous = NULL;

        while (current)
        {
            previous = current;
            current = current->next;
            free(previous);
        }
    }
}