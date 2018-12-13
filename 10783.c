#include<stdio.h>
int main()
{
    int a,b,d,n,i,T,sum;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&a,&b);
        if(a%2==0)
        {
            a=a+1;
        }
        if(b%2==0)
        {
            b=b-1;
        }
        d=2;
        n=((b-a)/2)+1;
        sum=(n*(2*a+(n-1)*d)/2);
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
