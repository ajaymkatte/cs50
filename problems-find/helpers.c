/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int n_init=0, n_final=n;
    do
    {
        int x = ((n_init + n_final)/2);
        if(values[x]==value)
            return true;
        else if(value<values[x])
            n_final = x-1;
        else if(value>values[x])
            n_init = x+1;
    }
    while((n_final-n_init)>=0);
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    return;
}
