#include<bits/stdc++.h>
using namespace std;

void generateUndirectedGraph(){
	// ***********For Unidirected***********
	int n,m;
	cin>>n>>m;
	bool adj[n+1][m+1]={0};
	for(int i=0;i<m;i++){
		int u,v;
		cin>>v>>u;
		adj[u][v]=1;
		adj[v][u]=1;
		//for weighted graph adj[u][v]=wt;
						   //adj[v][u]=wt;
	}
    cout<<"**********Undirected Graph**************\n";
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void generateDirectedGraph(){
	int n,m;cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		//for directed graph use array of type vector<pair<int,int>>
		//adj[u].push_back({v,wt})
		//adj[v].push_back({u,wt})
	}
	cout<<"**********Directed Graph**************\n";
	for(int i=1;i<n+1;i++){
		cout<<i<<" --> ";
		vector<int>v=adj[i];
		for(auto e:v)
			cout<<e<<" : ";
		cout<<"\n";
	}
}

int main(){
	// generateUndirectedGraph();
	generateDirectedGraph();
	return 0;
}