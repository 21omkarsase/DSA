// 37. Sudoku Solver
// Hard
// 8.5K
// 220
// Companies

// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

//     Each of the digits 1-9 must occur exactly once in each row.
//     Each of the digits 1-9 must occur exactly once in each column.
//     Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

// The '.' character indicates empty cells.

 

// Example 1:

// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:


 

// Constraints:

//     board.length == 9
//     board[i].length == 9
//     board[i][j] is a digit or '.'.
//     It is guaranteed that the input board has only one solution.

// Accepted
// 486.5K
// Submissions
// 827.5K
// Acceptance Rate
// 58.8%

// Time Complexity : 9 ^ (N*N)
// Space Complexity : O(N^2)


// isValid : O(9)
// inner loop : O(9 * N)  => O(N^2) (usually N : 9)
// depth of recursion : N ^ 2

// total : O(9 ^ (N^2))

class Solution {
    bool isValid(int num, int x, int y, int n, vector<vector<char>> &grid) {
        for (int col = 0; col < n; col++) {
            if (col != y && grid[x][col] == num) {
                return false;
            }
        }
        
        for (int row = 0; row < n; row++) {
            if (row != x && grid[row][y] == num) {
                return false;
            }
        }
        
        int startRow = x - (x % 3), startCol = y - (y % 3);
        
        for (int row = startRow; row < startRow + 3; row++) {
            for (int col = startCol; col < startCol + 3; col++) {
                if (row != x && col != y && grid[row][col] == num) {
                    return false;
                }
            }
        }
    
        return true;    
    }

    bool isPossibleToSolve(int idx, int n, vector<vector<char>>& grid) {
        int x = idx / n, y = idx % n;
        if (idx == n * n) {
            return true;
        }
        
        if (grid[x][y] == '.') {
            for (int num = '1'; num <= '9'; num++) {
                if (isValid(num, x, y, n, grid)) {
                    grid[x][y] = num;
                    
                    if (isPossibleToSolve(idx + 1, n, grid)) {
                        return true;
                    }
                    
                    grid[x][y] = '.';
                }
            }
        }
        else {
            if (isPossibleToSolve(idx + 1, n, grid)) {
                return true;
            }
        }
        
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        isPossibleToSolve(0, board.size(), board);
    }
};