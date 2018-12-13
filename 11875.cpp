#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,n,j,arr[100];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        printf("Case %d: %d\n",i,arr[(n-1)/2]);
    }
    return 0;
}
