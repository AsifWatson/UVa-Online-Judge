#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,b=1;
    while(scanf("%d",&n))
    {
        int a;
        if(n<0)
        {
            break;
        }
        for(int i=0;;i++)
        {
            a=pow(2,i);
            if(a==n)
            {
                printf("Case %d: %d\n",b,i);
                break;
            }
            if(a>n)
            {
                printf("Case %d: %d\n",b,i);
                break;
            }
        }
        b++;
    }
    return 0;
}
