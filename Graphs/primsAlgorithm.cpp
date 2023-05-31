// Minimum Spanning Tree
// MediumAccuracy: 47.82%Submissions: 78K+Points: 4
// Last Week Of Job Fair 2023. Explore Unlimited Opportunities Now!

// Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

 

// Example 1:

// Input:
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1

// Output:
// 4
// Explanation:

// The Spanning Tree resulting in a weight
// of 4 is shown above.

// Example 2:

// Input:
// 2 1
// 0 1 5

// Output:
// 5
// Explanation:
// Only one Spanning Tree is possible
// which has a weight of 5.

 

// Your task:
// Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes number of vertices V and an adjacency matrix adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains a list of lists containing two integers where the first integer a[i][0] denotes that there is an edge between i and a[i][0][0] and second integer a[i][0][1] denotes that the distance between edge i and a[i][0][0] is a[i][0][1].

// In other words , adj[i][j] is of form  { u , wt } . So,this denotes that i th node is connected to u th node with  edge weight equal to wt.

 

// Expected Time Complexity: O(ElogV).
// Expected Auxiliary Space: O(V2).

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        vector<bool> vis(n, 0);

        int ans = 0;
        while(!pq.empty()){
            int w = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(vis[node]) continue;
            
            vis[node] = 1;
            ans += w;

            for(auto p : adj[node]){
                int adjNode = p[0]; 
                int weight = p[1];
                if(!vis[adjNode]){
                    pq.push({weight, adjNode});
                }
            }
        }

        return ans;
        
        // return 0;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends