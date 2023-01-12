#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,k;cin>>n>>m>>k;
	vector<int>adj[n+1];
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int>q;
	vector<bool>visited(n+1,0);
	q.push(k);
	
	// ********Time Complexity : o(N) + o(2E)
	while(!q.empty()){
		int size=q.size();
		for(int i=0;i<size;i++){
		    int node=q.front();
			q.pop();
			for(auto e:adj[node]){
				if(!visited[e]){
					visited[e]=1;
					q.push(e);
				}
			}
			visited[node]=1;
			cout<<node<<" : ";
		}
		cout<<"\n";
	}
	return 0;
}

