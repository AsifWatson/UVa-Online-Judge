#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[10000];
    int i,j,sum,a,b,c,d;
    while(scanf("%s",str))
    {
        if(str[0]=='0')
        {
            break;
        }
        sum=0;
        c=1;
        for(i=0;i<strlen(str);i++)
        {
            sum=sum+(str[i]-'0');
        }
        if(sum>9)
        {
            d=sum;
            sum=0;
            while(d>9)
            {
                a=d;
                sum=0;
                while(a!=0)
                {
                    b=a%10;
                    a=a/10;
                    sum=sum+b;
                }
                d=sum;
                c++;
            }
        }
        if(d==9)
        {
            printf("%s is a multiple of 9 and has 9-degree %d.\n",str,c);
        }
        else
        {
            printf("%s is not a multiple of 9.\n",str);
        }
    }
    return 0;
}
