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

#define maxn 100005

struct data
{
    int MaxFreq, LeftElem, LeftFreq, RightElem, RightFreq;
    data(){}
    data(int a, int b, int c, int d, int e)
    {
        MaxFreq=a; LeftElem=b; LeftFreq=c; RightElem=d; RightFreq=e;
    }
};

int arr[maxn];
data tree[4*maxn];

data Merge(data A, data B)
{
    int a=max3(A.MaxFreq,B.MaxFreq,(A.RightElem==B.LeftElem)? A.RightFreq + B.LeftFreq : 0);
    int b=A.LeftElem;
    int c=(A.LeftElem==A.RightElem && A.RightElem==B.LeftElem) ? A.LeftFreq + B.LeftFreq : A.LeftFreq;
    int d=B.RightElem;
    int e=(B.LeftElem==B.RightElem && A.RightElem==B.LeftElem) ? A.RightFreq + B.RightFreq: B.RightFreq;

    return data(a,b,c,d,e);
}

void build(int node, int L, int R)
{
    if(L==R){tree[node]=data(1,arr[L],1,arr[R],1); return;}

    int leftNode=node*2;
    int rightNode=node*2+1;

    int mid=(L+R)/2;

    build(leftNode,L,mid);
    build(rightNode,mid+1,R);

    tree[node]=Merge(tree[leftNode],tree[rightNode]);
}

data query(int node, int L, int R, int l, int r)
{
    if(l>R || r<L)return data(0,0,0,0,0);
    if(L>=l && R<=r)return tree[node];

    int leftNode=node*2;
    int rightNode=node*2+1;

    int mid=(L+R)/2;

    data leftData = query(leftNode,L,mid,l,r);
    data rightData = query(rightNode,mid+1,R,l,r);

    if(leftData.MaxFreq==0)return rightData;
    if(rightData.MaxFreq==0)return leftData;
    return Merge(leftData,rightData);
}

int main()
{
    IOS

    int n,q;

    while(scanf("%d",&n) && n)
    {
        scanf("%d",&q);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
        }
        build(1,1,n);

        for(int i=1; i<=q; i++)
        {
            int L,R;
            scanf("%d %d",&L,&R);

            printf("%d\n", query(1,1,n,L,R).MaxFreq);
        }
    }

    return 0;
}
