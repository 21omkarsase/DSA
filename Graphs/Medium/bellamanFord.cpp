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
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dist[u] != 1e8 && dist[u]+w<dist[v]){
                    dist[v] = dist[u] +w;
                }
            }
        }
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            if(dist[u] != 1e8 && dist[u]+w<dist[v]){
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