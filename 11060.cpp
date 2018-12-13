#include<bits/stdc++.h>
#define CLR(a) memset(a, 0, sizeof(a))
using namespace std;

map<int,string> mp;
map<string,int> mps;

int n, take[110][110], indegree[110], taken[110];

void topsort()
{
    vector<int> task;
    int i, j, k;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(!indegree[j] && !taken[j])
            {
                taken[j] = 1;
                task.push_back(j);
                for(k=1; k<=n; k++)
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

    cout<<mp[task[0]];

    for(int i=1; i<n; i++)
    {
        cout<<" "<<mp[task[i]];
    }

    cout<<"."<<endl;

    task.clear();
}

int main()
{
    int cas=0;
    while(1)
    {
        cas++;
        int siz=0;
        int b,m,z=1;
        b=scanf("%d",&n);

        if(b==EOF) break;

        for(int i=1; i<=n; i++)
        {
            char str[100];
            scanf("%s",str);
            mp[z]=str;
            mps[str]=z;
            z++;
        }
        scanf("%d",&m);
        set<int> st;
        for(int i=1;i<=m;i++)
        {
            char str1[100];
            char str2[100];
            scanf("%s",str1);
            scanf("%s",str2);
            int num=mps[str1]*1000+mps[str2];
            st.insert(num);
            if(st.size()>siz)
            {
                siz++;
                take[mps[str1]][mps[str2]]=1;
                indegree[mps[str2]]++;
            }
        }
        cout<<"Case #"<<cas<<": Dilbert should drink beverages in this order: ";
        topsort();
        cout<<endl;
        CLR(take);
        CLR(indegree);
        CLR(taken);
        while(!mp.empty())
        {
            mp.erase(mp.begin());
        }
        while(!mps.empty())
        {
            mps.erase(mps.begin());
        }
    }
    return 0;
}

