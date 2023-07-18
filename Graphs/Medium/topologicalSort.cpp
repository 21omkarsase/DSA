// Topological sort
// MediumAccuracy: 56.52%Submissions: 119K+Points: 4
// Lamp
// Become a GfG Premium Member at Zero Cost. Explore Courses  

// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.


// Example 1:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 3, 2, 1, 0.

// Example 2:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 5, 4, 2, 1, 3, 0.


// Your Task:
// You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then console output will be 1 else 0.


// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).


// Constraints:
// 2 ≤ V ≤ 104
// 1 ≤ E ≤ (N*(N-1))/2

//posiible in DAG only
// if there is an edge between u to v  
// then in topoSort u will come before v

//*****************************using bfs (kahn's algorithm)***********************************

class Solution
{
    public:
    //Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        vector<int> inDegree(V, 0);
        
        for (int node = 0; node < V; node++) {
            for (auto adjNode : adj[node]) {
                inDegree[adjNode]++;
            }
        }
        
        queue<int> q;
        
        for (int node = 0; node < V; node++) {
            if (inDegree[node] == 0)
                q.push(node);
        }
        
        vector<int> topoOrder;
        
        while (!q.empty()) {
            int node = q.front();
            topoOrder.push_back(node);
            
            q.pop();
            
            for (auto adjNode : adj[node]) {
                if (inDegree[adjNode] - 1 == 0){
                    q.push(adjNode);
                }
                
                inDegree[adjNode]--;
            }
        }
        
        return topoOrder;
    }
};

//*****************************using dfs***********************************

class Solution
{
    public:
    void dfs(vector<int> adj[],int vis[],int curr,vector<int> &ans){
        vis[curr]=1;
        for(auto e:adj[curr]){
            if(!vis[e]){
              dfs(adj,vis,e, ans);
            }  
        }
        ans.push_back(curr);
    }
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        int vis[V];
        for(auto &e:vis)e=0;
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(adj,vis,i, ans);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};