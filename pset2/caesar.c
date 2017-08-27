#include<stdio.h>
#include<cs50.h>
#include<string.h>
int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("error\n");
        return 1;
    }
    int jump=atoi(argv[1]);
    jump=jump%26;
    printf("plaintext:");
    string name=get_string();
    printf("ciphertext:");
    int length=strlen(name);
    for(int p=0; p<length; p++)
    {
        int c=name[p];
        if((c>=65&&c<=90)||(c>=97&&c<=122))
        {
            if(c>=65&&c<=90)
            {
                int alphabet=c-65;
                if((c+jump)>90)
                {
                    int junk=jump+alphabet-26;
                    while(junk>26)
                        junk-=26;
                    printf("%c",65+junk);
                }
                else
                    printf("%c",(c+jump));
            }
            if(c>=97&&c<=122)
            {
                int alphabet=c-97;
                if((c+jump)>122)
                {
                    int junk=jump+alphabet-26;
                    while(junk>26)
                        junk-=26;
                    printf("%c",97+junk);
                }
                else
                    printf("%c",(c+jump));
            }
        }
        else
            printf("%c",name[p]);
    }
    printf("\n");
    return 0;
}