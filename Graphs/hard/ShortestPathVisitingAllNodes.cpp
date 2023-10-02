// 847. Shortest Path Visiting All Nodes
// Solved
// Hard
// Topics
// Companies

// You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

// Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

// Example 1:

// Input: graph = [[1,2,3],[0],[0],[0]]
// Output: 4
// Explanation: One possible path is [1,0,2,0,3]

// Example 2:

// Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
// Output: 4
// Explanation: One possible path is [0,1,4,2,3]

 

// Constraints:

//     n == graph.length
//     1 <= n <= 12
//     0 <= graph[i].length < n
//     graph[i] does not contain i.
//     If graph[a] contains b, then graph[b] contains a.
//     The input graph is always connected.

// Accepted
// 80.6K
// Submissions
// 130.1K
// Acceptance Rate
// 62.0%

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, 0));

        for (int node = 0; node < n; node++) {
            q.push({node, 1 << node});
            visited[node][1 << node] = 1;
        }
        
        int shortestPath = 0;

        while (!q.empty()) {
            int size = q.size();
            
            for (int it = 0; it < size; it++) {
                int node = q.front().first;
                int mask = q.front().second;

                q.pop();

                if (mask == (1 << n) - 1) {
                    return shortestPath;
                }

                for (auto adjNode : graph[node]) {
                    int newMask = mask | (1 << adjNode);

                    if (!visited[adjNode][newMask]) {
                        visited[adjNode][newMask] = true;

                        q.push({adjNode, newMask});
                    }
                }

            }

            shortestPath++;
        }

        return shortestPath;
    }
};