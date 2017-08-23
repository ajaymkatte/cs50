/**
 * Implements a dictionary's functionality, no hash table used. I'll be implementing one in the coming days.
 */

#include <stdbool.h>

// included string library to use strlen and strcmp
#include <string.h>

#include "dictionary.h"

// to keep track of the first node
struct node *first = NULL;

// when everything's said and done, the following fuction will destroy(free) the linked list
bool destroy(struct node* ptr)
{
    if(ptr != NULL)
        destroy(ptr -> next);
    free(ptr);
    return true;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // temp storage for first pointer
    struct node *ptr = first;

    // iterate through the linked list
    while(ptr != NULL)
    {

        // checks if the current dictionary string and the passed string are equal
        if(strcmp(ptr -> spell, word) == 0)
            return true;

        // checks if the passed string has less characters than the current dictionary string
        else if(strcmp(ptr -> spell, word) < 0)
            return false;

        // checks for the apostrophes usage
        else
        {

            // temp variable to keep track of len of the dictionary string
            int len = strlen(ptr -> spell), equals = 0;

            // iterate through the word passed to the fuction
            for(int i = 0, n = 0, rlen = strlen(word); i < rlen; i++)
            {

                // temp variables to easen the human effort in understanding the program
                char junk = ptr -> spell[i - n];
                char junk1 = junk - 32;

                // checks if the given characters are equal and increments equal in order to compare later
                if(junk == word[i] || junk1 == word[i])
                    equals += 1;

                // chekcs if the letter has an apostrophes
                else if(word[i] == 39)
                    ++n;

                // breaks out
                else
                    break;
            }

            // return true if the words are same
            if(equals == len)
                return true;
        }

        // go to the next node
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
    // open the dictionary
    FILE *filename = fopen(dictionary, "r");

    // check if the file exists
    if(filename == NULL)
        return false;

    //  variable declaration with the size of the largest string in the dictionary
    char correct[LENGTH + 1];

    // create two nodes
    struct node *array, *cur = NULL;

    while (fscanf(filename, "%s", correct) != EOF)
    {

        // dynamically allocate memory and check if the fuction returns NULL
        array = malloc(sizeof(words));
        if(array == NULL)
            return false;

        // copy string from dictonary to the linked list
        strcpy(array -> spell, correct);

        // assaign which is the next pointer
        array -> next = cur;

        // get the current address of the node
        cur = array;
    }

    // first is a global variable which keep track of the first element of the linked list
    first = cur;

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
    struct node *ptr = first;

    // for every word in the list, increment n by 1
    while(ptr != NULL)
    {
        n++;
        ptr = ptr -> next;
    }

    // returns the total word in the dictionary
    return n;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // calls destroy fuctioon and returns true if the fuction returns true
    if(destroy(first))
        return true;
    else
        return false;
}
