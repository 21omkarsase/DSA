// 1314. Matrix Block Sum
// Medium
// 2.2K
// 342
// Companies

// Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

//     i - k <= r <= i + k,
//     j - k <= c <= j + k, and
//     (r, c) is a valid position in the matrix.

 

// Example 1:

// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// Output: [[12,21,16],[27,45,33],[24,39,28]]

// Example 2:

// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
// Output: [[45,45,45],[45,45,45],[45,45,45]]

 

// Constraints:

//     m == mat.length
//     n == mat[i].length
//     1 <= m, n, k <= 100
//     1 <= mat[i][j] <= 100

// Accepted
// 79.1K
// Submissions
// 104.8K
// Acceptance Rate
// 75.5%

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        for (int col = 1; col < m; col++)
            mat[0][col] += mat[0][col - 1];
        
        for (int row = 1; row < n; row++)
            mat[row][0] += mat[row - 1][0];

        for (int row = 1; row < n; row++) 
            for (int col = 1; col < m; col++) 
                mat[row][col] += mat[row - 1][col] + mat[row][col - 1] - mat[row - 1][col - 1];
                
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                int startRow = max(0, row - k), startCol = max(0, col - k); 
                int endRow = min(n - 1, row + k), endCol = min(m - 1, col + k); 

                dp[row][col] = mat[endRow][endCol];

                if (startRow - 1 >= 0)
                   dp[row][col] -= mat[startRow - 1][endCol];

                if(startCol - 1 >= 0)
                    dp[row][col] -= mat[endRow][startCol - 1];

                if(startCol - 1 >= 0 && startRow - 1 >= 0)
                    dp[row][col] += mat[startRow - 1][startCol - 1];
            }
        }

        return dp;
    }
};