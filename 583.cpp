#include<bits/stdc++.h>
using namespace std;

int Prime[5010],nPrime;
int mark[47010];

void seive(int n)
{
    nPrime=0;
    for(int k=0;k<47010;k++)
    {
        mark[k]=0;
    }
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
    int a;
    while(scanf("%d",&a))
    {
        if(a==0)
        {
            break;
        }
        cout<<a<<" = ";
        int arr[100];
        int j=0;
        if(a<0)
        {
            cout<<"-1 x ";
            a=a*(-1);
        }
        seive(sqrt(a));
        for(int i=0;i<nPrime;i++)
        {
            while(a%Prime[i]==0)
            {
                a=a/Prime[i];
                arr[j++]=Prime[i];
            }
            if(a==1)
                break;
        }
        if(j==0)
        {
            cout<<a<<endl;
            continue;
        }
        if(j==1 && a==1)
        {
            cout<<arr[0];
            cout<<endl;
            continue;
        }
        if(a>1 && j==1)
        {
            cout<<arr[0]<<" x "<<a;
            cout<<endl;
            continue;
        }
        if(a>1 && j==2)
        {
            cout<<arr[0]<<" x "<<arr[1]<<" x "<<a;
            cout<<endl;
            continue;
        }
        if(a>1 && j>2)
        {
            cout<<arr[0];
            for(int i=1;i<j-1;i++)
            {
                cout<<" x "<<arr[i];
            }
            cout<<" x "<<arr[j-1];
            cout<<" x "<<a;
            cout<<endl;
            continue;
        }
        cout<<arr[0];
        for(int i=1;i<j-1;i++)
        {
            cout<<" x "<<arr[i];
        }
        cout<<" x "<<arr[j-1];
        cout<<endl;
    }
    return 0;
}
