// 1254. Number of Closed Islands
// Medium
// 4.2K
// 138
// Companies

// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

// Return the number of closed islands.

 

// Example 1:

// Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation: 
// Islands in gray are closed because they are completely surrounded by water (group of 1s).

// Example 2:

// Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// Output: 1

// Example 3:

// Input: grid = [[1,1,1,1,1,1,1],
//                [1,0,0,0,0,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,1,0,1,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,0,0,0,0,1],
//                [1,1,1,1,1,1,1]]
// Output: 2

 

// Constraints:

//     1 <= grid.length, grid[0].length <= 100
//     0 <= grid[i][j] <=1

// Accepted
// 190.7K
// Submissions
// 284.8K
// Acceptance Rate
// 66.9%

// ******************************using bfs dfs*********************************

class Solution {
    void dfs(int row, int col, int n , int m , vector<vector<int>> &grid){
        grid[row][col] = 1;                        

        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(abs(i) != abs(j)){
                    int nrow = row + i, ncol = col + j;
                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 0){
                        dfs(nrow, ncol, n, m, grid);
                    }
                }
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n - 1 || j == m -1){
                    if(grid[i][j] == 0){
                        grid[i][j] = 1;
                        dfs(i, j, n, m, grid);
                    }
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    cnt++;
                    dfs(i, j, n, m, grid);
                }
            }
        }

        return cnt;
    }
};

// The time complexity of the given code can be analyzed as follows:

//     The outer loop iterates over each row, and the inner loop iterates over each column of the grid. Therefore, the nested loops contribute a time complexity of O(n * m), where n is the number of rows and m is the number of columns in the grid.

//     Inside the nested loops, there is a DFS (depth-first search) function call. The DFS function is recursively called for each cell that satisfies certain conditions. In the worst case, the DFS function can traverse through all the cells of the grid. Since each cell is visited once, the time complexity of the DFS function is O(n * m).

//     Overall, the code performs two DFS calls. The first DFS call is made for the boundary cells, and the second DFS call is made for the remaining cells that are not connected to the boundary. Therefore, the total time complexity of the code is O(n * m + n * m) = O(n * m).

// The space complexity of the given code can be analyzed as follows:

//     The space complexity of the DFS function is determined by the maximum depth of the recursion stack. In the worst case, the DFS function can reach a depth of O(n * m) when it visits all the cells. Therefore, the space complexity of the DFS function is O(n * m).

//     Apart from the DFS function, the code uses additional space to store the grid and other variables. The space required to store the grid is O(n * m) since it has n rows and m columns. The other variables used in the code have constant space requirements.

//     Therefore, the total space complexity of the code is O(n * m + n * m) = O(n * m).

// In summary, the time complexity of the code is O(n * m), and the space complexity is also O(n * m).

// ***********************************using union find********************************
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
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        Disjoint *ds = new Disjoint((m * n) + 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j])
                    continue;
                if(i == 0 || j == 0 || i == n - 1 || j == m -1){
                    ds->unionMerge(m * n, (m * i) + j);
                }else{
                    for(int row = -1; row <= 1; row++){
                        for(int col = -1; col <= 1; col++){
                            if(abs(row) != abs(col)){
                                int nrow = row + i, ncol = col + j;
                                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !grid[nrow][ncol]){
                                    ds->unionMerge((m * i) + j, (m * nrow) + ncol);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        int boundaryPar = ds->findParent(m * n);
        unordered_set<int> cloIslands;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int currParent = ds->findParent((m * i) + j);
                if(grid[i][j] == 0 && currParent != boundaryPar)
                    cloIslands.insert(currParent);
            }
        }

        return cloIslands.size();
    }
};














































