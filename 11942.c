#include<stdio.h>
int main()
{
    int ar[20],i,j,n,a,b;
    scanf("%d",&n);
    printf("Lumberjacks:\n");
    for(i=1;i<=n;i++)
    {
        a=0;
        b=0;
        for(j=0;j<=9;j++)
        {
            scanf("%d",&ar[j]);
        }
        for(j=0;j<=8;j++)
        {
            if(ar[j]>ar[j+1])
            {
                a++;
            }
        }
        if(a==9)
        {
            printf("Ordered\n");
            continue;
        }
        for(j=0;j<=8;j++)
        {
            if(ar[j]<ar[j+1])
            {
                b++;
            }
        }
        if(b==9)
        {
            printf("Ordered\n");
            continue;
        }
        printf("Unordered\n");
    }
    return 0;
}
