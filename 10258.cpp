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

struct score
{
    int solved, penalty, id;
};

bool Compare(score a, score b)
{
    if(a.solved == b.solved){
            if(a.penalty == b.penalty){
                    return a.id < b.id;
            }
            return a.penalty < b.penalty;
    }
    return a.solved > b.solved;
}

int main()
{
    IOS

    int t;
    cin >> t;

    string s;

    getline(cin, s);
    getline(cin, s);

    while(t--)
    {
        int solveTime[105][12];
        int status[105][12];
        int submission[105];

        for(int i = 1; i <= 100; ++i){
                submission[i] = 0;

                for(int j = 1; j <= 9; ++j){
                        solveTime[i][j] = 0;
                        status[i][j] = 0;
                }
        }

        while(getline(cin, s), s.size() > 0){
                int contestant, problem, time;
                char verdict;

                stringstream ss(s);
                ss >> contestant >> problem >> time >> verdict;

                submission[contestant] = 1;

                if(verdict == 'C' && status[contestant][problem] == 0){
                        status[contestant][problem] = 1;
                        solveTime[contestant][problem] += time;
                }
                if(verdict == 'I' && status[contestant][problem] == 0){
                        solveTime[contestant][problem] += 20;
                }
	    }

        int totalSolved[105];
        int totalPenalty[105];

        vector<score> v;

        for(int i = 1; i <= 100; ++i){
                totalSolved[i] = 0;
                totalPenalty[i] = 0;

                if(submission[i] == 1){
                        for(int j = 1; j <= 9; ++j){
                                if(status[i][j] == 1){
                                        ++totalSolved[i];
                                        totalPenalty[i] += solveTime[i][j];
                                }
                        }

                        score temp;

                        temp.solved = totalSolved[i];
                        temp.penalty = totalPenalty[i];
                        temp.id = i;

                        v.push_back(temp);
                }

        }

        sort(All(v), Compare);

        for(int i = 0; i < v.size(); ++i){
                cout << v[i].id << " " << v[i].solved << " " << v[i].penalty << endl;
         }

         if(t > 0) cout << endl;

    }

    return 0;
}
