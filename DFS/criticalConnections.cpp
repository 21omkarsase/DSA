// 1192. Critical Connections in a Network
// Hard
// 5.5K
// 172
// Companies

// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

 

// Example 1:

// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.

// Example 2:

// Input: n = 2, connections = [[0,1]]
// Output: [[0,1]]

 

// Constraints:

//     2 <= n <= 105
//     n - 1 <= connections.length <= 105
//     0 <= ai, bi <= n - 1
//     ai != bi
//     There are no repeated connections.

// Accepted
// 199.3K
// Submissions
// 363.9K
// Acceptance Rate
// 54.8%

class Solution {
    void dfs(int node, int parent, int &timer, vector<int> adj[], vector<bool> &vis, vector<int> &low, vector<int> &ent, vector<vector<int>> &bridges){
        vis[node] = 1;
        timer++;

        low[node] = timer;
        ent[node] = timer;

        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, node, timer, adj, vis, low, ent, bridges);

                low[node] = min(low[node], low[adjNode]); 
                if(ent[node] < low[adjNode]){
                    bridges.push_back({node, adjNode});
                }               
            }else if(adjNode != parent){
                low[node] = min(low[node], low[adjNode]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];

        for(auto conn : connections){
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<vector<int>> bridges;
        vector<int> low(n, 0), ent(n, 0);
        vector<bool> vis(n, 0);
        int timer = 0;
        dfs(0, -1, timer, adj, vis, low, ent, bridges);

        return bridges;
    }
};