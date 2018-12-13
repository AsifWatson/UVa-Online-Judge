#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> m;
    string s;
    int c=0;
    for(int i=1;i<=26;i++)
    {
        string s2="";
        char c1=96+i;
        s2=s2+c1;
        //cout<<s2<<endl;
        c++;
        m[s2]=c;
    }
    for(int i=1;i<=25;i++)
    {
        for(int j=i+1;j<=26;j++)
        {
            string s2="";
            char c1=96+i;
            char c2=96+j;
            s2=s2+c1+c2;
            //cout<<s2<<endl;
            c++;
            m[s2]=c;
        }
    }
    for(int i=1;i<=24;i++)
    {
        for(int j=i+1;j<=25;j++)
        {
            for(int k=j+1;k<=26;k++)
            {
                string s2="";
                char c1=96+i;
                char c2=96+j;
                char c3=96+k;
                s2=s2+c1+c2+c3;
                //cout<<s2<<endl;
                c++;
                m[s2]=c;
            }
        }
    }
    for(int i=1;i<=23;i++)
    {
        for(int j=i+1;j<=24;j++)
        {
            for(int k=j+1;k<=25;k++)
            {
                for(int l=k+1;l<=26;l++)
                {
                    string s2="";
                    char c1=96+i;
                    char c2=96+j;
                    char c3=96+k;
                    char c4=96+l;
                    s2=s2+c1+c2+c3+c4;
                    //cout<<s2<<endl;
                    c++;
                    m[s2]=c;
                }
            }
        }
    }
    for(int i=1;i<=22;i++)
    {
        for(int j=i+1;j<=23;j++)
        {
            for(int k=j+1;k<=24;k++)
            {
                for(int l=k+1;l<=25;l++)
                {
                    for(int n=l+1;n<=26;n++)
                    {
                        string s2="";
                        char c1=96+i;
                        char c2=96+j;
                        char c3=96+k;
                        char c4=96+l;
                        char c5=96+n;
                        s2=s2+c1+c2+c3+c4+c5;
                        //cout<<s2<<endl;
                        c++;
                        m[s2]=c;
                    }
                }
            }
        }
    }

    while(cin>>s)
    {
        if(m.end()==m.find(s))
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<m[s]<<endl;
        }
    }
    return 0;
}
