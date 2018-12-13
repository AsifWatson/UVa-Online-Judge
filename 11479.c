#include<stdio.h>
int main()
{
    int T,i;
    long int a,b,c;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%ld %ld %ld",&a,&b,&c);
        if(a+b>c && a+c>b && b+c>a)
        {
            if(a==b && b==c && a==c)
            {
                printf("Case %d: Equilateral\n",i);
            }
            else if(a==b || b==c || c==a)
            {
                printf("Case %d: Isosceles\n",i);
            }
            else
            {
                printf("Case %d: Scalene\n",i);
            }
        }
        else
        {
            printf("Case %d: Invalid\n",i);
        }
    }
    return 0;
}
