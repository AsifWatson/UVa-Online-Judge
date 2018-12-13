#include<bits/stdc++.h>
#define N 20000001
using namespace std;

int Prime[20000010];
int nPrime;
int mark[20000010];
int tprime[20000000];


void check_twin_prime()
{
    long long  int i,j,s=1;
    for(i=1;i<=20000010;i++)
    {
        if(mark[i]==0 && mark[i+2]==0)
        {
            tprime[s++]=i;
        }
    }
}

void seive(int n)
{
    int i,j,limit=sqrt(n*1)+2;
    mark[1]=1;
    for(i=4;i<=n;i+=2)
        mark[i]=1;

    Prime[nPrime++]=2;
    for(i=3;i<=n;i+=2){
        if(!mark[i]){
            Prime[nPrime++]=i;
            if(i<=limit){
                for(j=i*i;j<=n;j+=i*2){
                    mark[j]=1;
                }
            }
        }
    }
}


int main()
{
    int s;
    seive(20000010);
    check_twin_prime();
    while(scanf("%d",&s)!=EOF)
    {
        printf("(%d, %d)\n",tprime[s],tprime[s]+2);
    }
    return 0;
}
