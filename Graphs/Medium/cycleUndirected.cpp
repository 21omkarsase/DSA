//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    bool bfs(int node, vector<int> &visited, vector<int> adj[]) {
        queue<pair<int, int>> bfsQue;
        bfsQue.push({node, -1});
        
        while (!bfsQue.empty()) {
            int size = bfsQue.size();
            
            while (size--) {
                int node = bfsQue.front().first;
                int parent = bfsQue.front().second;
                
                bfsQue.pop();
                
                visited[node] = 1;
                
                for (auto adjNode : adj[node]) {
                    if (!visited[adjNode]) {
                        bfsQue.push({adjNode, node});
                    } else if(adjNode != parent) {
                        return true;
                    }
                }
            }
        }
    }
  public:
    bool isCycle(int n, vector<int> adj[]) {
        vector<int> visited(n, 0);
        
        for (int node = 0; node < n; node++) {
            if (!visited[node] && bfs(node, visited, adj))
                return true;
        }
        
        return false;
    }
};

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