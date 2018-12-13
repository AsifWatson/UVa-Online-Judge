#include<stdio.h>
#include<math.h>

int main()
{
    int t,i,j,n,ret;
    double sum;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        sum=0;
        scanf("%d",&n);
        for(j=1;j<=n;j++){
            sum=sum+log10(j);
        }
        ret=floor(sum);
        printf("%d\n",ret+1);
    }
    return 0;
}
