// 934. Shortest Bridge
// Medium
// 4.8K
// 181
// Companies

// You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

// An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

// You may change 0's to 1's to connect the two islands to form one island.

// Return the smallest number of 0's you must flip to connect the two islands.

 

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 1

// Example 2:

// Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2

// Example 3:

// Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1

 

// Constraints:

//     n == grid.length == grid[i].length
//     2 <= n <= 100
//     grid[i][j] is either 0 or 1.
//     There are exactly two islands in grid.

// Accepted
// 169.9K
// Submissions
// 294K
// Acceptance Rate
// 57.8%

class Solution {
    void dfs(vector<vector<int>>& grid, vector<pair<int, int>> &island, int  r, int c, int n){
        grid[r][c] = 0;
        island.push_back({r, c});

        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                if(abs(i) != abs(j)){
                    int row = r + i, col = c + j;
                    if(row >= 0 && col >= 0 && row < n && col < n && grid[row][col]){
                        dfs(grid, island, row, col, n);
                    }
                }
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        bool flag = true;
        vector<pair<int, int>> island1, island2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    if(flag) dfs(grid, island1, i, j, n);
                    else dfs(grid, island2, i, j, n);
                    flag = false;
                }
            }
        }

        if(island1.size() > island2.size()){
            swap(island1, island2);
        }
        
        int l1 = island1.size(), l2 = island2.size();
        int ans = INT_MAX;
        for(int i = 0; i < l1; i++){
            for(int j = 0; j < l2; j++){
                int x = abs(island2[j].first - island1[i].first);
                int y = abs(island2[j].second - island1[i].second);
                ans = min(ans, x + y);
            }
        }

        return ans - 1;
    }
};
