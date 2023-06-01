// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Medium
// 2K
// 75
// Companies

// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

// Example 1:

// Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
// Output: 3
// Explanation: The figure above describes the graph. 
// The neighboring cities at a distanceThreshold = 4 for each city are:
// City 0 -> [City 1, City 2] 
// City 1 -> [City 0, City 2, City 3] 
// City 2 -> [City 0, City 1, City 3] 
// City 3 -> [City 1, City 2] 
// Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

// Example 2:

// Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
// Output: 0
// Explanation: The figure above describes the graph. 
// The neighboring cities at a distanceThreshold = 2 for each city are:
// City 0 -> [City 1] 
// City 1 -> [City 0, City 4] 
// City 2 -> [City 3, City 4] 
// City 3 -> [City 2, City 4]
// City 4 -> [City 1, City 2, City 3] 
// The city 0 has 1 neighboring city at a distanceThreshold = 2.

 

// Constraints:

//     2 <= n <= 100
//     1 <= edges.length <= n * (n - 1) / 2
//     edges[i].length == 3
//     0 <= fromi < toi < n
//     1 <= weighti, distanceThreshold <= 10^4
//     All pairs (fromi, toi) are distinct.

// Accepted
// 64.6K
// Submissions
// 116.7K
// Acceptance Rate
// 55.3%
// Seen this question in a real interview before?
// 1/4
// Yes
// No
// Discussion (11)
// Similar Questions
// Second Minimum Time to Reach Destination
// Hard
// Related Topics


// ************************TLE : using dfs*****************************
class Solution {
    void dfs(int node, int &ans, int temp, vector<pair<int, int>> adj[], vector<bool> &vis, vector<bool> &path, vector<bool> &thresholds, int &threshold){
        vis[node] = 1;
        path[node] = 1;

        if(threshold >= temp && !thresholds[node]){
            thresholds[node] = 1;
            ans++;
        }

        for(auto [adjNode, weight] : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, ans, temp + weight, adj, path, vis, thresholds, threshold);
            }else if(!path[adjNode] && !thresholds[adjNode]){
                dfs(adjNode, ans, temp + weight, adj, path, vis, thresholds, threshold);
            }
        }
        path[node] = 0;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int, int>> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        int finalNode = -1, finalAns = INT_MAX;
        for(int i = 0; i < n; i++){
            int ans = -1;
            vector<bool> vis(n, 0);
            vector<bool> path(n, 0);
            vector<bool> thresholds(n, 0);
            dfs(i, ans, 0, adj, vis, path, thresholds, threshold);
            if((ans < finalAns) || (finalAns == ans && finalNode < i)){
                finalAns = ans;
                finalNode = i;
            }
        }
    
        return finalNode;
    }
};



// ***************************using floyd warshall*************************
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            dist[u][v] = w; 
            dist[v][u] = w;
        }
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        int ans = INT_MAX, node = -1;
        for(int i = 0; i < n; i++){
            int temp = 0;
            for(int j = 0; j < n; j++){
                if(i != j && dist[i][j] <= threshold){
                    temp++;
                }
            }
            if(ans >= temp){
                ans = temp;
                node = i;
            }
        }

        return node;
    }
};


// *********************************using dijkstras*************************
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int, int>> adj[n];
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> shortDist(n, 0);
        for(int i = 0; i < n; i++){
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});
            dist[i] = 0;

            while(!pq.empty()){
                int u = pq.top().second;
                int w = pq.top().first;
                pq.pop();

                for(auto [v, weight] : adj[u]){
                    if(w + weight < dist[v]){
                        dist[v] = w + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
            
            int temp = 0;
            for(int i = 0; i < n; i++){
                if(dist[i] <= threshold && dist[i] != 0){
                    temp++;
                }
            }
            shortDist[i] = temp;
        }
        
        int ans = shortDist[0], node = 0;
        for(int i = 1; i < n; i++){
            if(shortDist[i] <= ans){
                ans = shortDist[i];
                node = i;
            }
        }

        return node;
    }
};