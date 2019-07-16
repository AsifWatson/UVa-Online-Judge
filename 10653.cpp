#include "bits/stdc++.h"
using namespace std;

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

int visited[1005][1005],grid[1005][1005],dest[1005][1005],row,col;

void bfs(int x,int y)
{
    visited[x][y]=1;

    queue<pair<int,int> >q;
    q.push({x,y});

    while(!q.empty())
    {
        pair<int,int> top=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=top.first+fx[i];
            int ty=top.second+fy[i];
            if(tx>=0 && tx<row && ty>=0 && ty<col && grid[tx][ty]!=-1 && !visited[tx][ty])
            {
                visited[tx][ty]=1;
                dest[tx][ty]=dest[top.first][top.second]+1;
                q.push({tx,ty});
            }
        }
    }
}

int main()
{
    while(scanf("%d %d",&row,&col))
    {
        if(!row && !col)return 0;

        memset(grid,0,sizeof(grid));
        memset(visited,0,sizeof(visited));
        memset(dest,0,sizeof(dest));

        int mine_loop;
        cin>>mine_loop;
        for(int i=1;i<=mine_loop;i++)
        {
            int mine_row,row_loop;
            cin>>mine_row>>row_loop;
            for(int j=1;j<=row_loop;j++)
            {
                int mine_col;
                cin>>mine_col;
                grid[mine_row][mine_col]=-1;
            }
        }
        int sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        bfs(sx,sy);
        cout<<dest[dx][dy]<<endl;
    }
    return 0;
}
