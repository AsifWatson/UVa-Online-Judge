#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define allre(v) v.rbegin(),v.rend()
#define sp(x,y) fixed<<setprecision(y)<<x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) ((a*b)/__gcd(a,b) )
using namespace std;

const double pi = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;

bool Reverse(long long a,long long b)
{
    return a>b;
}

void f(long long n)
{
    long long kuti,lakh,hajar,shata,last;
    last=n%100;
    n/=100;
    shata=n%10;
    n/=10;
    hajar=n%100;
    n/=100;
    lakh=n%100;
    n/=100;
    if(n){
        cout<<" "<<n<<" kuti";
    }
    if(lakh){
        cout<<" "<<lakh<<" lakh";
    }
    if(hajar) {
        cout<<" "<<hajar<<" hajar";
    }
    if(shata) {
        cout<<" "<<shata<<" shata";
    }
    if(last) {
        cout<<" "<<last;
    }
}

int main()
{
    long long n;
    int caseno=0;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%4d.",++caseno);
        if(!n)
        {
            cout<<" 0"<<endl;
            continue;
        }
        long long kuti,lakh,hajar,shata,last;
        last=n%100;
        n/=100;
        shata=n%10;
        n/=10;
        hajar=n%100;
        n/=100;
        lakh=n%100;
        n/=100;
        if(n)
        {
            f(n);
            cout<<" kuti";
        }
        if(lakh) cout<<" "<<lakh<<" lakh";
        if(hajar) cout<<" "<<hajar<<" hajar";
        if(shata) cout<<" "<<shata<<" shata";
        if(last) cout<<" "<<last;
        cout<<endl;
    }
    return 0;
}
