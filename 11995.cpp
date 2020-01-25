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
#define Sp(y)                 fixed<<setprecision(y)

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

int main()
{
    int n;

    while(scanf("%d", &n) != EOF)
    {
        stack<int> stk;
        queue<int> q;
        priority_queue<int> pq;

        int type[n + 5], value[n + 5];

        for(int i = 1; i <= n; ++i){
                scanf("%d %d", &type[i], &value[i]);
        }

        bool Stack = true, Queue = true, Pq = true;
        for(int i = 1; i <= n; ++i){
                if(type[i] == 1){
                        stk.push(value[i]);
                        q.push(value[i]);
                        pq.push(value[i]);
                }

                else if(type[i] == 2){
                        if(Stack == true){
                                if(stk.size()){
                                        if(value[i] == stk.top()) stk.pop();
                                        else Stack = false;
                                }
                                else Stack = false;
                        }
                        if(Queue == true){
                                if(q.size()){
                                        if(value[i] == q.front()) q.pop();
                                        else Queue = false;
                                }
                                else Queue = false;
                        }
                        if(Pq == true){
                                if(pq.size()){
                                        if(value[i] == pq.top()) pq.pop();
                                        else Pq = false;
                                }
                                else Pq = false;
                        }
                }
        }

        int totalTrue = 0;

        if(Stack == true) ++totalTrue;
        if(Queue == true) ++totalTrue;
        if(Pq == true) ++totalTrue;

        if(totalTrue == 0) printf("impossible\n");

        if(totalTrue == 1){
                if(Stack == true) printf("stack\n");
                if(Queue == true) printf("queue\n");
                if(Pq == true) printf("priority queue\n");
        }

        if(totalTrue > 1) printf("not sure\n");
    }

    return 0;
}
