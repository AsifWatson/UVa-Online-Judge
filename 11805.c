#include<stdio.h>
int main()
{
    int T,N,K,P,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf(" %d %d %d",&N,&K,&P);
        if(P<N)
        {
            if(K+P>N)
            {
                printf("Case %d: %d\n",i,(K+P)%N);
            }
            else if(K+P==N || K+P<N)
            {
                printf("Case %d: %d\n",i,K+P);
            }
        }

        else if(P==N || P%N==0)
        {
            printf("Case %d: %d\n",i,K);
        }

        else if(P>N)
        {
            if((K+P)%N==0)
            {
                printf("Case %d: %d\n",i,N);
            }
            else
            {
                printf("Case %d: %d\n",i,(K+P)%N);
            }
        }
    }
    return 0;
}
