#include<stdio.h>
#include<cs50.h>
int main (void)
{
    int steps,a,b,c,d,com;
    do{
        printf("Height: ");
        steps=get_int();
    }
    while(steps<0 || steps>23);
    if(steps==0)
        return 0;
    b=steps;
    c=1;
    d=1;
    while(b!=0)
    {
        a=steps;
        com=1;
        while(a!=0)
        {
            
            if(com<b)
                printf(" ");
            else
                printf("#");
            ++com;
            --a;
        }
        printf("  ");
        if(c<=steps)
        {
            int e=d;
            while(e!=0)
            {
                printf("#");
                --e;
            }
        }
        printf("\n");
        --b;
        ++c;
        ++d;
    }
}