// 2685. Count the Number of Complete Components
// Medium
// 361
// 7
// Companies

// You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

// Return the number of complete connected components of the graph.

// A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

// A connected component is said to be complete if there exists an edge between every pair of its vertices.

 

// Example 1:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
// Output: 3
// Explanation: From the picture above, one can see that all of the components of this graph are complete.

// Example 2:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
// Output: 1
// Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.

 

// Constraints:

//     1 <= n <= 50
//     0 <= edges.length <= n * (n - 1) / 2
//     edges[i].length == 2
//     0 <= ai, bi <= n - 1
//     ai != bi
//     There are no repeated edges.

// Accepted
// 13.8K
// Submissions
// 20.5K
// Acceptance Rate
// 67.3%

class Solution {
    void dfs(int node, int parent, int &count, vector<bool> &visited, vector<int> adj[], unordered_map<int, int> &tracker) {
        visited[node] = 1;
        
        tracker[node] = adj[node].size();
        count++;
        
        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]){
                dfs(adjNode, node, count, visited, adj, tracker);
            } else if(adjNode != parent) {
                continue;
            }   
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int completeComponentsCount = 0;
        
        vector<int> adj[n];
        vector<bool> visited(n, 0);
        
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                int count = 0;
                unordered_map<int, int> tracker;
                
                dfs(node, -1, count, visited, adj, tracker);
                
                bool flag = true;
                
                for (auto [key, value] : tracker) {

                    if (value != count - 1) {
                        flag = false;
                        break;                        
                    }
                }
                
                if (flag)
                    completeComponentsCount++;
            }
        }
        
        return completeComponentsCount;
    }
};