#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,j,r,k,m;
    int s[510];
    int sum[510];
    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        m=15000000;
        scanf("%d",&r);

        for(j=0;j<r;j++)
        {
            scanf("%d",&s[j]);
        }
        for(j=0;j<510;j++)
        {
            sum[j]=0;
        }
        for(j=0;j<r;j++)
        {
            for(k=0;k<r;k++)
            {
                sum[j]=sum[j]+(abs(s[j]-s[k]));
            }
            if(sum[j]<m)
            {
                m=sum[j];
            }
        }
        printf("%d\n",m);

    }
    return 0;
}
