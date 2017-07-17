#include<stdio.h>
#include<cs50.h>
int main(void)
{
    printf("Number: ");
    long long cc;
    cc=get_long_long();
    int a=1;
    long long divide=10;
    int sum1=0, junk, sum2=0;
    while(a<=16)
    {
        if(a%2==0)
            sum1=sum1+cc%divide;
        else
        {
            junk=cc%divide;
            junk*=2;
            if(junk>=10)
            {
                int quo,rem;
                quo=junk/10;
                rem=junk%10;
                junk=quo+rem;
            }
        }
        sum2=sum2+junk;
        divide*=10;
        a++;
    }
    int sum=sum1+sum2;
    printf("%d",sum);
}