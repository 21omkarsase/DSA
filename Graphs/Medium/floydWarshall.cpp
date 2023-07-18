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


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1));

        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= n; col++) {
                if (row == col) {
                    dist[row][col] = 0;
                } else {
                    dist[row][col] = 1e9;
                }
            }
        }

        for (auto it : times) {
            dist[it[0]][it[1]] = it[2];
        }

        for (int it = 1; it <= n; it++) {
            for (int row = 1; row <= n; row++) {
                for (int col = 1; col <= n; col++) {
                    int time = dist[row][it] + dist[it][col];

                    if (time < dist[row][col]) {
                        dist[row][col] = time;
                    }
                }
            }
        }

        for (int idx = 1; idx <= n; idx++) {
            if (dist[idx][idx] < 0)
                return -1; // negative cycle
        }

        int totalTime = 0;

        for (int idx = 1; idx <= n; idx++) {
            if (dist[k][idx] >= 1e9)
                return -1;            // can't reach to ith node
            
            totalTime = max(totalTime, dist[k][idx]);
        }

        return totalTime ;
    }
};

// Time Complexity:

//     The Floyd-Warshall algorithm has a time complexity of O(V^3), where V is the number of vertices.
//     The algorithm iterates over all pairs of vertices and considers each vertex as a potential intermediate vertex.
//     In each iteration, the algorithm updates the shortest path between all pairs of vertices by considering the intermediate vertex.
//     Therefore, the algorithm performs three nested loops, resulting in a time complexity of O(V^3).

// Space Complexity:

//     The space complexity of the Floyd-Warshall algorithm is O(V^2) because it requires a matrix to store the shortest distances between all pairs of vertices.
//     The matrix has dimensions V x V to represent all possible pairs of vertices.
//     Therefore, the overall space complexity is O(V^2).

// It's important to note that the Floyd-Warshall algorithm is suitable for small to medium-sized graphs due to its cubic time complexity. For larger graphs, more efficient algorithms such as Dijkstra's algorithm or the Bellman-Ford algorithm may be preferred.

// In summary, the time complexity of the Floyd-Warshall algorithm is O(V^3) and the space complexity is O(V^2).