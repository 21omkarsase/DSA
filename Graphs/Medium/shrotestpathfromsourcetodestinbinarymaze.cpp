// Shortest Distance in a Binary Maze
// MediumAccuracy: 58.22%Submissions: 19K+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation  

// Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

// If the path is not possible between source cell and destination cell, then return -1.

// Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right.

// Example 1:

// Input:
// grid[][] = {{1, 1, 1, 1},
//             {1, 1, 0, 1},
//             {1, 1, 1, 1},
//             {1, 1, 0, 0},
//             {1, 0, 0, 1}}
// source = {0, 1}
// destination = {2, 2}
// Output:
// 3
// Explanation:
// 1 1 1 1
// 1 1 0 1
// 1 1 1 1
// 1 1 0 0
// 1 0 0 1
// The highlighted part in the matrix denotes the 
// shortest path from source to destination cell.

// Example 2:

// Input:
// grid[][] = {{1, 1, 1, 1, 1},
//             {1, 1, 1, 1, 1},
//             {1, 1, 1, 1, 0},
//             {1, 0, 1, 0, 1}}
// source = {0, 0}
// destination = {3, 4}
// Output:
// -1
// Explanation:
// The path is not possible between source and 
// destination, hence return -1.

// Your Task:

// You don't need to read or print anything. Your task is to complete the function shortestPath() which takes the a 2D integer array grid, source cell and destination cell as an input parameters and returns the shortest distance between source and destination cell.

// Expected Time Complexity: O(n * m)
// Expected Space Complexity: O(n * m)

// Constraints:

//     1 ≤ n, m ≤ 500
//     grid[i][j] == 0 or grid[i][j] == 1
//     The source and destination cells are always inside the given matrix.
//     The source and destination cells always contain 1.

// Time Complexity : O(N*M)
// Space Complexity : O(N*M)

class Solution {
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if (A[0][0] == 0) {
            return -1;
        }
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> visited(N, vector<int>(M, 0));
        
        q.push({0, {0, 0}});
        visited[0][0] = 1;
        
        while (!q.empty()) {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
            if (row == X && col == Y) {
                return dist;
            }
            
            for (auto dir: dirs) {
                int nRow = row + dir.first, nCol = dir.second + col;
                
                if (isValid(nRow, nCol, N, M) && visited[nRow][nCol] == 0 && A[nRow][nCol] == 1) {
                    q.push({dist + 1, {nRow, nCol}});
                    visited[nRow][nCol] = 1;
                }
            }
        }
        
        return -1;
    }
};