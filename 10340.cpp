#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[100000];
    char t[100000];
    int i,j,a,c;
    while(scanf("%s %s",s,t)!=EOF)
    {
        a=0;
        c=0;
        for(i=0;i<strlen(s);i++)
        {
            for(j=a;j<strlen(t);j++)
            {
                if(s[i]==t[j])
                {
                    c++;
                    break;
                }
            }
            a=j+1;
        }
        if(strlen(s)==c)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
