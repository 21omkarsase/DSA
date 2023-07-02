// 1020. Number of Enclaves
// Medium
// 3.5K
// 66
// Companies

// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

// Example 1:

// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

// Example 2:

// Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// Output: 0
// Explanation: All 1s are either on the boundary or can reach the boundary.

 

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 500
//     grid[i][j] is either 0 or 1.

// Accepted
// 167.3K
// Submissions
// 243.5K
// Acceptance Rate
// 68.7%

// Time Complexity : O(N * M) 
// Space Complexity : O(N * M)

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
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        Disjoint *ds = new Disjoint(n * m + 1);

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) {
                    if (row == 0 || col == 0 || row == n - 1 || col == m - 1) {
                        ds->unionMerge((n * m), (m * row) + col);
                    } else {
                        for (int i = -1; i <= 1; i++) {
                            for (int j = -1; j <= 1; j++) {
                                if (abs(i) != abs(j)) {
                                    int nRow = row + i, nCol = col + j;

                                    if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && grid[nRow][nCol] == 1) {
                                        ds->unionMerge((m * row) + col , (m * nRow) + nCol);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        int boundaryPar = ds->findParent(n * m);
        int enclavesCount = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) {
                    int currPar = ds->findParent((m * row) + col);
                    
                    if (boundaryPar != currPar)
                        enclavesCount++;
                }
            }
        }

        return enclavesCount; 
    }
};


















