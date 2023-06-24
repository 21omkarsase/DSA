// 1277. Count Square Submatrices with All Ones
// Medium
// 4.4K
// 71
// Companies

// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.

// Example 2:

// Input: matrix = 
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7
// Explanation: 
// There are 6 squares of side 1.  
// There is 1 square of side 2. 
// Total number of squares = 6 + 1 = 7.

 

// Constraints:

//     1 <= arr.length <= 300
//     1 <= arr[0].length <= 300
//     0 <= arr[i][j] <= 1

// Accepted
// 197.1K
// Submissions
// 264.2K
// Acceptance Rate
// 74.6%

// Time Complexity  : O(N^2)
// Space Complexity  : O(N^2)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        int totalSubMatrices = 0;
        vector<vector<int>> dp = matrix;

        for (int row = 1; row < n; row++) 
            for (int col = 1; col < m; col++) 
                if (matrix[row][col])
                    dp[row][col] = min(dp[row - 1][col], min(dp[row][col - 1], dp[row - 1][col - 1])) + 1;
        
        for (int row = 0; row < n; row++)
            totalSubMatrices += (accumulate(dp[row].begin(), dp[row].end(), 0));

        return totalSubMatrices;
    }
};