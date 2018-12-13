#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,T,n,P,Q,j,d[100],c,sum;

    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
        c=0;
        sum=0;

        scanf("%d %d %d",&n,&P,&Q);

        for(j=0;j<n;j++)
        {
            scanf("%d",&d[j]);
        }

        for(j=0;j<P;j++)
        {
            if(n==j)
            {
                break;
            }
            if(sum<=Q)
                sum=sum+d[j];
            if(Q<sum)
                break;
            if(sum<=Q)
                c++;

        }

        printf("Case %d: %d\n",i,c);

    }

    return 0;
}
