#include<stdio.h>
int main()
{
    int T,i;
    long int C,d;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%ld %ld",&C,&d);
        printf("Case %d: %.2lf\n",i,C+(d/1.8));
    }
    return 0;
}
