#include "bits/stdc++.h"
using namespace std;

map<string,long long>dimension;
map<string,long long>C;
vector<long long> Array[1000010];

int main()
{
    long long n,r,start=1;
    cin>>n>>r;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        long long B,Size_in_byte,D;
        cin>>B>>Size_in_byte>>D;
        dimension[s]=D;
        C[s]=start++;

        vector<pair<long long,long long> >v;
        Array[C[s]].push_back(Size_in_byte);

        long long current_C=Size_in_byte;
        for(int j=1;j<=D;j++)
        {
            long long U,L;
            cin>>U>>L;
            v.push_back({U,L});
        }

        long long Minus=0;

        for(int j=v.size()-1;j>=1;j--)
        {
            long long calc;
            calc=current_C*(v[j].second-v[j].first+1);
            Array[C[s]].push_back(calc);
            Minus+=(current_C*v[j].first);
            current_C=calc;
        }
        Minus+=(current_C*v[0].first);
        Array[C[s]].push_back(B-Minus);
        reverse(Array[C[s]].begin(),Array[C[s]].end());

    }
    for(int i=1;i<=r;i++)
    {
        string s;
        cin>>s;
        long long sum=Array[C[s]][0];
        long long arr[dimension[s]+1];
        for(int j=1;j<=dimension[s];j++)
        {
            cin>>arr[j];
            sum+=(Array[C[s]][j]*arr[j]);
        }
        cout<<s<<"["<<arr[1];
        for(int j=2;j<=dimension[s];j++)cout<<", "<<arr[j];
        cout<<"] = "<<sum<<endl;
    }
    return 0;
}
