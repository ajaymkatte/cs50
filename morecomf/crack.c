#define _XOPEN_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<cs50.h>
#include<string.h>

//checks if the strings are the same and if they're indeed the same, prints the password and exits returing 0//

void comparestrings(char* finalhashed, char* final, char* hashed)
{
    int length=strlen(finalhashed);
    
    //checks if the strings are the same//
    
    for(int n=0; n<length; n++)
    {
        if(finalhashed[n]!=hashed[n])
        {
                return;
        }
    }
    printf("%s\n",final);
    exit(0);
}

//passes hashed password and argv[1] for comparing//


void comstrandargv(char* final, char* salt, char* hashed)
{
    string finalhashed=crypt(final,salt);
    comparestrings(finalhashed, final, hashed);
}

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("error\n");
        return 1;
    }
    
    char* hashed=argv[1];
    
    //scrap salt//
    
    char salt[3]={hashed[0], hashed[1], '\0'};
    
    //get the pass//
    
    for(int n=0; n<10; n++)
    {
        for(int p=0; p<26; p++)
        {
            char final[2]={'z', '\0'};
            comstrandargv(final,salt,hashed);
        }
    }
    return 0;
}