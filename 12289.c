#include<stdio.h>
#include<string.h>
int main()
{
    int t,i;
    char s[10];

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%s",s);
        if(strlen(s)==5)
        {
            if(s[0]=='t')
            {
                if(s[1]=='h')
                {
                    if(s[2]=='r')
                    {
                        if(s[3]=='e')
                            printf("3\n");
                        else
                        {
                            if(s[4]=='e')
                                printf("3\n");
                        }
                    }
                    else
                    {
                        if(s[3]=='e' && s[4]=='e')
                            printf("3\n");
                    }
                }
                else
                {
                    if(s[2]=='r' && s[3]=='e' && s[4]=='e')
                        printf("3\n");
                }
            }
            else
            {
                if(s[1]=='h' && s[2]=='r' && s[3]=='e' && s[4]=='e')
                    printf("3\n");
            }
        }
        else if(strlen(s)==3)
        {
            if(s[0]=='o')
            {
                if(s[1]=='n')
                    printf("1\n");

                else
                {
                    if(s[2]=='e')
                        printf("1\n");
                }
            }
            else if(s[0]=='t')
            {
                if(s[1]=='w')
                    printf("2\n");

                else
                {
                    if(s[2]=='o')
                        printf("2\n");
                }
            }
            else
            {
                if(s[1]=='n')
                {
                    if(s[2]=='e')
                        printf("1\n");
                }

                if(s[1]=='w')
                {
                    if(s[2]=='o')
                        printf("2\n");
                }
            }
        }
    }
    return 0;
}
