#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,n,i,a,b;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        a=(315*n)+36962;
        b=a%100;
        printf("%d\n",abs(b/10));
    }
    return 0;
}
