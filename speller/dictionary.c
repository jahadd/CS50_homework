// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// Word count
unsigned int word_count = 0;

// Compares two strings ignoring case
bool compare_insensitive(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (tolower((unsigned char) *s1) != tolower((unsigned char) *s2))
        {
            return false;
        }
        s1++;
        s2++;
    }
    return *s1 == *s2;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // djb2-style hash function
    unsigned long hash = 5381;
    int c;
    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        strcpy(new_node->word, word);

        unsigned int index = hash(word);
        new_node->next = table[index];
        table[index] = new_node;

        word_count++;
    }

    fclose(file);
    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (compare_insensitive(cursor->word, word))
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (unsigned int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        table[i] = NULL;
    }
    return true;
}
