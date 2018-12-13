#include<stdio.h>
int main()
{
    int c,n,i,j,sum,avg,cnt;
    double per;
    int arr[1010];
    scanf("%d",&c);
    for(i=1;i<=c;i++)
    {
        sum=0;
        cnt=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
            sum=sum+arr[j];
        }
        avg=sum/n;
        for(j=0;j<n;j++)
        {
            if(arr[j]>avg)
            {
                cnt++;
            }
        }
        per=((double)cnt/(double)n)*100;
        printf("%.3lf%%\n",per);
    }
    return 0;
}
