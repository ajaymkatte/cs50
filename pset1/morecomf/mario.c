#include<stdio.h>
#include<cs50.h>

// main starts here
int main(void)
{
    int steps, a, com;

    // get a number greater than 0 and no greater than 23
    do{
        printf("Height: ");
        steps=get_int();
    }
    while(steps < 0 || steps > 23);

    if(steps == 0)
        return 0;

    int b = steps, c = 1, d = 1;

    // iterate till the b is not equal to zero
    while(b != 0)
    {
        a = steps;
        com = 1;

        // iterate till the c is not equal to zero
        while(a != 0)
        {

            if(com < b)
                printf(" ");
            else
                printf("#");
            ++com;
            --a;
        }

        // spacer
        printf("  ");

        if(c <= steps)
        {
            int e = d;
            while(e!=0)
            {
                printf("#");
                --e;
            }
        }

        // print new line
        printf("\n");
        --b;
        ++c;
        ++d;
    }

    return 0;
}