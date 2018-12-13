#include<stdio.h>
#include<string.h>
int main()
{
    int i,l,c;
    char str[100];
    while(scanf("%s",str)==1)
    {
        c=getchar();
        l=strlen(str);
        for(i=l-1;i>=0;i--)
        {
            printf("%c",str[i]);
        }
        putchar(c);
    }
    return 0;
}
