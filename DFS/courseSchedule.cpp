// 207. Course Schedule
// Medium
// 13.4K
// 536
// Companies

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

//     For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

 

// Constraints:

//     1 <= numCourses <= 2000
//     0 <= prerequisites.length <= 5000
//     prerequisites[i].length == 2
//     0 <= ai, bi < numCourses
//     All the pairs prerequisites[i] are unique.

// Accepted
// 1.2M
// Submissions
// 2.6M
// Acceptance Rate
// 45.4%
// Seen this question in a real interview before?
// 1/4
// Yes
// No
// Discussion (55)
// Similar Questions
// Course Schedule II
// Medium
// Graph Valid Tree
// Medium
// Minimum Height Trees
// Medium
// Course Schedule III
// Hard
// Build a Matrix With Conditions
// Hard
// Related Topics
// Depth-First Search
// Breadth-First Search
// Graph
// Topological Sort
// Copyright ©️ 2023 LeetCode All rights reserved


class Solution {
    bool dfs(vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis, int node){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfs(adj, vis, pathVis, adjNode))
                    return true;
            }else if(pathVis[adjNode]){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prs) {
        vector<int> adj[n];
        for(auto v : prs){
            adj[v[1]].push_back(v[0]);
        }

        vector<bool> vis(n, 0), pathVis(n, 0);
        
        for(int i = 0; i  < n; i++){
            if(dfs(adj, vis, pathVis, i)){
                return false;
            }
        }
        
        return true;
    }
};







// ******************using topological sort and queue*********************
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prs) {
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        for(auto v : prs){
            adj[v[0]].push_back(v[1]);
            inDegree[v[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!inDegree[i])
                q.push(i);
        }
        
        unordered_set<int> uset;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            uset.insert(node);
            for(auto adjNode : adj[node]){
                if(inDegree[adjNode] - 1 == 0)
                    q.push(adjNode);
                inDegree[adjNode]--;
            }
        }

        if(uset.size() == n)
            return true;
        return false;
    }
};





















