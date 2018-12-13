#include<stdio.h>
int main()
{
    int N,sum;
    for(;;)
    {
        scanf("%d",&N);
        if(N==0)
            break;
        printf("%d\n",(N*(N+1)*(2*N+1))/6);
    }
    return 0;
}
