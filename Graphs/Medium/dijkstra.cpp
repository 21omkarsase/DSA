// /743. Network Delay Time
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

// can't detect cycles with -ve cycle sum

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];

        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        int totalTime = 0;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {k, k}});

        while (!pq.empty()) {
            int size = pq.size();

            while (size--) {
                auto it = pq.top();
                pq.pop();

                int w = it.first, u = it.second.first, v = it.second.second;

                for (auto [node, weight] : adj[v]) {
                    int distance = weight + w;

                    if (distance < dist[node]) {
                        dist[node] = distance;
                        pq.push({distance, {v, node}});
                    }
                }
            }
        }

        for (int idx = 1; idx <= n; idx++) {
            if (dist[idx] >= 1e9)
                return -1;              // ith node is unreachable

            totalTime = max(totalTime, dist[idx]);
        }
        
        return totalTime;
    }
};

// Time Complexity:

//     With a priority queue implementation, Dijkstra's algorithm has a time complexity of O((V + E) log V), where V is the number of vertices and E is the number of edges.
//     In the worst case, the algorithm visits each vertex once (V iterations) and each edge once (E iterations) while maintaining the priority queue.
//     Each insertion and deletion operation in the priority queue takes O(log V) time.
//     Therefore, the overall time complexity is O((V + E) log V).

// Space Complexity:

//     The space complexity of Dijkstra's algorithm is O(V) because it uses a priority queue to store the vertices and their distances from the source vertex.
//     Additionally, it requires space to store the distances from the source vertex to all other vertices, which is also O(V).
//     Therefore, the overall space complexity is O(V).

// In summary, the time complexity of Dijkstra's algorithm is O((V + E) log V) and the space complexity is O(V).