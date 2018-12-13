#include<stdio.h>
int main()
{
    long int N,a,sum;
    while(scanf("%ld",&N)!=EOF)
    {
        sum=0;
        a=(((N+1)*(N+1))/2)-1;;
        sum=a+(a-2)+(a-4);
        printf("%ld\n",sum);
    }
    return 0;
}
