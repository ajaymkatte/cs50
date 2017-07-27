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


//passes an alphabet as requried, controls both uppercase and lowercase while excluding the rest of the ascii keys//


char retrievechar(int x)
{
    char alpha;
    if(x<=25)
        alpha=65+x;
    else
        alpha=65+x+6;
    return alpha;
}

//main starts from here//

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
    
    for(int n=0; n<5; n++)
    {
        for(int p=0; p<52; p++)
        {
            char alpha0 = retrievechar(p);
            if(n==0)
            {
                char final[2] = {alpha0,'\0'};
                comstrandargv(final,salt,hashed);
            }
            
//if the pass is more than one character long//
            
            if(n>0)
            {
                
//if the pass is two characters long//
                
                if(n==1)
                {
                    for(int q=0; q<52; q++)
                    {
                        char alpha1 = retrievechar(q);
                        char final[3] = {alpha0, alpha1, '\0'};
                        comstrandargv(final,salt,hashed);
                    }
                }
                
//ends//
                
//if the pass is three characters long//
                
                
                if(n==2)
                {
                    for(int q=0; q<52; q++)
                    {
                        char alpha1 = retrievechar(q);
                        for(int r=0; r<52; r++)
                        {
                            char alpha2 = retrievechar(r);
                            char final[4] = {alpha0, alpha1, alpha2, '\0'};
                            comstrandargv(final,salt,hashed);
                        }
                    }
                }
                
//ends//
                
//if the pass is four characters long//
                
                if(n==3)
                {
                    for(int q=0; q<52; q++)
                    {
                        char alpha1 = retrievechar(q);
                        for(int r=0; r<52; r++)
                        {
                            char alpha2 = retrievechar(r);
                            for(int s=0; s<52; s++)
                            {
                                char alpha3 = retrievechar(s);
                                char final[5] = {alpha0, alpha1, alpha2, alpha3, '\0'};
                                comstrandargv(final,salt,hashed);
                            }
                        }
                    }
                }
                
//ends//
                
                
//if the pass is five charcters long//
                
                if(n==4)
                {
                    for(int q=0; q<52; q++)
                    {
                        char alpha1 = retrievechar(q);
                        for(int r=0; r<52; r++)
                        {
                            char alpha2 = retrievechar(r);
                            for(int s=0; s<53; s++)
                            {
                                char alpha3 = retrievechar(s);
                                for(int t=0; t<52; t++)
                                {
                                    char alpha4 = retrievechar(t);
                                    char final[6] = {alpha0, alpha1, alpha2, alpha3, alpha4, '\0'};
                                    comstrandargv(final,salt,hashed);
                                }
                                
                            }
                        }
                    }
                }
                
//ends//
            }
        }
    }
    return 0;
}