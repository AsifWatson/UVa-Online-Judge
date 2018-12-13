#include<bits/stdc++.h>
using namespace std;

int Prime[1010],nPrime;
int mark[1010];

void seive(int n)
{
    nPrime=0;
    for(int i=0;i<1010;i++)
    {
        Prime[i]=0;
        mark[i]=0;
    }
    int i,j,limit=sqrt(n*1)+2;

    mark[1]=1;

    for(i=4;i<=n;i+=2)
        mark[i]=1;

    Prime[nPrime++]=1;
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
    int n,c,temp,print;
    while(scanf("%d %d",&n,&c)!=EOF)
    {
        seive(n);
        if(n==1)
        {
            nPrime--;
        }
        cout<<n<<" "<<c<<":";
        if(nPrime&1)
        {
            print = (c*2)-1;
            if(print>=nPrime)
            {
                for(int i=0;i<nPrime;i++)
                {
                    cout<<" "<<Prime[i];
                }
                cout<<endl<<endl;
                continue;
            }
            temp = nPrime-((c*2)-1);
            temp = temp/2;
            for(int i=temp;i<(nPrime-temp);i++)
            {
                cout<<" "<<Prime[i];
            }
        }
        else
        {
            print = c*2;
            if(print>=nPrime)
            {
                for(int i=0;i<nPrime;i++)
                {
                    cout<<" "<<Prime[i];
                }
                cout<<endl<<endl;
                continue;
            }
            temp = nPrime-(c*2);
            temp = temp/2;
            for(int i=temp;i<(nPrime-temp);i++)
            {
                cout<<" "<<Prime[i];
            }
        }
        cout<<endl<<endl;
    }

    return 0;
}
