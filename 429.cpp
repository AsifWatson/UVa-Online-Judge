#include "bits/stdc++.h"
using namespace std;

bool reachable_by_one_change(string s1,string s2)
{
    bool reachable=true;
    if(s1.size()!=s2.size())reachable=false;
    else
    {
        int not_match=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])not_match++;
        }
        if(not_match!=1)reachable=false;
    }
    return reachable;
}

void bfs(string src, string dest,map<string,vector<string> >graph)
{
	list<string>lst;
	map<string,bool>visited;
	map<string,int>dist;

	visited[src]=true;
	dist[src]=0;
	lst.push_back(src);

	while(!lst.empty())
    {
        bool pre_break=false;
		string u=lst.front();
		lst.pop_front();
		for(int i=0;i<graph[u].size();i++)
		{
			if(!visited[graph[u][i]])
			{
				visited[graph[u][i]]=true;
				dist[graph[u][i]]=dist[u]+1;

				lst.push_back(graph[u][i]);

				if(graph[u][i]==dest)
                {
                    cout<<dist[dest]<<endl;
                    pre_break=true;
                    break;
                }
			}
		}
		if(pre_break)break;
	}
}

int main()
{
    int n,space=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        vector<string>v;
        map<string,vector<string> >graph;
        string s;
        while(true)
        {
            cin>>s;
            if(s=="*")break;
            v.push_back(s);
        }
        for(int j=0;j<v.size()-1;j++)
        {
            for(int k=j+1;k<v.size();k++)
            {
                if(reachable_by_one_change(v[j],v[k]))
                {
                    graph[v[j]].push_back(v[k]);
                    graph[v[k]].push_back(v[j]);
                }
            }
        }
        if(space>1)cout<<endl;
        string start,finish,_string,hell;
        getline(cin,hell);
        while(getline(cin,_string) && _string!="")
        {
            stringstream strm(_string);
            strm>>start>>finish;
            cout<<start<<" "<<finish<<" ";
            bfs(start,finish,graph);
        }
        space++;
    }
    return 0;
}
