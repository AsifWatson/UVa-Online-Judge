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
    int Max;
    int Left_element, Left_element_occurance;
    int Right_element, Right_element_occurance;
};

int arr[maxn];
data tree[4*maxn];

data build(int node, int L, int R)
{
    if(L==R)
    {
        data temp;

        temp.Max=1;

        temp.Left_element=arr[L];
        temp.Left_element_occurance=1;

        temp.Right_element=arr[R];
        temp.Right_element_occurance=1;

        tree[node]=temp;

        return temp;
    }

    int leftNode=node*2;
    int rightNode=node*2+1;

    int mid=(L+R)/2;

    data leftData = build(leftNode,L,mid);
    data rightData = build(rightNode,mid+1,R);

    data Data;

    int element = 0;
    if(leftData.Right_element == rightData.Left_element)
    {
        element = leftData.Right_element_occurance + rightData.Left_element_occurance;
    }
    Data.Max = max3(leftData.Max, rightData.Max, element);

    Data.Left_element = leftData.Left_element;
    Data.Left_element_occurance = leftData.Left_element_occurance;
    if(leftData.Left_element == leftData.Right_element)
    {
        if(leftData.Right_element == rightData.Left_element)
        {
            Data.Left_element_occurance += rightData.Left_element_occurance;
        }
    }

    Data.Right_element = rightData.Right_element;
    Data.Right_element_occurance = rightData.Right_element_occurance;
    if(rightData.Left_element == rightData.Right_element)
    {
        if(leftData.Right_element == rightData.Left_element)
        {
            Data.Right_element_occurance += leftData.Right_element_occurance;
        }
    }

    tree[node] = Data;

    return Data;
}

data query(int node, int L, int R, int l, int r)
{
    if(l>R || r<L)
    {
        data temp;
        temp.Max=0;
        return temp;
    }
    if(L>=l && R<=r)return tree[node];

    int leftNode=node*2;
    int rightNode=node*2+1;

    int mid=(L+R)/2;

    data leftData = query(leftNode,L,mid,l,r);
    data rightData = query(rightNode,mid+1,R,l,r);

    if(leftData.Max==0)return rightData;
    if(rightData.Max==0)return leftData;

    data Data;

    int element=0;
    if(leftData.Right_element == rightData.Left_element)
    {
        element = leftData.Right_element_occurance + rightData.Left_element_occurance;
    }
    Data.Max=max3(leftData.Max, rightData.Max, element);

    Data.Left_element = leftData.Left_element;
    Data.Left_element_occurance = leftData.Left_element_occurance;
    if(leftData.Left_element == leftData.Right_element)
    {
        if(leftData.Right_element == rightData.Left_element)
        {
            Data.Left_element_occurance += rightData.Left_element_occurance;
        }
    }

    Data.Right_element = rightData.Right_element;
    Data.Right_element_occurance = rightData.Right_element_occurance;
    if(rightData.Left_element == rightData.Right_element)
    {
        if(leftData.Right_element == rightData.Left_element)
        {
            Data.Right_element_occurance += leftData.Right_element_occurance;
        }
    }

    return Data;
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

            data output = query(1,1,n,L,R);

            printf("%d\n", output.Max);
        }
    }

    return 0;
}
