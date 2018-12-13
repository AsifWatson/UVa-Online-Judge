#include<stdio.h>
#include<math.h>

int isPrime(int N)
{
    int i,flag=0;
    for(i=2;i<=sqrt(N);i++){
        if(N%i==0){
            flag=1;
        }
    }
    return flag;
}

int main()
{
    int n,a,c,j,i,k;
    int arr[100000];
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        }
        j=0;
        c=0;
        for(i=0;i<10000;i++){
            arr[i]=0;
        }
        for(i=2;i<n;i++){
            a=isPrime(i);
            if(a==0){
                arr[j++]=i;
            }
        }
        for(i=0;i<j;i++){
            if(arr[i]*2==n){
                c++;
            }
            for(k=i+1;k<j;k++){
               if(arr[i]+arr[k]==n){
                c++;
               }
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
