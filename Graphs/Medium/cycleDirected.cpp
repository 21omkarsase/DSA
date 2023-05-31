//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis, int node){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfs(adj, vis, pathVis, adjNode))
                    return true;
            }else if(pathVis[adjNode]){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int n, vector<int> adj[]) {
        vector<bool> vis(n, 0), pathVis(n, 0);
        
        for(int i = 0; i  < n; i++){
            if(dfs(adj, vis, pathVis, i)){
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends