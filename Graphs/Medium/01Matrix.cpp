// 542. 01 Matrix
// Medium
// 7.3K
// 338
// Companies

// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

 

// Example 1:

// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]

// Example 2:

// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]

 

// Constraints:

//     m == mat.length
//     n == mat[i].length
//     1 <= m, n <= 104
//     1 <= m * n <= 104
//     mat[i][j] is either 0 or 1.
//     There is at least one 0 in mat.

// Accepted
// 394.6K
// Submissions
// 873.8K
// Acceptance Rate
// 45.2%


// Time Complexity : O(N * M)
// Space Complexity : O(N * M)

class Solution {
    bool isValidCell(int row, int col, int n, int m) {
        return row >= 0 && col >= 0 && row < n && col < m; 
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        
        
        queue<pair<int, pair<int, int>>> q;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (mat[row][col] == 0) {
                    visited[row][col] = 1;
                    q.push({0, {row, col}});
                }
            }
        }

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int row = it.second.first;
            int col = it.second.second;
            int dist = it.first;

            distance[row][col] = dist;

            for (int dir1 = -1; dir1 <= 1; dir1++) {
                for (int dir2 = -1; dir2 <= 1; dir2++) {
                    if (abs(dir1) != abs(dir2)) {
                        int nRow = row + dir1, nCol = col + dir2;

                        if (isValidCell(nRow, nCol, n, m) && visited[nRow][nCol] == 0) {
                            visited[nRow][nCol] = 1;
                            q.push({dist + 1, {nRow, nCol}});
                        }
                    }
                }
            }
        }

        return distance;
    }
};













