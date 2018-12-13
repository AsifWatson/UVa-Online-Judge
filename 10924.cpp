#include<bits/stdc++.h>
using namespace std;

int mark[1500];

void seive(int n)
{
    for(int i=0;i<1500;i++)
    {
        mark[i]=0;
    }
    int i,j,limit=sqrt(n*1)+2;
    mark[0]=1;
    mark[1]=0;

    for(i=4;i<=n;i+=2) mark[i]=1;

    for(i=3;i<=n;i+=2)
    {
        if(!mark[i])
        {
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
    char str[25];
    while(scanf("%s",str)!=EOF)
    {
        int sum=0;
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]>=97)
            {
                sum = sum + ((str[i]-'a')+1);
            }
            if(str[i]<=90)
            {
                sum = sum + ((str[i]-'A')+1) + 26 ;
            }
        }
        seive(sum);

        if(mark[sum])
        {
            cout<<"It is not a prime word."<<endl;
        }
        else
            cout<<"It is a prime word."<<endl;
    }
    return 0;
}
