/**
 * Implements a dictionary's functionality, no hash table used. I'll be implementing one in the coming days.
 */

#include <stdbool.h>

// included string library
#include <string.h>

#include "dictionary.h"

// declare a global hash table
struct node *ht[24];

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

    // temp storage
    int ju;
    if(word[0] >= 65 && word[0] <= 91)
        ju = word[0] - 65;
    else
        ju = word[0] - 97;

    // temp pointer
    struct node *ptr = ht[ju];

    // iterate through the linked list
    while(ptr != NULL)
    {
        int x = strcmp(ptr -> spell, word);

        // checks if strings are same
        if(x == 0)
            return true;

        // get the next string
        else if(x < 0)
            ptr = ptr -> next;

        // apostrophes usage
        else
        {

            int len = strlen(ptr -> spell), equals = 0;

            // iterate through the word
            for(int i = 0, n = 0, rlen = strlen(word); i < rlen; i++)
            {

                char junk = ptr -> spell[i - n];
                char junk1 = junk - 32;

                // checks characters
                if(junk == word[i] || junk1 == word[i])
                    equals += 1;

                // chekcs apostrophes usage
                else if(word[i] == 39)
                    ++n;

                // breaks out
                else
                    break;
            }

            // return true if the words are same
            if(equals == len)
                return true;

            // go to the next node
            ptr = ptr -> next;
        }
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

    // check if the file exists
    if(filename == NULL)
        return false;

    //  variable declaration with the size of the largest string in the dictionary
    char correct[LENGTH + 1];

    // create temp nodes
    struct node *array;

    while (fscanf(filename, "%s", correct) != EOF)
    {
        // find the alphabets position
        int ht_number = correct[0] - 97;

        // allocate memory and check if the fuction returns NULL
        array = malloc(sizeof(words));
        if(array == NULL)
            return false;

        // copy string
        strcpy(array -> spell, correct);

        // assaign pointer
        array -> next = ht[ht_number];

        // current address
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
    // temp variables
    int n = 0;

    // interate through the words
    for(int i = 0; i < 24; i++)
    {
        struct node *ptr = ht[i];

        // increment n by 1
        while(ptr != NULL)
        {
            n++;
            ptr = ptr -> next;
        }
    }

    // returns the total words
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
