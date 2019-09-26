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

int bfs(int s, vector<int> graph[])
{
    int visited[105],level[105];

    for(int i=0;i<105;i++)
    {
        visited[i]=0;
        level[i]=0;
    }

    queue<int>q;
    q.push(s);
    visited[s]=1;
    level[s]=0;

    while(!q.empty())
    {
        int u=q.front();

        for(int i=0;i<graph[u].size();i++)
        {
            if(!visited[graph[u][i]])
            {
                int v=graph[u][i];
                level[v]=level[u]+1;
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }

    int cost=0;
    for(int i=1; i<=100; i++)
    {
        cost+=level[i];
    }

    return cost;
}

int main()
{
    IOS

    int a,b,cs=1;

    while(scanf("%d %d",&a,&b))
    {
        if(a==0 && b==0)break;

        vector<int> graph[105];
        set<int> st;

        graph[a].push_back(b);

        st.insert(a);
        st.insert(b);

        int u,v;
        while(scanf("%d %d",&u,&v))
        {
            if(u==0 && v==0)break;
            graph[u].push_back(v);

            st.insert(u);
            st.insert(v);
        }

        int total_cost=0;
        for(auto it : st)
        {
            total_cost+=bfs(it,graph);
        }

        int possible_paths=st.size()*(st.size()-1);
        double avg_cost=(double)total_cost/(double)possible_paths;

        cout<<"Case "<<cs++<<": average length between pages = ";
        cout<<fixed<<setprecision(3)<<avg_cost<<" clicks"<<endl;
    }

    return 0;
}
