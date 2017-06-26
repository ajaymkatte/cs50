#include<stdio.h>
#include<cs50.h>
int main (void)
{
    printf("O hai! How much change is owed?\n");
    float owed;
    int junk;
    owed=get_float();
    if(owed<0)
        return 0;
    junk=owed*100;
    junk=junk%100;
    int sum=0;
    while(junk>=25)
    {
        sum++;
        junk=junk-25;
    }
    while(junk>=10)
    {
        sum++;
        junk=junk-10;
    }
    while(junk>=5)
    {
        sum++;
        junk=junk-5;
    }
    while(junk>=1)
    {
        sum=sum+(junk/1);
        junk=0;
    }
    printf("%d\n",sum);
}