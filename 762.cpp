#include <bits/stdc++.h>
using namespace std;

map<string,int>mp1;
map<int,string>mp2;

bool BFS(vector<int> graph[],int src, int dest, int v,int pred[], int dist[])
{
	list<int> lst;
	bool visited[v];

	for(int i=0;i<v;i++){visited[i]=false;dist[i]=INT_MAX;pred[i]=-1;}

	visited[src]=true;dist[src]=0;lst.push_back(src);

	while(!lst.empty())
    {
		int u=lst.front();
		lst.pop_front();
		for(int i=0;i<graph[u].size();i++)
		{
			if(!visited[graph[u][i]])
			{
				visited[graph[u][i]]=true;
				dist[graph[u][i]]=dist[u]+1;
				pred[graph[u][i]]=u;

				lst.push_back(graph[u][i]);

				if(graph[u][i]==dest)
				return true;
			}
		}
	}
	return false;
}

void printShortestDistance(vector<int> graph[],int s,int dest, int v)
{
	int pred[v],dist[v];

	if(BFS(graph,s,dest,v,pred,dist)==false){cout<<"No route"<<endl;return;}

	vector<pair<int,int> >path;

	int crawl=dest;
	while(pred[crawl]!=-1)
    {
		path.push_back({pred[crawl],crawl});
		crawl=pred[crawl];
	}
	for(int i=path.size()-1;i>=0;i--)cout<<mp2[path[i].first]<<" "<<mp2[path[i].second]<<endl;
}

int main()
{
    int t,space=1;
    while(cin>>t)
    {
        vector<int> graph[100000];
        int visited[100000],v;

        int index1=-1,index2=-1;

        for(int i=1;i<=t;i++)
        {
            string a,b;
            cin>>a>>b;
            if(mp1.find(a)==mp1.end()){mp1[a]=++index1;mp2[++index2]=a;}
            if(mp1.find(b)==mp1.end()){mp1[b]=++index1;mp2[++index2]=b;}
            graph[mp1[a]].push_back(mp1[b]);
            graph[mp1[b]].push_back(mp1[a]);
        }
        string source,dest;
        cin>>source>>dest;
        v=index1+1;
        if(space>1)cout<<endl;
        if(mp1.find(source)==mp1.end()){cout<<"No route"<<endl;}
        else if(mp1.find(dest)==mp1.end()){cout<<"No route"<<endl;}
        else printShortestDistance(graph,mp1[source],mp1[dest],v);
        space++;
        mp1.clear();
        mp2.clear();
    }
    return 0;
}
