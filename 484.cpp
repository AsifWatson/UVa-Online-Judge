#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;
int main()
{
    int n;
    char c;
    multiset<int> mlt;
    vector<int> v;
    while(scanf("%d%c",&n,&c)!=EOF)
    {
        mlt.insert(n);
        if(mp[n]==0)
        {
            mp[n]++;
            v.push_back(n);
        }
        if(c=='\n')
        {
            break;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" "<<mlt.count(v[i])<<endl;
    }
    return 0;
}
