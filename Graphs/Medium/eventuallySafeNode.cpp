//     LeetCode Logo

// Problem List
// Premium
// 0
// DCC Badge
// 802. Find Eventual Safe States
// Medium
// 3.8K
// 361
// Companies

// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

// Example 1:
// Illustration of graph

// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

// Example 2:

// Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
// Output: [4]
// Explanation:
// Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.

 

// Constraints:

//     n == graph.length
//     1 <= n <= 104
//     0 <= graph[i].length <= n
//     0 <= graph[i][j] <= n - 1
//     graph[i] is sorted in a strictly increasing order.
//     The graph may contain self-loops.
//     The number of edges in the graph will be in the range [1, 4 * 104].

// Accepted
// 128.1K
// S

// ************************* using dfs and path********************
class Solution {
    bool dfs(vector<vector<int>>& graph, vector<bool> &vis, vector<bool> &pathVis, vector<int> &safeSet, int node){
        vis[node] = 1;
        pathVis[node] = 1;
        safeSet[node] = 1;

        for(auto adjNode : graph[node]){
            if(!vis[adjNode]){
                if(dfs(graph, vis, pathVis, safeSet, adjNode)){
                    cout<<node<<" :: "<<adjNode<<" 1:1 \n";
                    return true;
                }
            }else if(pathVis[adjNode]){
                cout<<node<<" :: "<<adjNode<<" 2:2 \n";
                return true;
            }
        }
        cout<<node<<" reached\n";
        
        safeSet[node] = 0;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n = graph.size();
       vector<int> safeSet(n, 0);
       vector<bool>vis (n, 0), pathVis(n, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i])
                dfs(graph, vis, pathVis, safeSet, i);
        }

        vector<int> safeNodes;
        for(int i = 0; i < n; i++){
           if(safeSet[i] == 0) 
              safeNodes.push_back(i);
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

// *************************** using bfs and topological sort**************************
// reverse all edges
// calculate inDegrees
// push nodes with indegree == 0 in queue 
// push queue ele to ans vector
// reduce adj ele in degree by 1 
// it it gets == 0 push that adj ele in queue
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n = graph.size();

       vector<int> adj[n];
       vector<int> inDegree(n, 0);
       for(int i = 0; i < n; i++){
           for(auto e : graph[i]){
               adj[e].push_back(i);
               inDegree[i]++;
           }
       }

       queue<int> safeStates;
       vector<int> safeNodes;
       for(int i = 0; i < n; i++){
           if(inDegree[i] == 0){
              safeStates.push(i);
           }
       }

       while(!safeStates.empty()){
           int node = safeStates.front();
           safeStates.pop();
           safeNodes.push_back(node);
           
           for(auto adjNode : adj[node]){
               if(inDegree[adjNode] - 1 == 0){
                    safeStates.push(adjNode);
               }
               inDegree[adjNode]--;
           }
       }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};