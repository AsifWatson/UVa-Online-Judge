#include "bits/stdc++.h"
using namespace std;

bool isLeap(int year)
{
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

bool firstYearLeap(char month[],int date,int year)
{
    if(isLeap(year))
    {
        if(strcmp(month,"January")==0 || strcmp(month,"February")==0)return true;
        return false;
    }
    return false;
}

bool lastYearLeap(char month[],int date,int year)
{
    if(isLeap(year))
    {
        if(strcmp(month,"January")==0)return false;
        else if(strcmp(month,"February")==0)
        {
            if(date<29)return false;
            else return true;
        }
        return true;
    }
    return false;
}

int leapYear(int year1,int year2)
{
    int num=0;
    for(int i=year1;i<=year2;i++)
    {
        if(isLeap(i))num++;
    }
    return num;
}

int main()
{
    int tc,caseno=0;
    scanf("%d",&tc);
    while(tc--)
    {
        char month1[20],month2[20],ch1,ch2;
        int date1,year1,date2,year2,ans=0;

        scanf("%s",month1);
        scanf("%d%c%d",&date1,&ch1,&year1);

        scanf("%s",month2);
        scanf("%d%c%d",&date2,&ch2,&year2);

        if(!firstYearLeap(month1,date1,year1))year1++;
        if(!lastYearLeap(month2,date2,year2))year2--;


        if(year1<=year2)
        {
            int dif=year2-year1;
            if(dif<1600)ans=leapYear(year1,year2);
            else
            {
                int left_year1=year1;
                int left_year2=(((year1/400)+1)*400);
                ans+=leapYear(left_year1,left_year2);

                int right_year1=((year2/400)*400);
                int right_year2=year2;
                ans+=leapYear(right_year1+1,right_year2);

                ans+=(((right_year1-left_year2)/400)*97);
            }
        }

        printf("Case %d: %d\n",++caseno,ans);
    }
    return 0;
}
