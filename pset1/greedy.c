#include<stdio.h>
#include<cs50.h>
int get_amount(void)
{
    float amount;
    do
    {
        printf("O hai! How much change is owed?\n");
        amount=get_float();
    }
    while(amount<0);
    amount *=1000;
    return amount;
}
int main (void)
{
    int amount = get_amount();
    int count=0;
    if(amount<0)
        count=1;
    while(amount>=250)
    {
        count++;
        amount -=250;
    }
    while(amount>=100)
    {
        count++;
        amount -=100;
    }
    while(amount>=50)
    {
        count++;
        amount -=50;
    }
    while(amount>=10)
    {
        count++;
        amount -=10;
    }
    printf("%d\n",count);
}