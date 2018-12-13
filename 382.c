#include<stdio.h>
int main()
{
    int n,N,c=0,i;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n)){
        c=0;
        if(n==0){
            printf("END OF OUTPUT\n");
            break;
        }
        N=n/2;
        for(i=1;i<=N;i++){
            if(n%i==0){
                c=c+i;
            }
        }
        if(c==n){
            printf("%5d  PERFECT\n",n);
        }
        if(c>n){
            printf("%5d  ABUNDANT\n",n);
        }
        if(c<n){
            printf("%5d  DEFICIENT\n",n);
        }
    }
    return 0;
}
