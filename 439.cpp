#include "bits/stdc++.h"
using namespace std;

int fx[]={1,-1,2,2,-2,-2,-1,1};
int fy[]={2,2,1,-1,1,-1,-2,-2};

int visited[1005][1005],dest[1005][1005],row=8,col=8;

void bfs(int x,int y)
{
    memset(visited,0,sizeof(visited));
    memset(dest,0,sizeof(dest));
    visited[x][y]=1;

    queue<pair<int,int> >q;
    q.push({x,y});

    while(!q.empty())
    {
        pair<int,int> top=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int tx=top.first+fx[i];
            int ty=top.second+fy[i];
            if(tx>=1 && tx<=row && ty>=1 && ty<=col && !visited[tx][ty])
            {
                visited[tx][ty]=1;
                dest[tx][ty]=dest[top.first][top.second]+1;
                q.push({tx,ty});
            }
        }
    }
}

int get_char(char ch){return ch-'a'+1;}
int get_num(char ch){return ch-'0';}

int main()
{
    char s1[3],s2[3];
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        int sx,sy,dx,dy;
        sx=get_char(s1[0]);
        sy=get_num(s1[1]);
        dx=get_char(s2[0]);
        dy=get_num(s2[1]);
        bfs(sx,sy);
        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<dest[dx][dy]<<" knight moves."<<endl;
    }
    return 0;
}
