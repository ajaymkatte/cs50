/**
 * Implements a dictionary's functionality using hash table.
 */

#include <stdbool.h>

#include <string.h>
#include <strings.h>
#include "dictionary.h"

// declare a global hash table
struct node *ht[24];

// hashtable
int hashit(char word)
{
    int ju;
    if(word >= 65 && word <= 91)
        ju = word - 65;
    else
        ju = word - 97;
    return ju;
}

// destroy(free) the linked list
void realdestory(struct node *ptr)
{
    if(ptr != NULL)
        realdestory(ptr -> next);
    free(ptr);
}

// iterate through linked lists
bool destroy(void)
{
    for(int i = 0; i < 24; i++)
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

    struct node *ptr = ht[hashit(word[0])];

    // iterate through the linked list
    while(ptr != NULL)
    {
        if(strcasecmp(ptr -> spell, word) == 0)
            return true;

        ptr = ptr -> next;
    }

    // if all else fails, return false
    return false;

}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // initialize all the linked lists first pointer to NULL
    for(int i = 0; i < 24; i++)
    {
        ht[i] = NULL;
    }

    // open the dictionary
    FILE *filename = fopen(dictionary, "r");
    if(filename == NULL)
        return false;

    char correct[LENGTH + 1];
    struct node *array;

    while (fscanf(filename, "%s", correct) != EOF)
    {
        // find the hashtable
        int ht_number = hashit(correct[0]);

        // sanity check
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

    // close the file
    fclose(filename);

    // if everything goes well
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    int n = 0;

    for(int i = 0; i < 24; i++)
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
    // calls destroy function
    if(destroy())
        return true;
    else
        return false;
}
