#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[1000];
    int t,i;
    stack<char> myStack;
    scanf("%d",&t);
    getchar();
    for(int j=1;j<=t;j++)
    {
        gets(str);
        if(str[0]==' '){
            continue;
        }
        for(int i=0; str[i]; i++)
        {
            if(!myStack.empty() && myStack.top()=='(' && str[i]==')')
                myStack.pop();
            else if(!myStack.empty() && myStack.top()=='[' && str[i]==']')
                myStack.pop();
            else
                myStack.push(str[i]);
        }

        if(!myStack.empty()){
            printf("No\n");
            while(!myStack.empty()){
                myStack.pop();
            }
        }
        else
            printf("Yes\n");
    }

    return 0;
}

