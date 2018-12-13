#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,M,i,tk,d,j,x,y;
    int a[100000];
    while(scanf("%d",&N)!=EOF)
    {
        x=0;
        y=0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&M);

        sort(a,a+N);

        tk=M/2;

        for(i=0;i<N-1;i++)
        {
            if(a[i]>tk)
            {
                break;
            }
            for(j=1;j<N;j++)
            {
                if(a[i]+a[j]==M)
                {
                    d=a[j]-a[i];
                    x=a[i];
                    y=a[j];
                    break;
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",x,y);
    }
    return 0;
}
