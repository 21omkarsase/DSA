//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<int>adj[],int s,int d,int n,int &ans){
        for(auto e:adj[s]){
            if(e==d)ans++;
            dfs(adj,e,d,n,ans);
        }
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	   if(n==1 || s==d )return 1;
	   vector<int> adj[n];
	   for(auto v:edges){
	       adj[v[0]].push_back(v[1]);
	   }
	   int ans=0;
	   dfs(adj,s,d,n,ans);
	   return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends