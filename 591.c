#include<stdio.h>
int main()
{
    int n,h,sum,k,i,d,j=1;
    char arr[50];

    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        sum=0;
        k=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        for(i=0;i<n;i++)
        {
            sum=sum+arr[i];
        }

        d=sum/n;

        for(i=0;i<n;i++)
        {
            if(arr[i]>d)
            {
                k=k+(arr[i]-d);
            }
        }

        printf("Set #%d\n",j);
        printf("The minimum number of moves is %d.\n\n",k);

        j++;
    }

    return 0;
}
