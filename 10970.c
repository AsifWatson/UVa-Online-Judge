#include<stdio.h>
int main()
{
    int M,N,a;
    while(scanf(" %d %d",&M,&N)!=EOF)
    {
        a=(N-1)+N*(M-1);
        printf("%d\n",a);
    }
    return 0;
}
