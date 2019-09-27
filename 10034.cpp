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

int parent[105];

int Find(int r)
{
    if(parent[r]==r)return r;
    return parent[r]=Find(parent[r]);
}

void initPar(int n)
{
    for(int i=0 ; i<n ; i++)parent[i]=i;
}

struct data
{
    int u,v;
    double w;
    bool operator < (const data &p) const
    {
        return w < p.w;
    }
};

double kruskal(int n, vector<data> graph, double mstValue=0.0)
{
    sort(all(graph));
    initPar(n);

    for(int i=0; i<graph.size(); i++)
    {
        int uPr=Find(graph[i].u);
        int vPr=Find(graph[i].v);

        if(uPr!=vPr)
        {
            parent[uPr]=vPr;
            mstValue+=graph[i].w;
        }
    }
    return mstValue;
}

/*
2
3
1.0 1.0
2.0 4.0
2.0 2.0
3
1.0 1.0
2.0 4.0
2.0 2.0
*/

int main()
{
    IOS

    int t,line=1;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);

        double dist[n][2];

        for(int i=0; i<n; i++)
        {
            scanf("%lf %lf",&dist[i][0],&dist[i][1]);
        }

        vector<data> graph;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                data input;
                input.u=i;
                input.v=j;
                input.w=sqrt(pow((dist[i][0]-dist[j][0]),2)+pow((dist[i][1]-dist[j][1]),2));
                graph.push_back(input);
            }
        }

        if(line>1)cout<<endl;
        cout<<fixed<<setprecision(2)<<kruskal(n,graph)<<endl;
        line++;
    }

    return 0;
}
