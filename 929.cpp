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

template <class T> inline T gcd(T x,T y){if(y==0)return x; return gcd(y,x%y);}
template <class T> inline T lcm(T x,T y){return ((x/gcd(x,y))*y);}

bool Reverse(long long a,long long b){return a>b;}

bool compare(pair<long long,long long> a,pair<long long,long long> b)
{
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}

const int infinity=INT_MAX;
int row, col, grid[1005][1005], min_cost[1005][1005];
bool visited[1005][1005];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

struct data
{
    int Row,Col,Cost;
    data(){}
    data(int ROW, int COLUMN, int COST)
    {
        Row=ROW;
        Col=COLUMN;
        Cost=COST;
    }
    bool operator < (const data& p) const
    {
        return Cost > p.Cost;
    }
};

bool insideGrid(int r,int c)
{
    return ((r>=1 && r<=row) && (c>=1 && c<=col));
}

void dijkstra()
{
    priority_queue<data> pq;
    data Data;

    pq.push(data(1,1,grid[1][1]));
    min_cost[1][1]=grid[1][1];

    while(!pq.empty())
    {
        Data=pq.top();
        pq.pop();

        if(visited[Data.Row][Data.Col])continue;
        visited[Data.Row][Data.Col]=true;

        for(int i=0;i<4;i++)
        {
            int r=Data.Row+dx[i];
            int c=Data.Col+dy[i];

            if(insideGrid(r,c) && (min_cost[r][c] > min_cost[Data.Row][Data.Col]+grid[r][c]))
            {
                min_cost[r][c] = min_cost[Data.Row][Data.Col]+grid[r][c];
                pq.push(data(r,c,min_cost[r][c]));
            }
        }
    }

    cout<<min_cost[row][col]<<endl;
}

int main()
{
    IOS

    int t;
    cin>>t;

    while(t--)
    {
        cin>>row>>col;

        for(int i=1; i<=row; i++)
        {
            for(int j=1; j<=col; j++)
            {
                cin>>grid[i][j];
            }
        }

        for(int i=1; i<=row; i++)
        {
            for(int j=1; j<=col; j++)
            {
                visited[i][j]=false;
                min_cost[i][j]=infinity;
            }
        }

        dijkstra();
    }

    return 0;
}
