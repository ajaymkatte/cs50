#include<stdio.h>
#include<cs50.h>
int main()
{
    printf("Minutes: ");
    int min;
    min = get_int();
    printf("Water: %d\n", min*12);
}