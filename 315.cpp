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

#define maxn 105

vector<int> graph[maxn];
set<int> points;

int parent[maxn], discoverTime[maxn], lowestTime[maxn], counter;
bool visited[maxn];

void init()
{
    counter=0;
    for(int i=0; i<maxn; i++)
    {
        parent[i]=-1;
        discoverTime[i]=lowestTime[i]=0;
        visited[i]=false;
        graph[i].clear();
    }
    points.clear();
}

void dfs(int rootNode)
{
    visited[rootNode]=true;
    discoverTime[rootNode]=lowestTime[rootNode]=++counter;

    int child=0;

    for(int i=0; i<graph[rootNode].size(); i++)
    {
        int thisNode=graph[rootNode][i];

        if(!visited[thisNode])
        {
            child++;
            parent[thisNode]=rootNode;

            dfs(thisNode);

            if(parent[rootNode]!=-1 && lowestTime[thisNode]>=discoverTime[rootNode])points.insert(rootNode);

            lowestTime[rootNode]=min(lowestTime[rootNode],lowestTime[thisNode]);
        }

        if(visited[thisNode] && thisNode!=parent[rootNode])  // checks for back edge
        {
            lowestTime[rootNode]=min(lowestTime[rootNode],discoverTime[thisNode]);
        }
    }

    if(parent[rootNode]==-1 && child>1)points.insert(rootNode);
}

void showPoints()
{
    cout<<points.size()<<endl;
    //for(auto point : points)cout<<point<<" ";
    //cout<<endl;
}

void showGraph(int n)
{
    for(int i=1; i<=n; i++)
    {
        cout<<i<<"->";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    //freopen("in.txt", "rt", stdin);
    //freopen("out.txt", "wt", stdout);
    IOS

    int n;
    while(cin>>n , n!=0)
    {
        init();
        string s;
        while(getline(cin,s) && s!="0")
        {
            stringstream ss(s);
            int u,v;
            ss>>u;
            while(ss>>v)
            {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        //showGraph(n);
        //cout<<endl;
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])dfs(i);
        }
        showPoints();
        //cout<<endl;
    }

    return 0;
}
