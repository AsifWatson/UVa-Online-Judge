#include<bits/stdc++.h>
using namespace std;

int Prime[300000],nPrime;
int mark[1000002];

void seive(int n)
{
    int i,j,limit=sqrt(n*1)+2;

    mark[1]=1;

    for(i=4;i<=n;i+=2)
        mark[i]=1;

    Prime[nPrime++]=2;

    for(i=3;i<=n;i+=2)
    {
        if(!mark[i])
        {
            Prime[nPrime++]=i;
            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=i*2)
                {
                    mark[j]=1;
                }
            }
        }
    }
}


int main()
{
    int ugly=1;
    seive(1000000);
    for(int i=2; ;i++)
    {
        int n=i;
        int j;
        for(j=0;j<nPrime;j++)
        {
            if(j>2)
            {
                break;
            }
            while(n%Prime[j]==0)
            {
                n=n/Prime[j];
            }
            if(n==1)
                break;
        }
        if(j<=2)
        {
            ugly++;
        }
        if(ugly==1500)
        {
            cout<<"The 1500'th ugly number is "<<i<<"."<<endl;
            break;
        }
    }
    return 0;
}
