//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool cycleDetection(vector<int>adj[],int vis[],int dfs[],int curr){
        vis[curr]=1;
        dfs[curr]=1;
        for(auto e : adj[curr]){
            if(!vis[e]){
                if(cycleDetection(adj,vis,dfs,e))return true;
            }else if(dfs[e])return true;
        }
        dfs[curr]=0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        int vis[n]={0};
        int dfs[n]={0};
        for(int i=0;i<n;i++){
            if(cycleDetection(adj,vis,dfs,i))return true;
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