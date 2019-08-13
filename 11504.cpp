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
|   CSTE,Noakhali Science and Technology University(11)     |
|                                                           |
************************************************************/

#include "bits/stdc++.h"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

vector<int> graph[100010];
bool visited[100010];
int outdegree[100010];
int indegree[100010];

void dfs(int u)
{
    visited[u]=true;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        memset(visited,false,sizeof(visited));
        memset(outdegree,0,sizeof(outdegree));
        memset(indegree,0,sizeof(indegree));
        int nodes,edges;
        cin>>nodes>>edges;
        for(int i=1;i<=edges;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            outdegree[x]++;
            indegree[y]++;
        }
        vector<pair<int,int> > v1,v2;
        for(int i=1;i<=nodes;i++)
        {
            v1.push_back({outdegree[i],i});
            v2.push_back({indegree[i],i});
        }
        sort(allre(v1));
        sort(all(v2));
        int ans1=0;
        for(int i=0;i<v1.size();i++)
        {
            if(!visited[v1[i].second])
            {
                ans1++;
                dfs(v1[i].second);
            }
        }
        memset(visited,false,sizeof(visited));
        int ans2=0;
        for(int i=0;i<v2.size();i++)
        {
            if(!visited[v2[i].second])
            {
                ans2++;
                dfs(v2[i].second);
            }
        }
        cout<<min(ans1,ans2)<<endl;
        for(int i=0;i<100010;i++)graph[i].clear();
    }
    return 0;
}
