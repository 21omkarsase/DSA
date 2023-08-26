// 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
// Hard
// 1.1K
// 93
// Companies

// Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

// Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

// Note that you can return the indices of the edges in any order.

 

// Example 1:

// Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
// Output: [[0,1],[2,3,4,5]]
// Explanation: The figure above describes the graph.
// The following figure shows all the possible MSTs:

// Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
// The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

// Example 2:

// Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
// Output: [[],[0,1,2,3]]
// Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.

 

// Constraints:

//     2 <= n <= 100
//     1 <= edges.length <= min(200, n * (n - 1) / 2)
//     edges[i].length == 3
//     0 <= ai < bi < n
//     1 <= weighti <= 1000
//     All pairs (ai, bi) are distinct.

// Accepted
// 21.5K
// Submissions
// 34.8K
// Acceptance Rate
// 61.7%

class Disjoint {
    vector<int> size, parent;

public:
    Disjoint(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) return node;

        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    bool unionMerge(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v) {
            return false;
        }

        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        return true;
    }

    int getMaxSize() {
        return *max_element(size.begin(), size.end());
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(2); 

        vector<pair<int, pair<int, pair<int, int>>>> sortedEdges;

        for (int edge = 0; edge < edges.size(); edge++) {
            int u = edges[edge][0], v = edges[edge][1], w = edges[edge][2];

            sortedEdges.push_back({w, {edge, {u, v}}});
        }

        sort(sortedEdges.begin(), sortedEdges.end());

        Disjoint ds(n); 

        int originalCost = 0;
        for (auto edge : sortedEdges) {
            int w = edge.first, u = edge.second.second.first, v = edge.second.second.second;

            if (ds.unionMerge(u, v)) {
                originalCost += w;
            }
        }

        for (auto edge : sortedEdges) {
            int w = edge.first, idx = edge.second.first, u = edge.second.second.first, v = edge.second.second.second;

            Disjoint tempDs(n);

            int newCost = 0;
            for (auto currEdge : sortedEdges) {
                int currW = currEdge.first, currIdx = currEdge.second.first;
                int currU = currEdge.second.second.first, currV = currEdge.second.second.second;

                if (currIdx != idx && tempDs.unionMerge(currU, currV)) {
                    newCost += currW;
                }
            }

            if (newCost > originalCost || tempDs.getMaxSize() != n) {
                result[0].push_back(idx);
            } else {
                tempDs = Disjoint(n);
                tempDs.unionMerge(u, v);
                newCost = w;

                for (auto currEdge : sortedEdges) {
                    int currW = currEdge.first, currIdx = currEdge.second.first;
                    int currU = currEdge.second.second.first, currV = currEdge.second.second.second;

                    if (currIdx != idx && tempDs.unionMerge(currU, currV)) {
                        newCost += currW;
                    }
                }

                if (newCost == originalCost && tempDs.getMaxSize() == n) {
                    result[1].push_back(idx);
                }
            }
        }

        return result;
    }
};
