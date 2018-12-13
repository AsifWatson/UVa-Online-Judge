#include<stdio.h>
int main()
{
    int arr[60],T,N,i,j,high,low;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        high=0;
        low=0;
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(j=1;j<N;j++)
        {
            if(arr[j-1]<arr[j])
            {
                high++;
            }
            if(arr[j-1]>arr[j])
            {
                low++;
            }
        }
        printf("Case %d: %d %d\n",i,high,low);
    }
    return 0;
}
