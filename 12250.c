#include<stdio.h>
#include<string.h>
int main()
{
    char S[14];
    int c=1;
    while(scanf("%s",S))
    {
        if(c==2001 || strcmp(S,"#")==0)
            break;

        if(strcmp(S,"HELLO")==0)
        {
            printf("Case %d: ENGLISH\n",c);
        }

        else if(strcmp(S,"HOLA")==0)
        {
            printf("Case %d: SPANISH\n",c);
        }

        else if(strcmp(S,"HALLO")==0)
        {
            printf("Case %d: GERMAN\n",c);
        }

        else if(strcmp(S,"BONJOUR")==0)
        {
            printf("Case %d: FRENCH\n",c);
        }

        else if(strcmp(S,"CIAO")==0)
        {
            printf("Case %d: ITALIAN\n",c);
        }

        else if(strcmp(S,"ZDRAVSTVUJTE")==0)
        {
            printf("Case %d: RUSSIAN\n",c);
        }

        else
        {
            printf("Case %d: UNKNOWN\n",c);
        }

        c++;
    }
    return 0;
}
