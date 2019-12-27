/*****************************************************************|
|             /\         _______   ________   _________           |
|            /  \       /------ \ |___  ___| |  _______|          |
|           / /\ \      ||            ||     | |                  |
|          / /  \ \     ||______      ||     | |______            |
|         / /____\ \    \ ----- \     ||     |  ______|           |
|        / /------\ \          ||     ||     | |                  |
|       / /        \ \   ______||  ___||___  | |                  |
|      |_/          \_| \ ------/ |________| |_|                  |
|                                                                 |
|                                                                 |
|      Codeforces = Asif_Watson                                   |
|      Codechef   = asif_watson                                   |
|      UVa        = Asif_Watson                                   |
|      Mail       = ashfaqislam33@gmail.com                       |
|      CSTE, Noakhali Science and Technology University (11)      |
|                                                                 |
******************************************************************/

#include "bits/stdc++.h"
using namespace std;

#define IOS                   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Iterate(st,it)        for(auto it=st.begin();it!=st.end();it++)
#define Iteratere(st,it)      for(auto it=st.rbegin();it!=st.rend();it++)

#define All(v)                v.begin(),v.end()
#define Allre(v)              v.rbegin(),v.rend()
#define Unique(v)             sort(All(v)),v.erase(unique(All(v)),v.end())
#define Mem(Array,Value,Size) for(int i=0;i<Size;i++)Array[i]=Value
#define Sp(x,y)               fixed<<setprecision(y)<<x

#define Max3(a,b,c)           max(a,max(b,c))
#define Max(v)                *max_element(All(v))
#define Min3(a,b,c)           min(a,min(b,c))
#define Min(v)                *min_element(All(v))

typedef long long i64;

const double Pi = acos(-1.0);
const double Eps = 1e-6;
const int Mod = (int)1e9+7;

i64 Bigmod(i64 b, i64 p, i64 m)
{
    if(p==0)return 1LL;
    if(p%2==0)
    {
        i64 c = Bigmod(b, p/2, m);
        return ((c%m)*(c%m))%m;
    }
    else return ((b%m)*(Bigmod(b, p-1, m)))%m;
}

i64 ModInverse(i64 a, i64 M){return Bigmod(a, M-2, M);}  /// M is prime

template <class T> inline T GCD(T x,T y){if(y==0)return x; return GCD(y,x%y);}
template <class T> inline T LCM(T x,T y){return ((x/GCD(x,y))*y);}

bool Reverse(i64 a, i64 b){return a > b;}

bool Compare(pair<i64,i64> a, pair<i64,i64> b)
{
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

const int MX = 20;
int queen[MX], rows[MX], diagonal1[MX + MX], diagonal2[MX + MX];
int totalSolution, r, c;

void nqueen(int col, int n)
{
    if(col == c) ++col;

    if(col == n + 1)
    {
        printf("%2d      ", ++totalSolution);

        for(int i = 1; i <= n; i++)
        {
            if(i > 1) printf(" ");
            printf("%d", queen[i]);
        }
        printf("\n");

        return;
    }

    for(int row = 1; row <= n; ++row)
    {
        if(rows[row] || diagonal1[row + col] || diagonal2[n + row - col]) continue;

        queen[col] = row;

        rows[row] = 1;
        diagonal1[row + col] = 1;
        diagonal2[n + row - col] = 1;

        nqueen(col + 1, n);

        rows[row] = 0;
        diagonal1[row + col] = 0;
        diagonal2[n + row - col] = 0;
    }
}

void init()
{
    Mem(queen, 0, MX);
    Mem(rows, 0, MX);
    Mem(diagonal1, 0, MX);
    Mem(diagonal2, 0, MX);

    totalSolution = 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        scanf("%d %d", &r, &c);

        queen[c] = r;

        rows[r] = 1;
        diagonal1[r + c] = 1;
        diagonal2[8 + r - c] = 1;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        nqueen(1, 8);

        if(n > 0) printf("\n");

        init();
    }

    return 0;
}
