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
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define allre(v) v.rbegin(),v.rend()
#define sp(x,y) fixed<<setprecision(y)<<x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const double pi = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;

long long bigmod(long long b, long long p, long long m)
{
    if(p==0)return 1;
    if(p%2==0)
    {
        long long c = bigmod(b, p/2, m);
        return ((c%m)*(c%m))%m;
    }
    else return ((b%m)*(bigmod(b, p-1, m)))%m;
}

template <class T> inline T gcd(T x,T y){if(y==0)return x; return gcd(y,x%y);}
template <class T> inline T lcm(T x,T y){return ((x/gcd(x,y))*y);}

bool Reverse(long long a,long long b){return a>b;}

bool compare(pair<long long,long long> a,pair<long long,long long> b)
{
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}

int bsearch(long long v[],int n,long long chek)
{
    int low=0;
    int high=n-1;
    int R=-1;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(v[mid]==chek)
        {
             R=mid;
             high=mid-1;
        }
        else if(v[mid]>chek)high=mid-1;
        else low=mid+1;
    }
    return R;
}

int main()
{
    int n,q;
    int tc = 1;
    while(scanf("%d %d",&n,&q)==2)
    {
        if(n==0 && q==0)break;

        long long v[n+5];
        for(int i=0; i<n; i++)scanf("%lld",&v[i]);
        sort(v,v+n);

        printf("CASE# %d:\n",tc);

        for(int j=0; j<q; j++)
        {
            long long Q;
            scanf("%lld",&Q);
            int res=bsearch(v,n,Q);
            if(res==-1)printf("%lld not found\n",Q);
            else printf("%lld found at %d\n",Q,res+1);
        }
        tc++;
    }
    return 0;
}
