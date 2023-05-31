// 947. Most Stones Removed with Same Row or Column
// Medium
// 4.7K
// 616
// Companies

// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

// Example 1:

// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

// Example 2:

// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// Output: 3
// Explanation: One way to make 3 moves is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,0].
// 2. Remove stone [2,0] because it shares the same column as [0,0].
// 3. Remove stone [0,2] because it shares the same row as [0,0].
// Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

// Example 3:

// Input: stones = [[0,0]]
// Output: 0
// Explanation: [0,0] is the only stone on the plane, so you cannot remove it.

 

// Constraints:

//     1 <= stones.length <= 1000
//     0 <= xi, yi <= 104
//     No two stones are at the same coordinate point.

// Accepted
// 178.2K
// Submissions
// 302.8K
// Acceptance Rate
// 58.9%

// *********************************using bfs****************************

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n, 0);
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                vis[i] = 1;
                queue<int> q;
                q.push(i);

                while(!q.empty()){
                    int row = stones[q.front()][0], col = stones[q.front()][1];
                    q.pop();

                    for(int j = 0; j < n; j++){
                        if(!vis[j] && stones[j][0] == row || stones[j][1] == col){
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return n - cnt;
    }
};


// *********************************using union find***********************

class DisJoint{
    vector<int> SIZE;
    vector<int> parent;

public:

    DisJoint(int n){
        SIZE.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node])
            return node;

        return parent[node] = this->findParent(parent[node]);
    }

    void unionMerge(int u, int v){
        int ulp_u = this->findParent(u);
        int ulp_v = this->findParent(v);
    
        if(SIZE[ulp_u] > SIZE[ulp_v]){
            parent[ulp_v] = ulp_u;
            SIZE[ulp_u] += SIZE[ulp_v];
            SIZE[ulp_v] = 0;
        }else if(SIZE[ulp_v] > SIZE[ulp_u]){
            parent[ulp_u] = ulp_v;
            SIZE[ulp_v] += SIZE[ulp_u];
            SIZE[ulp_u] = 0;
        }else{  
            parent[ulp_u] = ulp_v;
            SIZE[ulp_v] += SIZE[ulp_u];
            SIZE[ulp_u] = 0;
        }
    }

    int getMaxStoneSize(){
        int ans = 0;
        for(auto e : SIZE){
            if(e != 0)
                ans += (e - 1);
        }
        return ans;        
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        DisJoint *ds = new DisJoint(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    if(ds->findParent(i) != ds->findParent(j))
                        ds->unionMerge(i, j);
                }
            }
        }

        return ds->getMaxStoneSize();
    }
};