// 1091. Shortest Path in Binary Matrix
// Medium
// 5.8K
// 204
// Companies

// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

//     All the visited cells of the path are 0.
//     All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

// The length of a clear path is the number of visited cells of this path.

 

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 2

// Example 2:

// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4

// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1

 

// Constraints:

//     n == grid.length
//     n == grid[i].length
//     1 <= n <= 100
//     grid[i][j] is 0 or 1

// Accepted
// 369.7K
// Submissions
// 796.7K
// Acceptance Rate
// 46.4%

// Time Complexity : O(N*M)
// Space Complexity : O(N*M)

class Solution {
    bool isValid(int row, int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &visited) {
        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 1 || visited[row][col] == 1)
            return false;
        
        return true;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if (grid[0][0] == 1)
            return -1;

        int level = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        q.push({0, 0});
        
        visited[0][0] = 1;

        while (!q.empty()) {
            int k = q.size();
            level++;

            while (k--) {
                int row = q.front().first, col = q.front().second;
                q.pop();

                if (row == n - 1 && col == m - 1) {
                    return level;
                }

                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        int nRow = row + i, nCol = col + j;

                        if (isValid(nRow, nCol, n, m, grid, visited)) {
                            q.push({nRow, nCol});
                            visited[nRow][nCol] = 1;
                        }
                    }
                }
            }
        }

        return -1;
    }
};