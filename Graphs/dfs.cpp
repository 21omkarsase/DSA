#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],int vis[],int curr){
    cout<<curr<<" : ";
    vis[curr]=1;
    for(auto e:adj[curr]){
    	if(!vis[e]){
	    	dfs(adj,vis,e);
	    	vis[e]=1;
	    }
    }
}

int main(){
	int n,m,k;cin>>n>>m>>k;
	vector<int>adj[n+1];
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>ans;
	int vis[n+1]={0};

	dfs(adj,vis,k);


	return 0;
}

