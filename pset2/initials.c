#include<stdio.h>
#include<cs50.h>
#include<string.h>
int main(void)
{
    string name=get_string();
    int length=strlen(name);
    int e=name[0];
    if(e!=32)
    {
        if(e>=97&&e<=123)
            printf("%c",e-32);
        else
            printf("%c",e);
    }
    for(int p=0; p<length; p++)
    {
        int c=name[p], d=name[p+1];
        if(c==32)
        {
            if(d!=32)
            {
                if(d>=97&&d<=123)
                    printf("%c",d-32);
                else
                    printf("%c",d);
            }
        }
    }
    printf("\n");
}