#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[35];
    while(scanf("%s",str)!=EOF)
    {
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='-')
            {
                cout<<"-";
            }
            else if(str[i]=='1')
            {
                cout<<"1";
            }
            else if(str[i]=='0')
            {
                cout<<"0";
            }
            else if(str[i]=='A' || str[i]=='B' || str[i]=='C')
            {
                cout<<"2";
            }
            else if(str[i]=='D' || str[i]=='E' || str[i]=='F')
            {
                cout<<"3";
            }
            else if(str[i]=='G' || str[i]=='H' || str[i]=='I')
            {
                cout<<"4";
            }
            else if(str[i]=='J' || str[i]=='K' || str[i]=='L')
            {
                cout<<"5";
            }
            else if(str[i]=='M' || str[i]=='N' || str[i]=='O')
            {
                cout<<"6";
            }
            else if(str[i]=='P' || str[i]=='Q' || str[i]=='R' || str[i]=='S')
            {
                cout<<"7";
            }
            else if(str[i]=='T' || str[i]=='U' || str[i]=='V')
            {
                cout<<"8";
            }
            else if(str[i]=='W' || str[i]=='X' || str[i]=='Y' || str[i]=='Z')
            {
                cout<<"9";
            }
        }
        cout<<endl;
    }
    return 0;
}
