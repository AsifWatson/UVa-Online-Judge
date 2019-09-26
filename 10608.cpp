/***********************************************************|
|          /\           /-------|   -----    |-----------|  |
|         /  \         /              |      |              |
|        /    \       |               |      |              |
|       /      \      |----|          |      |-------|      |
|      / ------ \          |-----|    |      |              |
|     /          \               |    |      |              |
|    /            \              /    |      |              |
|  ---            --- |---------/   -----  -----            |
|                                                           |
|   Codeforces = Asif_Watson  ||  Codechef = asif_watson    |
|   Mail = ashfaqislam33@gmail.com                          |
|   CSTE, Noakhali Science and Technology University(11)    |
|                                                           |
************************************************************/

#include "bits/stdc++.h"
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define allre(v) v.rbegin(),v.rend()
#define sp(x,y) fixed<<setprecision(y)<<x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const double pi = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;

template <class T> inline T bigmod(T p,T e,T M,T ret=1)
{
    for(; e>0; e>>=1){if(e&1)ret=(ret*p)%M; p=(p*p)%M;}
    return ret;
}

template <class T> inline T gcd(T x,T y){if(y==0)return x; return gcd(y,x%y);}
template <class T> inline T lcm(T x,T y){return ((x/gcd(x,y))*y);}

bool Reverse(long long a,long long b){return a>b;}

bool compare(pair<long long,long long> a,pair<long long,long long> b)
{
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}

int dfs(int v, vector<int> graph[], int visited[])
{
    int friends=1;
    visited[v]=1;

    for(int i=0; i<graph[v].size(); i++)
    {
        if(!visited[graph[v][i]])
        {
            friends+=dfs(graph[v][i],graph,visited);
        }
    }

    return friends;
}

int main()
{
    IOS

    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);

        map<pair<int,int>, int> mp;
        vector<int> graph[n+1];
        int visited[n+1];

        for(int i=0; i<=n; i++)visited[i]=0;

        while(m--)
        {
            int u,v;
            scanf("%d %d",&u,&v);

            if(mp[{u,v}] || mp[{v,u}])continue;

            graph[u].push_back(v);
            graph[v].push_back(u);

            mp[{u,v}]=1;
            mp[{v,u}]=1;
        }

        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])ans=max(ans,dfs(i,graph,visited));
        }

        printf("%d\n",ans);
    }

    return 0;
}
