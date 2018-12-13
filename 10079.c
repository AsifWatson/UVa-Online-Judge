#include<stdio.h>

int main()
{
    long  int n,sum;
    while(scanf("%ld",&n)==1){
        if(n<0)
            break;
        sum=n*(n+1)/2;
        printf("%ld\n",sum+1);
    }
    return 0;
}
