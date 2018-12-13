#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,d1,d2,m1,m2,y1,y2,c1,c2,c3,c4,i,j,day1,day2,year;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%c%d%c%d",&d1,&c1,&m1,&c2,&y1);
        scanf("%d%c%d%c%d",&d2,&c3,&m2,&c4,&y2);
        day1=(y1*365)+(m1*30)+d1;
        day2=(y2*365)+(m2*30)+d2;
        year=(day1-day2)/365;
        if(day1-day2<0)
        {
            printf("Case #%d: Invalid birth date\n",i);
            continue;
        }
        if(year>=0 && year<=130)
            printf("Case #%d: %d\n",i,year);
        if(year>130)
            printf("Case #%d: Check birth date\n",i);
    }
    return 0;
}
