#define _XOPEN_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<cs50.h>
#include<string.h>

//checks if the strings are the same//

void comparestrings(char* a, char* b)
{
    int strlen1=strlen(a);
    int strlen2=strlen(b);
    
    //checks if the strings are of same length//
    
    if(strlen1!=strlen2)
    {
        printf("not enough length");
        exit(1);
    }
    
    //checks if the strings are the same//
    
    for(int n=0; n<strlen1; n++)
    {
        if(a[n]!=b[n])
        {
            printf("error\n");
            exit(1);   
        }
    }
}
int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("error\n");
        return 1;
    }
    char salt[3]={argv[1][0],argv[1][1],'\0'};
    comparestrings(argv[1],final);
    printf("success\n");
    return 0;
}