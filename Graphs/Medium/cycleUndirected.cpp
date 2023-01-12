//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool detectCycle(vector<int> adj[],int vis[],int curr,int parent){
        vis[curr]=1;
        for(auto e : adj[curr]){
            if(!vis[e]){
                if(detectCycle(adj,vis,e,curr))return true;
            }else if(e!=parent)return true;
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        int vis[n]={0};
        for(int i=0;i<n;i++){
            if(!vis[i])
               if(detectCycle(adj,vis,i,-1))return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends