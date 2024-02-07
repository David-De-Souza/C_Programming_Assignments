#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Structure for a node in the linked list
typedef struct _Node
{
    char key[50];
    int value;
    struct _Node* next;
} Node;

// Structure for the hash table
typedef struct _HashTable
{
    Node* table[TABLE_SIZE];
} HashTable;

// Hash function to calculate the index for a given key
int HashFunction(const char *key);

// Function to insert a key-value pair into the hash table
void Insert(HashTable *hashtable, const char *key, int value);

// Function to retrieve the value associated with a key from the hash table
int Get(HashTable *hashtable, const char *key);

// Function to print the hash table
void Print(HashTable* hashtable);

// Function to free the memory allocated by the Hashtable
void Delete(HashTable* hashtable);