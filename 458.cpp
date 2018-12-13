#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,ln,a;
    char str[10000];
    while(gets(str))
    {
        ln=strlen(str);
        for(i=0;i<ln;i++)
        {
            a=str[i]-7;
            printf("%c",a);
        }
        printf("\n");
    }
    return 0;
}
