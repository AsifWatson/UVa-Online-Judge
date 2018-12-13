#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        if(n==1)
        {
            cout<<"Discarded cards:"<<endl<<"Remaining card: 1"<<endl;
            continue;
        }
        queue<int> myQ;
        int arr[60];
        int j=0;

        for(int i=1;i<=n;i++)
        {
            myQ.push(i);
        }
        while(myQ.size()>1)
        {
            arr[j++]=myQ.front();
            myQ.pop();
            int b=myQ.front();
            myQ.pop();
            myQ.push(b);
        }
        cout<<"Discarded cards: "<<arr[0];
        for(int i=1;i<j;i++)
        {
            cout<<", "<<arr[i];
        }
        cout<<endl<<"Remaining card: "<<myQ.front()<<endl;
    }
    return 0;
}
