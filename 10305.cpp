#include<bits/stdc++.h>
#define CLR(a) memset(a,0,sizeof(a))
using namespace std;


int n,take[110][110],taken[110],indegree[110];

void topsort()
{
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!taken[j] && !indegree[j])
            {
                taken[j]=1;
                v.push_back(j);
                for(int k=1;k<=n;k++)
                {
                    if(take[j][k])
                    {
                        --indegree[k];
                    }
                }
                break;
            }
        }
    }
    cout<<v[0];
    for(int i=1;i<n;i++)
    {
        cout<<" "<<v[i];
    }
    cout<<endl;
}

int main()
{
    int m,a,b;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
        {
            break;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            take[a][b]=1;
            indegree[b]++;
        }
        topsort();
        CLR(take);
        CLR(taken);
        CLR(indegree);
    }
    return 0;
}
