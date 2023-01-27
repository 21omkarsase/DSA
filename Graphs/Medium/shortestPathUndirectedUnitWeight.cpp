// Shortest path in Undirected Graph having unit distance
// MediumAccuracy: 47.63%Submissions: 7K+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation  

// You are given an Undirected Graph having unit weight, Find the shortest path from src(0) to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

// Example:

// Input:
// n = 9, m= 10
// edges=[[0,1],[0,3],[3,4],[4 ,5]
// ,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
// src=0
// Output:
// 0 1 2 1 2 3 3 4 4

// Your Task:

// You don't need to print or input anything. Complete the function shortest path() which takes a 2d vector or array edges representing the edges of undirected graph with unit weight, an integer N as number nodes, an integer M as number of edges and an integer src as the input parameters and returns an integer array or vector, denoting the vector of distance from src to all nodes.

// Constraint:
// 1<=n,m<=100
// 1<=adj[i][j]<=100

// Expected Time Complexity: O(N + E), where N is the number of nodes and E is edges
// Expected Space Complexity: O(N)


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(auto p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        
        queue<pair<int,int>>q;
        q.push({src,0});
        
        vector<int>dist(N,1e6);
        dist[src]=0;
        
        while(!q.empty()){
            int node=q.front().first;
            int len=q.front().second;
            q.pop();
            for(auto e:adj[node]){
                int newDist=len+1;
                if(newDist<dist[e]){
                    dist[e]=newDist;
                    q.push({e,newDist});
                }
            }
        }
        for(auto &e:dist)e=e==1e6 ? -1 : e;
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends