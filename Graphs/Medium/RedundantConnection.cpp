// 684. Redundant Connection
// Medium
// 5.7K
// 365
// Companies

// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

// Example 1:

// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]

// Example 2:

// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]

 

// Constraints:

//     n == edges.length
//     3 <= n <= 1000
//     edges[i].length == 2
//     1 <= ai < bi <= edges.length
//     ai != bi
//     There are no repeated edges.
//     The given graph is connected.

// Accepted
// 301.4K
// Submissions
// 482.4K
// Acceptance Rate
// 62.5%

// Time Complexity : O(N * (N + E))

class Solution {
    bool isCycle(int node, int parent, vector<bool> &visited, vector<int> adj[]) {
        visited[node] = 1;

        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                if (isCycle(adjNode, node, visited, adj)) {
                    return true;
                }
            }
            else if (adjNode != parent) {
                return true;
            }
        }

        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        
        vector<int> adj[n];

        for (auto edge : edges) {
            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> visited(n, 0);

            if (isCycle(u, -1, visited, adj)) {
                return edge;
            }
        }

        return {-1, -1};
    }
};


class DSU {
    vector<int> size;
    vector<int> parent;

public:
    DSU (int n) {
        size.resize(n, 1);
        parent.resize(n);

        for (int idx = 0; idx < n; idx++) {
            parent[idx] = idx;
        }
    };

    int findParent (int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    bool unionMerge (int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v) {
            return false;
        }

        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        DSU ds(n + 1);

        for (auto edge : edges) {
            if (!ds.unionMerge(edge[0], edge[1])) {
                return edge;
            }
        }

        return {-1, -1};
    }
};

