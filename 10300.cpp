#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c,sum,n,i,j,f;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        sum=0;
        scanf("%lld",&f);
        for(j=1;j<=f;j++)
        {
            scanf(" %lld %lld %lld",&a,&b,&c);
            sum=sum+(a*c);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
