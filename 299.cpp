#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,L,k,c,temp;
    int L1[100];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        c=0;
        scanf("%d",&L);
        for(j=0;j<L;j++)
        {
            scanf("%d",&L1[j]);
        }
        for(j=0;j<L-1;j++)
        {
            for(k=j+1;k<L;k++)
            {
                if(L1[j]>L1[k])
                {
                    c++;
                    temp=L1[j];
                    L1[j]=L1[k];
                    L1[k]=temp;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",c);
    }
    return 0;
}
