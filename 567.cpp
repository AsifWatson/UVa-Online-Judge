#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100];
int visited[100]={0};
int level[100];


void bfs(int s)
{
    for(int i=0; i<100; i++)
    {
        visited[i]=0;
        level[i]=0;
    }

    queue<int>Q;
    Q.push(s);
    visited[s] = 1;
    level[s] = 0;

    while(!Q.empty())
    {
        int u = Q.front();

        for(int i=0; i<adj[u].size(); i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v = adj[u][i];
                level[v] = level[u]+1;
                visited[v] = 1;
                Q.push(v);
            }
        }
        Q.pop();
    }
}

int main()
{
    int ret,x,n,p,q,a;
    static int z=1;
    while(!cin.eof())
    {
        for(int i=1;i<20;i++)
        {
            ret=scanf("%d",&x);
            if(ret == EOF) return 0;

            if(x==0)
                continue;

            for(int j=1;j<=x;j++)
            {
                scanf("%d",&a);
                adj[i].push_back(a);
                adj[a].push_back(i);
            }
        }

        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&p,&q);
            bfs(p);
            if(i==1)
            {
                printf("Test Set #%d\n",z++);
            }
            printf("%2d to %2d: %d\n",p,q,level[q]-level[p]);
        }
        printf("\n");
        for(int i=0;i<100;i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}
