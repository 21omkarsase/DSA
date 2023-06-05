// 329. Longest Increasing Path in a Matrix
// Hard
// 8.1K
// 119
// Companies

// Given an m x n integers matrix, return the length of the longest increasing path in matrix.

// From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

// Example 1:

// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].

// Example 2:

// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

// Example 3:

// Input: matrix = [[1]]
// Output: 1

 

// Constraints:

//     m == matrix.length
//     n == matrix[i].length
//     1 <= m, n <= 200
//     0 <= matrix[i][j] <= 231 - 1

// Accepted
// 447.2K
// Submissions
// 851.1K
// Acceptance Rate
// 52.5%


class Solution {
    int getLIP(vector<vector<int>>& matrix, int mx, int r, int c, int n, int m){
        if(n == 1 && m == 1)
            return 1;

        if(n < 0 || m < 0)
            return 0;

        int take = 0;
        if(matrix[r][c] > mx){
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(abs(i) != abs(j)){
                        int row = r + i, col = c + j;
                        if(row >= 0 && col >= 0 && row < n && col < m){
                            int count = getLIP(matrix, matrix[r][c], row, col, n, m) + 1;
                            take = max(take, count);
                        }
                    }
                }
            }
        }
        return take;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, getLIP(matrix, INT_MIN, i, j, n, m));
            }
        }

        return ans;
    }
};

class Solution {
    int getLIP(vector<vector<int>>& matrix, vector<vector<int>> &dp, int r, int c, int n, int m){
        if(dp[r][c] != -1)
            return dp[r][c];
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int mx = 1;
        for (auto dir : directions) {
            int newRow = r + dir.first;
            int newCol = c + dir.second;

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && matrix[newRow][newCol] > matrix[r][c]) {
                mx = max(mx, getLIP(matrix, dp, newRow, newCol, n, m) + 1);
            }
        }
        return dp[r][c] = mx;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return 0;

        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, getLIP(matrix, dp, i, j, n, m));
            }
        }

        return ans;
    }
};