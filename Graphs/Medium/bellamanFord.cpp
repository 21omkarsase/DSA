// 743. Network Delay Time
// Medium
// 6.6K
// 336
// Companies

// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

// Example 1:

// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2

// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1

// Example 3:

// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1

 

// Constraints:

//     1 <= k <= n <= 100
//     1 <= times.length <= 6000
//     times[i].length == 3
//     1 <= ui, vi <= n
//     ui != vi
//     0 <= wi <= 100
//     All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

// Accepted
// 394.2K
// Submissions
// 753.2K
// Acceptance Rate
// 52.3%

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        

        // relaxing every edge
        // by iterating v - 1 times
        // beacause graph can have at most v - 1 edges
        for (int idx = 1; idx < n; idx++) {
            for (auto it : times) {
                int u = it[0], v = it[1], w = it[2];

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        for (auto it : times) {
            int u = it[0], v = it[1], w = it[2];

            if (dist[v] > dist[u] + w) {   // graph with -ve cycle sum 
                return -1;
            }
        }

        int totalTime = 0;
        
        for (int node = 1; node <= n; node++) {
            if (dist[node] >= 1e9) {
                return -1;                    // can't reach this node
            }

            totalTime = max(totalTime, dist[node]);
        }

        return totalTime;
    }
};

// } Driver Code Ends

// Time Complexity:

//     The Bellman-Ford algorithm has a time complexity of O(V * E), where V is the number of vertices and E is the number of edges.
//     In the worst case, the algorithm performs V-1 iterations, and in each iteration, it relaxes all E edges.
//     The relaxation step compares and updates the distances of vertices, and it takes O(1) time for each edge.
//     Therefore, the overall time complexity is O(V * E).

// Space Complexity:

//     The space complexity of the Bellman-Ford algorithm is O(V) because it requires an array to store the distances from the source vertex to all other vertices.
//     Additionally, it may require space for additional arrays to store other information, such as the predecessor vertices or a flag indicating negative cycles.
//     Therefore, the overall space complexity is O(V).

// It's worth noting that if the graph is a dense graph, meaning that the number of edges is close to the maximum possible (V * (V - 1)), the time complexity of the Bellman-Ford algorithm becomes O(V^3). However, in a sparse graph, the time complexity remains O(V * E).

// In summary, the time complexity of the Bellman-Ford algorithm is O(V * E) in general, and the space complexity is O(V).