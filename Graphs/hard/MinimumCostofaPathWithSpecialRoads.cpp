// 2662. Minimum Cost of a Path With Special Roads
// Medium
// 388
// 65
// Companies

// You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).

// The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.

// There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each special road any number of times.

// Return the minimum cost required to go from (startX, startY) to (targetX, targetY).

 

// Example 1:

// Input: start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
// Output: 5
// Explanation: The optimal path from (1,1) to (4,5) is the following:
// - (1,1) -> (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
// - (1,2) -> (3,3). This move uses the first special edge, the cost is 2.
// - (3,3) -> (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
// - (3,4) -> (4,5). This move uses the second special edge, the cost is 1.
// So the total cost is 1 + 2 + 1 + 1 = 5.
// It can be shown that we cannot achieve a smaller total cost than 5.

// Example 2:

// Input: start = [3,2], target = [5,7], specialRoads = [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
// Output: 7
// Explanation: It is optimal to not use any special edges and go directly from the starting to the ending position with a cost |5 - 3| + |7 - 2| = 7.

 

// Constraints:

//     start.length == target.length == 2
//     1 <= startX <= targetX <= 105
//     1 <= startY <= targetY <= 105
//     1 <= specialRoads.length <= 200
//     specialRoads[i].length == 5
//     startX <= x1i, x2i <= targetX
//     startY <= y1i, y2i <= targetY
//     1 <= costi <= 105


class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        map<pair<int, int>, int> m1;  // for storing {co-ordinates} : node
        map<int, pair<int, int>> m2;  // for storing node : {co-ordinates}
        
        int n = 0;

        m1[{start[0], start[1]}] = n;
        m2[n] = {start[0], start[1]};
        n++;
        
        
        for (auto road : specialRoads) {
            int s1 = road[0], e1 = road[1], s2 = road[2], e2 = road[3], w = road[4];

            if (m1.find({s1, e1}) == m1.end()) { // avoiding duplicates
                m1[{s1, e1}] = n;
                m2[n] = {s1, e1};
                n++;
            }

            if (m1.find({s2, e2}) == m1.end()) { // avoiding duplicates
                m1[{s2, e2}] = n;
                m2[n] = {s2, e2};
                n++;
            }
        }

        if (m1.find({target[0], target[1]}) == m1.end()) { // avoiding duplicates
            m1[{target[0], target[1]}] = n;
            m2[n] = {target[0], target[1]};
            n++;
        }

        // we have total n nodes (incluing start, end and all other special nodes)
        
        vector<pair<int, int>> adj[n]; // creating adj list

        for (int idx1 = 0; idx1 < n; idx1++) {
            for (int idx2 = idx1 + 1; idx2 < n; idx2++){
                int a = m2[idx1].first, b = m2[idx1].second;  // get co-ordinates using m2
                int c = m2[idx2].first, d = m2[idx2].second;

                adj[idx1].push_back({idx2, abs(c - a) + abs(d - b)}); // storing pairs with absolute diff
                adj[idx2].push_back({idx1, abs(c - a) + abs(d - b)}); 
            }
        }

        for (auto road : specialRoads) {
            int s1 = road[0], e1 = road[1], s2 = road[2], e2 = road[3], w = road[4];

            int node1 = m1[{s1, e1}];
            int node2 = m1[{s2, e2}];

            for (int idx = 0; idx < adj[node1].size(); idx++) {
                if (node2 == adj[node1][idx].first) {
                    // for special road storing min of abs distance and special road distance
                    adj[node1][idx] = {node2, min(w, adj[node1][idx].second)};  
                }
            }
        }

        // apply dijkstra's

        vector<int> dist(n, 1e9);
        dist[0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int size = pq.size();

            while (size--) {
                auto it = pq.top();
                pq.pop();

                int w = it.first;
                int u = it.second.first;
                int v = it.second.second;

                for (auto [adjNode, weight] : adj[v]) {
                    int distance = w + weight;

                    if (distance < dist[adjNode]) {
                        dist[adjNode] = distance;
                        pq.push({distance, {v, adjNode}});
                    }
                }
            }
        }

        return dist[m1[{target[0], target[1]}]];  // target node will not always present at last (if target duplicate present in special roads)
    }
};

