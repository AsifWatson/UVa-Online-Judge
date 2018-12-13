#include<stdio.h>
int main()
{
    int T,a,b,c,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf(" %d %d %d",&a,&b,&c);
        if(a>b && a>c)
        {
            if(b>c)
            {
                printf("Case %d: %d\n",i,b);
            }
            else if(c>b)
            {
                printf("Case %d: %d\n",i,c);
            }
        }

        if(b>a && b>c)
        {
            if(c>a)
            {
                printf("Case %d: %d\n",i,c);
            }
            else if(a>c)
            {
                printf("Case %d: %d\n",i,a);
            }
        }

        if(c>b && c>a)
        {
            if(a>b)
            {
                printf("Case %d: %d\n",i,a);
            }
            else if(b>a)
            {
                printf("Case %d: %d\n",i,b);
            }
        }

        if(a==b && b!=c)
        {
            printf("Case %d: %d\n",i,b);

        }

        if(b==c && c!=a)
        {
            printf("Case %d: %d\n",i,b);
        }

        if(c==a && a!=b)
        {
            printf("Case %d: %d\n",i,a);
        }

        if(a==b && b==c)
        {
            printf("Case %d: %d\n",i,b);
        }
    }
    return 0;
}
