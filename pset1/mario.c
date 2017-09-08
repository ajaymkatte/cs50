#include<stdio.h>
#include<cs50.h>

int main()
{
    int steps, a, b, con, com;

    // get a number greater than 0 and no greater than 23
    do
    {
        printf("Height = ");
        steps = get_int();
    }
    while (steps<0 || steps>23);

    int a=steps, b=steps, con=0;

    // iterate till the b is not equal to zero
    while(b!=0)
    {
        a=steps;
        com=steps;
        while(a!=0)
        {
            if(com>con+1)
            printf(" ");
        else
            printf("#");
        --a;
        --com;
        }
        ++con;
        --b;
        printf("#");
        printf("\n");
    }

    return 0;
}