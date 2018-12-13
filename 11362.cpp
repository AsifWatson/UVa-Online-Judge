#include<bits/stdc++.h>
#define N 200005
using namespace std;

int ch[N][10], ss=0, isWord[N];

void inl()
{
    memset(ch, 0, sizeof ch);
    memset(isWord, 0, sizeof isWord);
    ss=0;
}

bool insertt(string s)
{
    int u=0;
    for(int i=0; i<s.size(); i++)
    {
        int c=s[i]-'0';
        if(!ch[u][c])
        {
            ch[u][c]=++ss;
        }
        u=ch[u][c];
        if(isWord[u]==1)
        {
            return true;
        }
    }
    isWord[u]=1;
    return false;
}

/*bool searchh(string s)
{
    int u=0;
    for(int i=0; i<s.size()-1; i++)
    {
        int c=s[i]-'0';
        u=ch[u][c];
        if(isWord[u]==1)return true;
    }
    return false;
}*/


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        inl();
        int n,flag=0;
        cin>>n;
        set<string> sst;
        set<string> :: iterator it;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            sst.insert(s);
        }
        if(sst.size()<n)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(it=sst.begin();it!=sst.end();++it)
        {
            if(insertt(*it))
            {
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
