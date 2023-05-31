// Distance from the Source (Bellman-Ford Algorithm)
// MediumAccuracy: 48.11%Submissions: 29K+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation  

// Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
// Note: If the Graph contains a negative cycle then return an array consisting of only -1.

// Example 1:

// Input:

// E = [[0,1,9]]
// S = 0
// Output:
// 0 9
// Explanation:
// Shortest distance of all nodes from
// source is printed.

// Example 2:

// Input:

// E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]
// S = 2
// Output:
// 1 6 0
// Explanation:
// For nodes 2 to 0, we can follow the path-
// 2-0. This has a distance of 1.
// For nodes 2 to 1, we cam follow the path-
// 2-0-1, which has a distance of 1+5 = 6,

//  

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function bellman_ford( ) which takes a number of vertices V and an E-sized list of lists of three integers where the three integers are u,v, and w; denoting there's an edge from u to v, which has a weight of w and source node S as input parameters and returns a list of integers where the ith integer denotes the distance of an ith node from the source node.

// If some node isn't possible to visit, then its distance should be 100000000(1e8). Also, If the Graph contains a negative cycle then return an array consisting of only -1.

//  

// Expected Time Complexity: O(V*E).
// Expected Auxiliary Space: O(V).

//  

// Constraints:
// 1 ≤ V ≤ 500
// 1 ≤ E ≤ V*(V-1)
// -1000 ≤ adj[i][j] ≤ 1000
// 0 ≤ S < V


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */

    //implementation only work for directed graph 
    //so convert undirected graph to directed first
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V,1e8);
        dist[S]=0;

        // relax all nodes for n - 1 times (n --> no. of nodes)
        // relaxation : 
        // e.g (u : 1 -> v : 3  (w : 5))
        // checking condition : 
        // if(dist[u] + w < dis[v])
                // dist[v] = dist[u] + w

        //why n - 1 :
        // in worst case we will need take n - 1 edges to travel from first node to last node

        for(int i=0;i<V-1;i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        


        // this is n'th iteration to detect -ve cycle
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            if(dist[u] != 1e8 && dist[u]+w<dist[v]){
                //if value get's reduced here, then graph has -ve cycle in it.
               return {-1};
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

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