#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,s,d,i;

    scanf("%lld",&n);

    for(i=1;i<=n;i++){

        scanf("%lld %lld",&s,&d);

        if(d>s || (s%2==0 && d%2==1) || (s%2==1 && d%2==0) ){
            printf("impossible\n");
        }
        else
            printf("%lld %lld\n",(s+d)/2,(s-d)/2);
    }

    return 0;
}
