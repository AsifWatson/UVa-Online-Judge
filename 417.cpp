#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[6];
    while(scanf("%s",str)!=EOF)
    {
        int len = strlen(str);
        int c,flag=0;
        if(len==1)
        {
            c=0;
            for(int i=1;i<=26;i++)
            {
                c++;

                if(str[0]-'a'+1==i)
                {
                    cout<<c<<endl;
                    flag=1;
                    break;
                }
            }
        }
        if(len==2)
        {
            c=26;
            for(int i=1;i<=25;i++)
            {
                for(int j=i+1;j<=26;j++)
                {
                    c++;
                    if(str[0]-'a'+1==i)
                    {
                        if(str[1]-'a'+1==j)
                        {
                            cout<<c<<endl;
                            flag=1;
                            break;
                        }
                    }
                }
            }
        }
        if(len==3)
        {
            c=351;
            for(int i=1;i<=24;i++)
            {
                for(int j=i+1;j<=25;j++)
                {
                    for(int k=j+1;k<=26;k++)
                    {
                        c++;
                        if(str[0]-'a'+1==i)
                        {
                            if(str[1]-'a'+1==j)
                            {
                                if(str[2]-'a'+1==k)
                                {
                                    cout<<c<<endl;
                                    flag=1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(len==4)
        {
            c=2951;
            for(int i=1;i<=23;i++)
            {
                for(int j=i+1;j<=24;j++)
                {
                    for(int k=j+1;k<=25;k++)
                    {
                        for(int l=k+1;l<=26;l++)
                        {
                            c++;
                            if(str[0]-'a'+1==i)
                            {
                                if(str[1]-'a'+1==j)
                                {
                                    if(str[2]-'a'+1==k)
                                    {
                                        if(str[3]-'a'+1==l)
                                        {
                                            cout<<c<<endl;
                                            flag=1;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(len==5)
        {
            c=17901;
            for(int i=1;i<=22;i++)
            {
                for(int j=i+1;j<=23;j++)
                {
                    for(int k=j+1;k<=24;k++)
                    {
                        for(int l=k+1;l<=25;l++)
                        {
                            for(int m=l+1;m<=26;m++)
                            {
                                c++;
                                if(str[0]-'a'+1==i)
                                {
                                    if(str[1]-'a'+1==j)
                                    {
                                        if(str[2]-'a'+1==k)
                                        {
                                            if(str[3]-'a'+1==l)
                                            {
                                                if(str[4]-'a'+1==m)
                                                {
                                                    cout<<c<<endl;
                                                    flag=1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(flag==0)
        {
            cout<<0<<endl;
        }
    }
    return 0;
}
