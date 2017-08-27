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
    int n=strlen(argv[1]);
    for(int p=0; p<n; p++)
    {
        if((argv[1][p]>=65&&argv[1][p]<=90)||(argv[1][p]>=97&&argv[1][p]))
            p=p+1-1;
        else
        {
            printf("error\n");
            return 1;
        }
    }
    printf("plaintext: ");
    string name=get_string();
    int length=strlen(name);
    printf("ciphertext: ");
    int count=0;
    for(int p=0; p<length; p++)
    {
        int c=name[p],jump=0;
        int z=count;
        while(n<=z)
            z-=n;
        if((c>=65&&c<=90)||(c>=97&&c<=122))
        {
            int junks=argv[1][z];
            if(junks>=65&&junks<=90)
                jump=junks-65;
            else if(junks>=97&&junks<=122)
                jump=junks-97;
            ++count;
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
}