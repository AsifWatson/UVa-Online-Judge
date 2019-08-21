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
#define all(v) v.begin(),v.end()
#define allre(v) v.rbegin(),v.rend()
#define sp(x,y) fixed<<setprecision(y)<<x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) ((a*b)/__gcd(a,b))

using namespace std;

const double pi = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;

bool Reverse(long long a,long long b){return a>b;}

bool compare(pair<long long,long long> a,pair<long long,long long> b)
{
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}

vector<int> graph[10005];
int visited[10005];

void dfs(int source)
{
    visited[source]=1;
    for(int i : graph[source])
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int n,m,l;
        cin>>n>>m>>l;

        while(m--)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
        }

        memset(visited,0,sizeof(visited));
        while(l--)
        {
            int k;
            cin>>k;
            if(!visited[k])dfs(k);
        }

        int ans=0;
        for(int i=1;i<=n;i++)if(visited[i])ans++;

        cout<< ans <<endl;

        for(int i=0;i<10005;i++)graph[i].clear();
    }

    return 0;
}

