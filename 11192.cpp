#include<bits/stdc++.h>
using namespace std;

int main()
{
    int g,ln,a,b,c,i,j;
    char str[1000];
    while(scanf("%d",&g))
    {
        if(g<1)
        {
            break;
        }
        scanf("%s",str);
        ln=strlen(str);
        c=ln/g;
        a=0;
        j=0;
        while(1)
        {
            b=a+c;
            for(i=b-1;i>=a;i--)
            {
                printf("%c",str[i]);
            }
            a=b;
            j++;
            if(j==g)
            {
                break;
            }
        }
        printf("\n");

    }
    return 0;
}
