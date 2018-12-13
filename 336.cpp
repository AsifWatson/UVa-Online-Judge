#include<bits/stdc++.h>
#define MAX 350
using namespace std;

map<int,int> m;
vector<int> adj[MAX];
int visited[MAX]={0};
int level[MAX];

void addEdge(int v,int e)
{
    adj[v].push_back(e);
    adj[e].push_back(v);
}

void bfs(int s)
{
    for(int i=0;i<MAX;i++)
    {
        visited[i]=0;
    }

    visited[s]=1;
    queue<int> q;
    q.push(s);
    level[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<adj[u].size();i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v=adj[u][i];
                visited[v]=1;
                level[v]=level[u]+1;
                q.push(v);
            }
        }
        q.pop();
    }
}

int check(int s,int ttl)
{
    int cou=0;

    for(int i=0;i<MAX;i++)
        visited[i]=0;

    visited[s]=1;
    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<adj[u].size();i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v=adj[u][i];
                if(level[v]<=ttl)
                {
                    cou++;
                }
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }
    return cou;
}

int main()
{
    int n,z,a,b,tot;
    static int r=1;
    while(scanf("%d",&n) && n)
    {
        int mapp[MAX];
        z=0;
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(m.empty())
            {
                mapp[z]=x;
                z++;
                m[x]=z;
                if(m.end() == m.find(y))
                {
                    mapp[z]=y;
                    z++;
                    m[y]=z;
                }

            }
            if(m.end() == m.find(x))
            {
                //pai nai;
                mapp[z]=x;
                z++;
                m[x]=z;
            }
            if(m.end() == m.find(y))
            {
                mapp[z]=y;
                z++;
                m[y]=z;
            }
            addEdge(m[x],m[y]);
        }
        while(scanf("%d %d",&a,&b))
        {
            int flag=0;
            if(a==0 && b==0)
                break;

            for(int i=0;i<MAX;i++)
            {
                if(mapp[i]==a)
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",r,z,a,b);
                r++;
                continue;
            }
            bfs(m[a]);
            tot=check(m[a],b);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",r,z-(tot+1),a,b);
            r++;
        }
        for(int i=0;i<MAX;i++)
        {
            adj[i].clear();
        }
        while(!m.empty())
        {
            m.clear();
        }
    }
    return 0;
}

