/***********************************************************|
|          /\           /-------|   -----    |-----------|  |
|         /  \         /              |      |              |
|        /    \       |               |      |              |
|       /      \      |----|          |      |-------|      |
|      / ------ \          |-----|    |      |              |
|     /          \               |    |      |              |
|    /            \              /    |      |              |
|  ---            --- |---------/   -----  -----            |
|                                                           |
|   Codeforces = Asif_Watson  ||  Codechef = asif_watson    |
|   Mail = ashfaqislam33@gmail.com                          |
|   CSTE, Noakhali Science and Technology University(11)    |
|                                                           |
************************************************************/

#include "bits/stdc++.h"
#define all(v) v.begin(),v.end()
#define allre(v) v.rbegin(),v.rend()
#define sp(x,y) fixed<<setprecision(y)<<x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) ((a*b)/__gcd(a,b))

using namespace std;

const double pi = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;

bool Reverse(long long a,long long b){return a>b;}

bool compare(pair<long long,long long> a,pair<long long,long long> b)
{
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}

bool isVowel(char ch)
{
    return (ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int l,n;
    cin>>l>>n;

    map<string,string> mp;
    while(l--)
    {
        string s1,s2;
        cin>>s1>>s2;

        mp[s1]=s2;
    }

    while(n--)
    {
        string s;
        cin>>s;

        if(mp.find(s)!=mp.end())cout<<mp[s]<<endl;
        else if(s[s.size()-1] == 'y' && !isVowel(s[s.size()-2]))
        {
            for(int i=0;i<s.size()-1;i++)cout<<s[i];
            cout<<"ies"<<endl;
        }
        else if(s[s.size()-1]== 'o' ||
                s[s.size()-1]== 's' ||
                s[s.size()-1]== 'x' ||
                ((s[s.size()-1]== 'h') && (s[s.size()-2]== 'c' || (s[s.size()-2]== 's')))
                )
        {
            s+="es";
            cout<<s<<endl;
        }
        else cout<<s<<"s"<<endl;
    }

    return 0;
}

