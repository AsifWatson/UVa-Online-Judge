#include <bits/stdc++.h>
#define MAX 30
using namespace std;

vector<int> adj[MAX];
int seen[MAX];

void dfs(int u)
{
    seen[u]=1;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(seen[v]==0)
        {
            dfs(v);
        }
    }
}

int main()
{
    int t,a,b,Case=0,k;
    char s[5];
    string str;
    scanf("%d",&t);
    k=t;
    getchar();
    while(t--){
        scanf("%s",s);
        int ans=s[0]-'A';
        getchar();
        while(getline(cin,str)){
            if(str.length()==0){
                break;
            }
            a=str[0]-'A';
            b=str[1]-'A';
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<MAX;i++){
            seen[i]=0;
        }
        int cou=0;
        for(int i=0;i<=ans;i++){
            if(seen[i]==0){
                cou++;
                dfs(i);
            }
        }
        for(int i=0;i<MAX;i++){
            adj[i].clear();
        }
        cout<<cou<<endl;
        ++Case;
        if(Case<k){
           cout<<endl;
        }
    }
    return 0;
}
