// Bipartite Graph
// MediumAccuracy: 31.25%Submissions: 97K+Points: 4
// Lamp
// Save Today, Earn More Tomorrow. Get 25% off on Complete Interview Preparation  

// Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
//  

// Example 1:

// Input: 

// Output: 1
// Explanation: The given graph can be colored 
// in two colors so, it is a bipartite graph.

// Example 2:

// Input:

// Output: 0
// Explanation: The given graph cannot be colored 
// in two colors such that color of adjacent 
// vertices differs. 

//  

// Your Task:
// You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.
//  

// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)

// Constraints:
// 1 ≤ V, E ≤ 105

// Acylic and graph with even cycle length are always biaprtite
// we can divide bipartite graph nodes in two sets such that any two adjacent nodes does not belong to same set

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	// ****************************bfs************************
    bool bfs(vector<int>adj[],int vis[],int start){
        queue<pair<int,int>>q;
	    q.push({start,0});
	    vis[start]=0;
        while(!q.empty()){
            int node=q.front().first;
            int color=q.front().second;
            q.pop();
            for(auto e:adj[node]){
                if(vis[e]==-1){
                    vis[e]= color==0 ? 1 : 0;
                    q.push({e,vis[e]});
                }else if(color==vis[e]){
                    return false;
                }
            }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    int vis[V];
	    for(auto &e:vis)e=-1;
	    
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1)
    	        if(!bfs(adj,vis,i))return false;
	    }
	    return true;
	}
    // *******************************dfs*************************
    // bool dfs(vector<int>adj[],int vis[],int start,int color){
    //     vis[start]=color;
    //     for(auto e:adj[start]){
    //         if(vis[e]==-1){
    //             if(!dfs(adj,vis,e,!color))return false;
    //         }else if(vis[e]==color){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // bool isBipartite(int V,vector<int>adj[]){
    //     int vis[V];
    //     for(auto &e:vis)e=-1;
    //     for(int i=0;i<V;i++){
    //         if(vis[i]==-1)
    //            if(!dfs(adj,vis,i,0))return false;
    //     }
        
    //     return true;
    // }
    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends