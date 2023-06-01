// 547. Number of Provinces
// Medium
// 7.6K
// 292
// Companies

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 

// Example 1:

// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2

// Example 2:

// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3

 

// Constraints:

//     1 <= n <= 200
//     n == isConnected.length
//     n == isConnected[i].length
//     isConnected[i][j] is 1 or 0.
//     isConnected[i][i] == 1
//     isConnected[i][j] == isConnected[j][i]

// Accepted
// 629.9K
// Submissions
// 984.6K
// Acceptance Rate
// 64.0%


// *************************USING UNION FIND**************************

class Disjoint{
    vector<int>size, parent;
public:
    Disjoint(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node)return node;

        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    void unionMerge(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);

        if(ulp_u == ulp_v)return ;
        
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u; 
            size[ulp_u]+=size[ulp_v];
        }else{
            parent[ulp_u]=ulp_v; 
            size[ulp_v]+=size[ulp_u];
        }
    }

    int getProvinces(int n){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(findParent(i) == i)
                cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Disjoint *ds = new Disjoint(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    ds->unionMerge(i, j);
                }
            }
        }

        return ds->getProvinces(n);
    }
};




// **************************************USING DFS**********************************
class Solution {
    void dfs(vector<int> adj[], vector<bool> &vis, int node){
        vis[node] = 1;

        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adj, vis, adjNode);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
                vector<int> adj[n];
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                            if(isConnected[i][j]){
                                adj[i].push_back(j);
                                adj[j].push_back(i);
                            }
                    }
                }
                
                int cnt = 0;
                vector<bool> vis(n, 0);
                for(int i = 0; i < n; i++){
                    if(!vis[i]){
                        dfs(adj, vis, i);
                        cnt++;
                    }
                }

                return cnt;
    }
};









