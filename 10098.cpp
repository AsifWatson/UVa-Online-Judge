#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        sort (s.begin(),s.end());
        int n=s.size();
        do
        {
            for(int i=0; i<n; i++)
            {
                cout <<s[i];
            }
            cout<<endl;
        }
        while (next_permutation(s.begin(),s.end()));
        cout<<endl;
    }
    return 0;
}

