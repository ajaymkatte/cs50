#include<stdio.h>
#include<cs50.h>

int main()
{
    printf("Minutes: ");
    int min = get_int();

    // prints min times 12
    printf("Water: %d\n", min*12);
    return 0;
}