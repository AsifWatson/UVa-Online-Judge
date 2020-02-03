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
    int c;
    cin >> c;

    while(c--)
    {
        int capacity, crossingTime, m;
        cin >> capacity >> crossingTime >> m;

        queue<pair<int, int> > left, right;
        vector<pair<int, int> > ans;

        for(int i = 1; i <= m; ++i){
                int arrival;
                string dir;

                cin >> arrival >> dir;

                if(dir == "left") left.push({i, arrival});
                if(dir == "right") right.push({i, arrival});
        }

        int curTime = 0;
        string pos = "left";

        while(true)
        {
            if(pos == "left"){
                    if(left.size() == 0 && right.size() == 0)
                            break;

                    if(left.size() == 0 && right.size() > 0){
                            pos = "right";

                            if(curTime < right.front().second)
                                    curTime = right.front().second;

                            curTime += crossingTime;

                            continue;
                    }

                    if(left.size() > 0 && right.size() == 0){
                            if(curTime < left.front().second)
                                    curTime = left.front().second;

                            for(int i = 1; i <= capacity; ++i){
                                    if(left.size() == 0) break;

                                    if(left.front().second > curTime) break;

                                    ans.push_back({left.front().first, curTime + crossingTime});
                                    left.pop();
                            }

                            curTime += crossingTime;
                            pos = "right";

                            continue;
                    }

                    if(left.size() > 0 && right.size() > 0){
                            if(curTime >= left.front().second){
                                    for(int i = 1; i <= capacity; ++i){
                                            if(left.size() == 0) break;

                                            if(left.front().second > curTime) break;

                                            ans.push_back({left.front().first, curTime + crossingTime});
                                            left.pop();
                                    }
                            }
                            else{
                                    if(left.front().second <= right.front().second){
                                            if(curTime < left.front().second)
                                                    curTime = left.front().second;

                                            for(int i = 1; i <= capacity; ++i){
                                                    if(left.size() == 0) break;

                                                    if(left.front().second > curTime) break;

                                                    ans.push_back({left.front().first, curTime + crossingTime});
                                                    left.pop();
                                            }
                                    }
                                    else{
                                            if(curTime < right.front().second)
                                                    curTime = right.front().second;
                                    }
                            }

                            curTime += crossingTime;
                            pos = "right";
                    }
            }
            else if(pos == "right"){
                    if(left.size() == 0 && right.size() == 0)
                            break;

                    if(left.size() > 0 && right.size() == 0){
                            pos = "left";

                            if(curTime < left.front().second)
                                    curTime = left.front().second;

                            curTime += crossingTime;

                            continue;
                    }

                    if(left.size() == 0 && right.size() > 0){
                            if(curTime < right.front().second)
                                    curTime = right.front().second;

                            for(int i = 1; i <= capacity; ++i){
                                    if(right.size() == 0) break;

                                    if(right.front().second > curTime) break;

                                    ans.push_back({right.front().first, curTime + crossingTime});
                                    right.pop();
                            }

                            curTime += crossingTime;
                            pos = "left";

                            continue;
                    }

                    if(left.size() > 0 && right.size() > 0){
                            if(curTime >= right.front().second){
                                    for(int i = 1; i <= capacity; ++i){
                                                    if(right.size() == 0) break;

                                                    if(right.front().second > curTime) break;

                                                    ans.push_back({right.front().first, curTime + crossingTime});
                                                    right.pop();
                                            }
                            }
                            else{
                                    if(right.front().second <= left.front().second){
                                            if(curTime < right.front().second)
                                                    curTime = right.front().second;

                                            for(int i = 1; i <= capacity; ++i){
                                                    if(right.size() == 0) break;

                                                    if(right.front().second > curTime) break;

                                                    ans.push_back({right.front().first, curTime + crossingTime});
                                                    right.pop();
                                            }
                                    }
                                    else{
                                            if(curTime < left.front().second)
                                                    curTime = left.front().second;
                                    }
                            }

                            curTime += crossingTime;
                            pos = "left";
                    }
            }
        }

        sort(All(ans));

        for(pair<int, int> p : ans)
                cout << p.second << endl;

        if(c > 0) cout << endl;
    }

    return 0;
}
