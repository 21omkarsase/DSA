// 240. Search a 2D Matrix II
// Medium
// 10.5K
// 174
// Companies

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

//     Integers in each row are sorted in ascending from left to right.
//     Integers in each column are sorted in ascending from top to bottom.

 

// Example 1:

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true

// Example 2:

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false

 

// Constraints:

//     m == matrix.length
//     n == matrix[i].length
//     1 <= n, m <= 300
//     -109 <= matrix[i][j] <= 109
//     All the integers in each row are sorted in ascending order.
//     All the integers in each column are sorted in ascending order.
//     -109 <= target <= 109

// Accepted
// 795.2K
// Submissions
// 1.6M
// Acceptance Rate
// 51.2%

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m - 1;

        int curr;
        while(row < n){
            curr = matrix[row][col];

            if(curr == target)
                return true;
            
            if(curr > target){
                while(col > 0 && matrix[row][col] > target){
                    col--;
                }

                if(col >= 0 && col < m && matrix[row][col] == target)
                    return true;
                else row++;
            }else{
                while(col < m - 1 && matrix[row][col] < target){
                    col++;
                }

                if(col >= 0 && col < m - 1 && matrix[row][col] == target)
                    return true;
                else row++;
            }
        }

        return false;
    }
};