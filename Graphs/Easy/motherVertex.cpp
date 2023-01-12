//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    void dfs(vector<int>adj[],int vis[],int &cnt,int curr){
        vis[curr]=1;
        cnt++;
        for(auto e:adj[curr]){
            if(!vis[e]){
                dfs(adj,vis,cnt,e);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int cnt=0;
	    int vis[V]={0};
	    dfs(adj,vis,cnt,0);
	    if(cnt==V)return 0;
	    for(int i=0;i<V;i++){
    	    cnt=0;
	        if(!vis[i]){
	            dfs(adj,vis,cnt,i);
	        }
	        if(cnt==V)return i;
	    }
	    return -1;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends