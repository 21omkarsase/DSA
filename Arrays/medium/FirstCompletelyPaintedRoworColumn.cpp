// 2661. First Completely Painted Row or Column
// Medium
// 315
// 5
// Companies

// You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

// Return the smallest index i at which either a row or a column will be completely painted in mat.

 

// Example 1:
// image explanation for example 1

// Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
// Output: 2
// Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].

// Example 2:
// image explanation for example 2

// Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
// Output: 3
// Explanation: The second column becomes fully painted at arr[3].

 

// Constraints:

//     m == mat.length
//     n = mat[i].length
//     arr.length == m * n
//     1 <= m, n <= 105
//     1 <= m * n <= 105
//     1 <= arr[i], mat[r][c] <= m * n
//     All the integers of arr are unique.
//     All the integers of mat are unique.

// Accepted
// 17.2K
// Submissions
// 34.3K
// Acceptance Rate
// 50.2%

// Time Complexity : O(N*M)
// Space Complexity : O(N*M)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        unordered_map<int, pair<int, int>> tracker;
        vector<int> rowsPaintedCount(n, 0), colsPaintedCount(m, 0);
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                tracker[mat[row][col]] = {row, col};
            }
        }
        
        for (int idx = 0; idx < (m * n); idx++) {
            int row = tracker[arr[idx]].first, col = tracker[arr[idx]].second;
            
            rowsPaintedCount[row]++;
            colsPaintedCount[col]++;
            
            if (rowsPaintedCount[row] >= m || colsPaintedCount[col] >= n)
                return idx;            
        }

        return m * n - 1;
    }
};