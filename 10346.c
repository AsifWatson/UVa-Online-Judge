#include<stdio.h>
int main()
{
    int n,k,i,a,b,t;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        t=n;
        for(i=1; ;i++)
        {
            a=n/k;
            if(a<1)
            {
                break;
            }
            else
            {
                t=t+a;
            }
            b=n%k;
            n=a+b;
        }
        printf("%d\n",t);
    }
    return 0;
}
