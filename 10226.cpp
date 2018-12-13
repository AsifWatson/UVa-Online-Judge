#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string input;
    cin>>t;
    getline(cin, input);
	getline(cin, input);
    map<string,int> m;
    vector<string> v;
    while(t--)
    {
        m.clear();
        v.clear();
        int n=0;
        while(getline(cin, input))
        {
            if(input=="")
            {
                break;
            }
            if(!m[input])
            {
                m[input]=1;
                v.push_back(input);
            }
            else
            {
                m[input]++;
            }
            n++;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i];
            printf(" %.4lf\n",m[v[i]]*100/(double)n);
        }
        if(t>0)
            cout<<endl;
    }
    return 0;
}
