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

vector<int> graph[105];
set<int> inaccessible;
int visited[105];

void dfs(int source)
{
    visited[source]=1;
    for(int i=0;i<graph[source].size();i++)
    {
        inaccessible.erase(graph[source][i]);
        if(!visited[graph[source][i]])
        {
            dfs(graph[source][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;

    while(cin>>n)
    {
        if(n==0)break;

        int node;
        while(cin>>node)
        {
            if(node==0)break;

            int edge;
            while(cin>>edge)
            {
                if(edge==0)break;

                graph[node].push_back(edge);
            }
        }

        int query;
        cin>>query;

        while(query--)
        {
            int Node;
            cin>>Node;

            memset(visited,0,sizeof(visited));
            for(int i=1;i<=n;i++)inaccessible.insert(i);
            dfs(Node);

            cout<<inaccessible.size();
            for(auto it=inaccessible.begin();it!=inaccessible.end();it++)
            {
                cout<<" "<<*it;
            }
            cout<<endl;

            inaccessible.clear();
        }

        for(int i=0;i<105;i++)graph[i].clear();
    }
    return 0;
}
