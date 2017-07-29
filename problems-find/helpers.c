/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

int checkarray(int values[], int n)
{
    int first = values[0];
    for(int p=1; p<n; p++)
    {
        if(first> values[p])
        {
            first = 1;
            return first;
        }
        else
            first = values[p];
    }
    first = 0;
    return first;
}

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
    int check;
    do
    {
        for(int q=0; q<n; q++)
        {
            if(values[q]>values[q+1])
            {
                int swap=values[q+1];
                values[q+1]=values[q];
                values[q]=swap;
            }
        }
        check = checkarray(values, n);
    }
    while(check==1);
    return;
}
