#include<stdio.h>
#include<string.h>

int main()
{
    char str[100000];
    long int flag=0,i;
    while(gets(str))
    {
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]=='"')
            {
                if(flag==0)
                {
                    printf("``");
                    flag=1;
                    continue;
                }
                else if(flag==1)
                {
                    printf("''");
                    flag=0;
                    continue;
                }
            }
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
