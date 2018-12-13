#include<bits/stdc++.h>
using namespace std;

int mark[1000010];
int dMark[1000010];
int arr[1000010];

int digitSum(int a)
{
    int sum=0,b,rem;
    b=a;
    while(b!=0)
    {
        rem=b%10;
        b=b/10;
        sum=sum+rem;
    }
    return sum;
}


void seive(int n)
{
    int i,j,limit=sqrt(n*1)+2;

    mark[0]=1;
    mark[1]=1;
    dMark[2]=1;

    for(i=4;i<=n;i+=2)
        mark[i]=1;

    for(i=3;i<=n;i+=2)
    {
        if(!mark[i])
        {
            if(mark[digitSum(i)]==0)
            {
                dMark[i]=1;
            }
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

    int n,t1,t2,coun,a,b;
    scanf("%d",&n);
    seive(1000010);
    arr[0]=0;
    for(int i=1;i<1000000;i++)
    {
        if(dMark[i]==1)
        {
            arr[i]=arr[i-1]+1;
            continue;
        }
        arr[i]=arr[i-1];
    }

    while(n--)
    {
        scanf("%d %d",&t1,&t2);
        coun=(arr[t2]-arr[t1]);
        if(dMark[t1]==1)
            coun=coun+1;
        cout<<coun<<endl;
    }

    return 0;
}
