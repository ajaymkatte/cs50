/**
 * Implements a dictionary's functionality using hash table.
 */

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

#define HASHSIZE 10000

// Declare a global hash table
struct node *ht[HASHSIZE];

// A huge thanks to /u/delipity for the below algorithm
// Find the hashtable
int hashit(char* wordhash)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(wordhash); i<n; i++)
        hash = (hash << 2) ^ wordhash[i];
    return hash % HASHSIZE;
}

// Destroy(free) the linked list
void realdestory(struct node *ptr)
{
    if(ptr != NULL)
        realdestory(ptr -> next);
    free(ptr);
}

// Iterate through linked lists
bool destroy(void)
{
    for(int i = 0; i < HASHSIZE; i++)
    {
        struct node* ptr = ht[i];
        realdestory(ptr);
    }
    return true;
}


/**
 * Returns true if word is in dictionary.
 */
bool check(const char *word)
{
    int wordlength = strlen(word);
    char lcword[wordlength + 1];

    for(int i = 0; i < wordlength; i++)    // (int i = 0, length = strlen(word); i < length; i++)
    {
        lcword[i] = tolower(word[i]);
    }

    lcword[wordlength] = '\0';

    struct node *ptr = ht[hashit(lcword)];

    // Iterate through the linked list
    while(ptr != NULL)
    {
        if(strcasecmp(ptr -> spell, word) == 0)
            return true;

        ptr = ptr -> next;
    }

    // If all else fails, return false
    return false;

}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // Initialize all the linked lists first pointer to NULL
    for(int i = 0; i < HASHSIZE; i++)
    {
        ht[i] = NULL;
    }

    // Open the dictionary
    FILE *filename = fopen(dictionary, "r");
    if(filename == NULL)
        return false;

    char correct[LENGTH + 1];
    struct node *array;

    while (fscanf(filename, "%s", correct) != EOF)
    {
        // Find the hashtable
        int ht_number = hashit(correct);

        // Sanity check
        array = malloc(sizeof(words));
        if(array == NULL)
        {
            unload();
            fclose(filename);
            return false;
        }

        strcpy(array -> spell, correct);
        array -> next = ht[ht_number];
        ht[ht_number] = array;
    }

    // Close the file
    fclose(filename);

    // If everything goes well
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    int n = 0;

    for(int i = 0; i < HASHSIZE; i++)
    {
        struct node *ptr = ht[i];

        while(ptr != NULL)
        {
            n++;
            ptr = ptr -> next;
        }
    }
    return n;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // Calls destroy function
    if(destroy())
        return true;
    else
        return false;
}
