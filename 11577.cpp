#include "bits/stdc++.h"
using namespace std;

int main()
{
    int test_case;
    scanf("%d",&test_case);
    string hell;
    getline(cin,hell);
    while(test_case--)
    {
        map<char,int>mp;
        string s;
        getline(cin,s);
        int mx=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=65 && s[i]<=90)s[i]+=32;
            if(s[i]>=97 && s[i]<=122)
            {
                mp[s[i]]++;
                mx=max(mx,mp[s[i]]);
            }
        }
        for(int i=97;i<=122;i++)
        {
            char ch=i;
            if(mp[ch]==mx)cout<<ch;
        }
        cout<<endl;
    }
    return 0;
}
