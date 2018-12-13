#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t,i,j,n,a[110],mn,mx;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        mn=999999;
        mx=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }

        for(j=0;j<n;j++)
        {
            if(a[j]<mn)
            {
                mn=a[j];
            }
            if(a[j]>mx)
            {
                mx=a[j];
            }
        }
        printf("%d\n",2*(mx-mn));
    }
    return 0;
}
