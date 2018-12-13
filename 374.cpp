#include<bits/stdc++.h>
using namespace std;

long long bigMod(long long number,long long power,long long mod)
{
    if(power==0) return 1;
    if(power%2==0)
    {
        long long ret=bigMod(number,power/2,mod);
        return ((ret%mod)*(ret%mod))%mod;
    }
    else return ((number%mod)*(bigMod(number,power-1,mod)%mod))%mod;
}

int main()
{
    long long number,power,mod;

    while(cin>>number>>power>>mod)
    {
        if(number<=10 && power<=10)
        {
            int sum=1;

            for(int i=1;i<=power;i++)
            {
                sum=sum*number;
            }

            cout<<sum%mod<<endl;

            continue;
        }
        cout<<bigMod(number,power,mod)<<endl;
    }

    return 0;
}
