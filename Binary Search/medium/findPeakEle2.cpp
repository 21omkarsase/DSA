// 1901. Find a Peak Element II
// Medium
// 1.5K
// 101
// Companies

// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

// Example 1:

// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

// Example 2:

// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

 

// Constraints:

//     m == mat.length
//     n == mat[i].length
//     1 <= m, n <= 500
//     1 <= mat[i][j] <= 105
//     No two adjacent cells are equal.

// Accepted
// 39.4K
// Submissions
// 76.1K
// Acceptance Rate
// 51.8%

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int st = 0, en = n - 1;

        while(st <= en) {
            int mid = st + (en - st) / 2;
            
            int c = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            int val = mat[mid][c];

            if (mid == 0) {
                if (val > mat[mid + 1][c]) 
                    return {mid, c};
                else st = mid + 1;
            }
            else if (mid == n - 1) {
                if (val > mat[mid - 1][c]) 
                    return {mid, c};
                else en = mid - 1;
            }
            else{
                if (val > mat[mid + 1][c] && val > mat[mid - 1][c]) 
                    return {mid, c};
                else if (mat[mid + 1][c] > val)
                    st = mid + 1;
                else
                    en = mid - 1;
            }
        }

        return {-1, -1};
    }
};
    