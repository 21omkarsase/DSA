// 210. Course Schedule II
// Medium
// 9.2K
// 298
// Companies

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

//     For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]

 

// Constraints:

//     1 <= numCourses <= 2000
//     0 <= prerequisites.length <= numCourses * (numCourses - 1)
//     prerequisites[i].length == 2
//     0 <= ai, bi < numCourses
//     ai != bi
//     All the pairs [ai, bi] are distinct.

// Accepted
// 821.2K
// Submissions
// 1.7M
// Acceptance Rate
// 48.7%


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

    void dfs2(vector<int> adj[], vector<bool> &vis, vector<int> &courseOrder, int node){
        vis[node] = 1;
        for(auto adjNode : adj[node]){
            if(!vis[adjNode])
                dfs2(adj, vis, courseOrder, adjNode);
        }

        courseOrder.push_back(node);
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& prs) {
        vector<int> adj[n];
        for(auto v : prs){
            adj[v[1]].push_back(v[0]);
        }

        vector<bool> vis(n, 0), pathVis(n, 0);
        
        for(int i = 0; i  < n; i++){
            if(dfs(adj, vis, pathVis, i)){
                vector<int> ans;
                  for(int i = 0; i < n; i++)
                     cout<<pathVis[i]<<" : ";
                  cout<<"\n";
                return ans;
            }
        }

        for(int i = 0; i < n; i++)
            cout<<pathVis[i]<<" : ";
        cout<<"\n";
        
        for(int i = 0; i < n; i++) vis[i] = 0;
        vector<int> courseOrder;
        for(int i = 0; i < n; i++){
            if(!vis[i])
                dfs2(adj, vis, courseOrder, i);
        }
        
        reverse(courseOrder.begin(), courseOrder.end());
        return courseOrder;
    }
};








class Solution {
    bool dfs(vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis, vector<int> &courseOrder, int node){
        if(pathVis[node]){
            return true;
        }

        if(vis[node]){
            return false;
        }
        
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto adjNode : adj[node]){
            if(dfs(adj, vis, pathVis, courseOrder, adjNode))
                return true;
        }
        
        courseOrder.push_back(node);
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& prs) {
        vector<int> adj[n];
        for(auto v : prs){
            adj[v[1]].push_back(v[0]);
        }

        vector<bool> vis(n, 0), pathVis(n, 0);
        vector<int> courseOrder;
        
        for(int i = 0; i  < n; i++){
            if(dfs(adj, vis, pathVis, courseOrder, i)){
                vector<int> ans;
                return ans;
            }
        }
        
        reverse(courseOrder.begin(), courseOrder.end());
        return courseOrder;
    }
};
























