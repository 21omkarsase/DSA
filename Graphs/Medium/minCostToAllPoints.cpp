// 1584. Min Cost to Connect All Points
// Medium
// 3.6K
// 84
// Companies

// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

// Example 1:

// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation: 

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.

// Example 2:

// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18

 

// Constraints:

//     1 <= points.length <= 1000
//     -106 <= xi, yi <= 106
//     All pairs (xi, yi) are distinct.

// Accepted
// 161.3K
// Submissions
// 251.8K
// Acceptance Rate
// 64.1%

vector<int> SIZE;
vector<int> parent;

class Solution {
    int findParent(int node){
        if(node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(SIZE[ulp_u] > SIZE[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else if(SIZE[ulp_v] > SIZE[ulp_u]){
            parent[ulp_u] = ulp_v;
        }else{
            parent[ulp_u] = ulp_v;
            SIZE[ulp_v] += SIZE[ulp_u];
        }
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> minHeap;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    int dist = abs(points[i][0] - points[j][0]) + abs(points[j][1] - points[i][1]);
                    minHeap.push_back({dist , {i, j}});
                }
            }
        }

        sort(minHeap.begin(), minHeap.end());
        
        SIZE.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        int mstCost = 0;
        for(auto edge : minHeap){
            int w = edge.first, u = edge.second.first, v = edge.second.second;
            if(findParent(u) != findParent(v)){
                mstCost += w;
                unionBySize(u, v);
            }
        }
        
        return mstCost;
    }
};













