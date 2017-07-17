#include<stdio.h>
#include<cs50.h>
int splitx(long long ccnum)
{
    int junk=ccnum%10;
    return junk;
}
int main(void)
{
    printf("Number:\t");
    long long ccnum=get_long_long();
    int ultimate=0;
    int n=0, decimal=0;
    int sum=0, sum1=0, sum2=0;
    do
    {
        decimal=ultimate;
        ultimate=ccnum;
        int junk=splitx(ccnum);
        if(ccnum<0)
        {
            
        }
        if(n%2==0)
            sum1=sum1+junk;
        else
        {
            int junks=junk*2;
            sum2=sum2+(junks%10)+(junks/10);
        }
        ccnum/=10;
        n++;
    }
    while(ccnum>1);
    sum=sum1+sum2;
    if(sum%10==0)
    {
        if(decimal==34||decimal==37)
            printf("AMEX\n");
        if(ultimate==4)
            printf("VISA\n");
        if(decimal==51||decimal==52||decimal==53||decimal==54||decimal==55)
            printf("MASTERCARD\n");
    }
    else
        printf("INVALID\n");
}