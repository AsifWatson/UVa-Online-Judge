#include<bits/stdc++.h>
using namespace std;

int main()
{

    int a,b,boxA,boxB,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %d %d",&a,&b);
        boxA=a/3;

        boxB=b/3;

        printf("%ld\n",boxA*boxB);
    }
    return 0;
}
