#include<stdio.h>
#include<cs50.h>
int main()
{
    int steps, a, b, con, com;
    do
    {
        printf("Height = ");
        steps = get_int();
    }
    while (steps<0 || steps>23);
    a=steps;
    b=steps;
    con=0;
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
}