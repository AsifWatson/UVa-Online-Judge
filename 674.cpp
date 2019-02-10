#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define memo(a,b) memset((a),(b),sizeof(a))
#define all(v) v.begin(),v.end()
#define allre(v) v.rbegin(),v.rend()
#define sp(x,y) fixed<<setprecision(y)<<x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) ((a*b)/__gcd(a,b) )
using namespace std;

const double pi = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;

int coin[5]={1,5,10,25,50};
int make,totalCoins=5;
int dp[6][7500];

int call(int i,int amount)
{
    if(i>=totalCoins)
    {
        if(amount==0) return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];

    int ret1=0,ret2=0;
    if(amount-coin[i]>=0) ret1=call(i,amount-coin[i]);
    ret2=call(i+1,amount);

    dp[i][amount]=ret1+ret2;

    return dp[i][amount];

}

int main()
{
    IOS
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&make)!=EOF)
    {
        if(make==0)
        {
            printf("1\n");
            continue;
        }
        printf("%d\n",call(0,make));
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

int nways[7560];

int main()
{
    nways[0]=1;
    int coin[5]={1,5,10,25,50};

    for(int i=0;i<5;i++)
    {
        for(int j=coin[i],k=0;j<=7500;j++,k++)
        {
            nways[j]+=nways[k];
        }
    }
    int make;
    while(scanf("%d",&make)!=EOF)
    {
        printf("%d\n",nways[make]);
    }

    return 0;
}
*/
