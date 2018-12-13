#include<stdio.h>

int cola(int N)
{
    int s,r,sum=0;

    while(1){
        s=N/3;
        r=N%3;
        sum=sum+s;
        N=s+r;
        if(N<3){
            if(N==2){
               sum++;
               break;
            }
            if(N==1){
                break;
            }
        }
    }
    return sum;
}

int main()
{
    int n,s,r,i=1;
    while(scanf("%d",&n))
    {
        if(n==0){
            break;
        }

        printf("%d\n",cola(n));

        i++;

        if(i==11){
            break;
        }
    }
    return 0;
}
