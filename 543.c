#include<stdio.h>
#include<math.h>

int isPrime(int N)
{
    int i,flag=1;
    for(i=2;i<=sqrt(N);i++){
        if(N%i==0){
            flag=0;
        }
    }
    return flag;
}

int main()
{
    int n,i,b,a;

    while(scanf("%d",&n) && n){

        if(n%2==1 || n<6){
            continue;
        }
        a=0;

        for(i=3;i<n;i++){
            if(isPrime(i)){
                b=n-i;
                if(isPrime(b)){
                    printf("%d = %d + %d\n",n,i,b);
                    a=1;
                    break;
                }
            }
        }
        if(a==0){
            printf("Goldbach's conjecture is wrong.\n");
        }
    }

    return 0;
}
