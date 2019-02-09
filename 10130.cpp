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

int cost[1001],weight[1001];

int dp[1001][31];

int fun(int i,int w,int capacity,int n)
{
    if(i==n+1) return 0;

    if(dp[i][w]!=-1) return dp[i][w];

    int profit1=0,profit2=0;
    if(w+weight[i]<=capacity) profit1=cost[i]+fun(i+1,w+weight[i],capacity,n);

    profit2=fun(i+1,w,capacity,n);

    dp[i][w]=max(profit1,profit2);

    return dp[i][w];
}

int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>cost[i];
            cin>>weight[i];
        }
        int g;
        cin>>g;
        while(g--)
        {
            int capacity;
            cin>>capacity;
            memset(dp,-1,sizeof(dp));
            sum+=fun(1,0,capacity,n);
        }
        cout<<sum<<endl;
    }
    return 0;
}
