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
    int t;
    cin >> t;

    while(t--)
    {
        int field, sg, sb;
        cin >> field >> sg >> sb;

        priority_queue<int> green, blue;

        for(int i = 1; i <= sg; ++i){
                int man;
                cin >> man;

                green.push(man);
        }

        for(int i = 1; i <= sb; ++i){
                int man;
                cin >> man;

                blue.push(man);
        }

        while(true)
        {
            vector<int> g, b;

            int gsize = green.size(), bsize = blue.size();

            for(int i = 1; i <= Min3(field, gsize, bsize); ++i){
                    g.push_back(green.top());
                    green.pop();

                    b.push_back(blue.top());
                    blue.pop();
            }

            for(int i = 0; i < g.size(); ++i){
                    if(g[i] > b[i]) green.push(g[i] - b[i]);
                    if(b[i] > g[i]) blue.push(b[i] - g[i]);
            }

            if(green.size() == 0 && blue.size() == 0){
                    cout << "green and blue died" << endl;

                    break;
            }

            if(green.size() == 0){
                    cout << "blue wins" << endl;

                    while(!blue.empty()){
                            cout << blue.top() << endl;
                            blue.pop();
                    }

                    break;
            }

            if(blue.size() == 0){
                    cout << "green wins" << endl;

                    while(!green.empty()){
                            cout << green.top() << endl;
                            green.pop();
                    }

                    break;
            }
        }

        if(t > 0) cout << endl;
    }

    return 0;
}
