#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,q,r,s,t,u;
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        double lo=0,hi=1,mid,ans0,ans1;
        int num=64,cou=0;
        ans0=p*(exp(-0))+r*cos(0)+u + q*sin(0)+s*tan(0)+t*0*0;
        ans1=p*(exp(-1))+r*cos(1)+u + q*sin(1)+s*tan(1)+t*1*1;
        //cout<<ans1<<" "<<ans0<<endl;
        if((ans0>0 && ans1>0)|| (ans0<0 && ans1<0))
        {
            cout<<"No solution"<<endl;
            continue;
        }
        while(num--)
        {
            mid=(lo+hi)/2;
            if((p*(exp(-mid))+r*cos(mid)+u + q*sin(mid)+s*tan(mid)+t*mid*mid)>0)
            {
                lo=mid;
            }
            else
            {
                hi=mid;
            }
        }
        cout<<fixed<<setprecision(4)<<mid<<endl;
    }
    return 0;
}
