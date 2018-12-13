#include<bits/stdc++.h>
#define MAX 210
using namespace std;

vector<int> adj[MAX];
int visited[MAX]={0};
int color[MAX];

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
        color[i]=0;
    }

    queue<int> q;
    q.push(s);
    visited[s]=1;
    color[s]=1;

    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<adj[u].size();i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v = adj[u][i];
                visited[v] = 1;

                if(color[u]==0)
                {
                    color[v]=1;
                }

                if(color[u]==1)
                {
                    color[v]=0;
                }

                q.push(v);
            }
        }
        q.pop();
    }
}

int biColor(int s)
{
    for(int i=0;i<MAX;i++)
        visited[i]=0;

    queue<int> q;
    q.push(s);
    visited[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(color[v]==color[u])
            {
                return 0;
            }
            if(visited[v]==0)
            {
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }
    return 1;
}

int main()
{
    int n,l,x,y,a;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&l);
        for(int i=0;i<l;i++)
        {
            scanf("%d %d",&x,&y);
            addEdge(x,y);
            if(i==0)
            {
                a=x;
            }
        }
        bfs(a);
        if(biColor(a))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");

        for(int i=0;i<MAX;i++)
        {
            adj[i].clear();
        }

    }
    return 0;
}

