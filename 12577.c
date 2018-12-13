#include<stdio.h>
int main()
{
    char str[10];
    int i;
    for(i=1;;i++)
    {
        gets(str);
        if(str[0]=='*')
        {
            break;
        }
        if(str[0]=='H')
        {
            printf("Case %d: Hajj-e-Akbar\n",i);
        }
        if(str[0]=='U')
        {
            printf("Case %d: Hajj-e-Asghar\n",i);
        }
    }
    return 0;
}
