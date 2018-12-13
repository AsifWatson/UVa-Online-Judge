#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[10000];
    char str1[10000];
    int ln,i,j;
    while(gets(str))
    {
        ln=strlen(str);
        j=0;
        for(i=0;i<ln;i++)
        {
            if(str[i]=='B')
                str1[j++]='V';

            if(str[i]=='C')
                str1[j++]='X';

            if(str[i]=='D')
                str1[j++]='S';

            if(str[i]=='E')
                str1[j++]='W';

            if(str[i]=='F')
                str1[j++]='D';

            if(str[i]=='G')
                str1[j++]='F';

            if(str[i]=='H')
                str1[j++]='G';

            if(str[i]=='I')
                str1[j++]='U';

            if(str[i]=='J')
                str1[j++]='H';

            if(str[i]=='K')
                str1[j++]='J';

            if(str[i]=='L')
                str1[j++]='K';

            if(str[i]=='M')
                str1[j++]='N';

            if(str[i]=='N')
                str1[j++]='B';

            if(str[i]=='O')
                str1[j++]='I';

            if(str[i]=='P')
                str1[j++]='O';

            if(str[i]=='R')
                str1[j++]='E';

            if(str[i]=='S')
                str1[j++]='A';

            if(str[i]=='T')
                str1[j++]='R';

            if(str[i]=='U')
                str1[j++]='Y';

            if(str[i]=='V')
                str1[j++]='C';

            if(str[i]=='W')
                str1[j++]='Q';

            if(str[i]=='X')
                str1[j++]='Z';

            if(str[i]=='Y')
                str1[j++]='T';

            if(str[i]=='[')
                str1[j++]='P';

            if(str[i]==']')
                str1[j++]='[';

            if(str[i]=='\\')
                str1[j++]=']';

            if(str[i]==';')
                str1[j++]='L';

            if(str[i]==',')
                str1[j++]='M';

            if(str[i]=='.')
                str1[j++]=',';

            if(str[i]=='/')
                str1[j++]='.';

            if(str[i]=='1')
                str1[j++]='`';

            if(str[i]=='2')
                str1[j++]='1';

            if(str[i]=='3')
                str1[j++]='2';

            if(str[i]=='4')
                str1[j++]='3';

            if(str[i]=='5')
                str1[j++]='4';

            if(str[i]=='6')
                str1[j++]='5';

            if(str[i]=='7')
                str1[j++]='6';

            if(str[i]=='8')
                str1[j++]='7';

            if(str[i]=='9')
                str1[j++]='8';

            if(str[i]=='0')
                str1[j++]='9';

            if(str[i]=='-')
                str1[j++]='0';

            if(str[i]=='=')
                str1[j++]='-';
            if(str[i]==' ')
                str1[j++]=' ';
            if(str[i]=='\'')
                str1[j++]=';';
        }
        for(i=0;i<j;i++)
        {
            printf("%c",str1[i]);
        }
        printf("\n");
    }
    return 0;
}
