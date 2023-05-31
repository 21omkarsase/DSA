// 834. Sum of Distances in Tree
// Hard
// 4.6K
// 106
// Companies

// There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

// You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

 

// Example 1:

// Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// Output: [8,12,6,10,10,10]
// Explanation: The tree is shown above.
// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// equals 1 + 1 + 2 + 2 + 2 = 8.
// Hence, answer[0] = 8, and so on.

// Example 2:

// Input: n = 1, edges = []
// Output: [0]

// Example 3:

// Input: n = 2, edges = [[1,0]]
// Output: [1,1]

 

// Constraints:

//     1 <= n <= 3 * 104
//     edges.length == n - 1
//     edges[i].length == 2
//     0 <= ai, bi < n
//     ai != bi
//     The given input represents a valid tree.

// Accepted
// 82K
// Submissions
// 138.8K
// Acceptance Rate
// 59.1%

class Solution {
    vector<int>sub;
    vector<int>dep;
    vector<int>sum;
    vector<bool> vis;

    void dfs1(vector<int> adj[], int par){
        sub[par] = 1;
        vis[par] = true;
        for(auto child : adj[par]){
            if(!vis[child]){
                vis[child] = 1;
                dep[child] = dep[par] + 1;
                dfs1(adj, child);
                sub[par] += sub[child];
            }
        }
    }

    void dfs2(vector<int> adj[], int par, int n){
        vis[par] = true;
        for(auto child : adj[par]){
            if(!vis[child]){
                sum[child] = sum[par] - sub[child] + (n - sub[child]);
                dfs2(adj, child, n);
            }
        }
    }
public:
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        int N = edges.size();
        sub.resize(n);
        dep.resize(n);
        sum.resize(n);
        vis.resize(n);
        
        vector<int> adj[n];

        for(int i = 0; i < N; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++) {
            vis[i] = false;
        }

        // vis.resize(n, 0);
        dfs1(adj, 0);

        for(int i = 0; i < n; i++){
            sum[0] += dep[i];
        }

        for(int i=0;i<n;i++) {
            vis[i] = false;
        }
        
        // vis.resize(n, 0);
        dfs2(adj, 0, n);

        return sum;
    }


};















