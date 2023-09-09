// Mother Vertex
// EasyAccuracy: 47.64%Submissions: 56K+Points: 2

// Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
// A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

// Example 1:

// Input: 

// Output: 0
// Explanation: According to the given edges, all 
// nodes can be reached from nodes from 0, 1 and 2. 
// But, since 0 is minimum among 0,1 and 2, so 0 
// is the output.

// Example 2:

// Input: 

// Output: -1
// Explanation: According to the given edges, 
// no vertices are there from where we can 
// reach all vertices. So, output is -1.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function findMotherVertex() which takes V denoting the number of vertices and adjacency list as input parameter and returns the vertices from through which we can traverse all other vertices of the graph. If there is more than one possible nodes then return the node with minimum value. If not possible returns -1.

// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)

// Constraints:
// 1 ≤ V ≤ 500

// Time Complexity : O(V + E) can be O(V * (V + E))
// Space Complexity : O(V)


class Solution 
{
    int dfs(int node, vector<bool> &visited, vector<int> adj[]) {
        visited[node] = 1;
        int cnt = 1;
        
        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                cnt += dfs(adjNode, visited, adj);
            }
        }
        
        return cnt;
    }
    public:
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool> visited(V, 0);
	    vector<int> vertices;
	    
	    for (int node = 0; node < V; node++) {
	        if (!visited[node]) {
	            dfs(node, visited, adj);
	            vertices.push_back(node);
	        }
	    }
	    
	    int ans = V + 1;
	    
	    for (int idx = vertices.size() - 1; idx >= 0; idx--) {
	        vector<bool> vis(V, 0);
	       
	        if (dfs(vertices[idx], vis, adj) == V) {
	            ans = min(ans, vertices[idx]);
	        }
	        else {
	            break;
	        }
	    }
	    
	    if (ans == V + 1) {
	        return -1;
	    }
	    
	    return ans;
	}

};

class Solution {
    void dfs(int node, vector<bool> &visited, vector<int> adj[], stack<int> &st) {
        visited[node] = 1;

        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
              dfs(adjNode, visited, adj, st);
            }
        }
        
        st.push(node);
    }
    
    int dfs(int node, vector<bool> &visited, vector<int> adj[]) {
        visited[node] = 1;
        int cnt = 1;
        
        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
              cnt += dfs(adjNode, visited, adj);
            }
        }
        
        return cnt;
    }
    
public:
	int findMotherVertex(int V, vector<int>adj[]) {
	    int ans = V + 1;
	    
        vector<bool> visited(V, 0);
        stack<int> st;
        
	    for (int node = 0; node < V; node++) {
	        if (!visited[node]) {
	            dfs(node, visited, adj, st);
	        }
	    }
	    
	    while (!st.empty()) {
	        vector<bool> vis(V, 0);
	        
	        if (dfs(st.top(), vis, adj) == V) {
	            ans = min(ans, st.top());
	           
	            st.pop();
	        }
	        else {
	            break;
	        }
	    }
	    
	    if (ans == V + 1) {
	        return -1;
	    }
	    
	    return ans;
	}
	
};

class Solution 
{
    public:
    void dfs(vector<int>adj[],int vis[],int &cnt,int curr){
        vis[curr]=1;
        cnt++;
        for(auto e:adj[curr]){
            if(!vis[e]){
                dfs(adj,vis,cnt,e);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int cnt=0;
	    int vis[V]={0};
	    dfs(adj,vis,cnt,0);
	    if(cnt==V)return 0;
	    for(int i=0;i<V;i++){
    	    cnt=0;
	        if(!vis[i]){
	            dfs(adj,vis,cnt,i);
	        }
	        if(cnt==V)return i;
	    }
	    return -1;
    }

};