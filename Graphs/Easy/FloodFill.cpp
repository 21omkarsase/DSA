// 733. Flood Fill
// Easy
// 7.4K
// 728
// Companies

// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

// Return the modified image after performing the flood fill.

 

// Example 1:

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

// Example 2:

// Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
// Output: [[0,0,0],[0,0,0]]
// Explanation: The starting pixel is already colored 0, so no changes are made to the image.

 

// Constraints:

//     m == image.length
//     n == image[i].length
//     1 <= m, n <= 50
//     0 <= image[i][j], color < 216
//     0 <= sr < m
//     0 <= sc < n

// Accepted
// 739.5K
// Submissions
// 1.2M
// Acceptance Rate
// 62.5%

// Time Complexity : O(N)  N -> number of pixels in grid;
// Space Complexity : O(N)  dfs call stack space

class Solution {
    void dfs(int row, int col, int n, int m, int parent, int color, vector<vector<int>> &image) {
        image[row][col] = color;
        
        for (int idx1 = -1; idx1 <= 1; idx1++) {
            for (int idx2 = -1; idx2 <= 1; idx2++) {
                if (abs(idx1) != abs(idx2)) {
                    int nRow = row + idx1, nCol = col + idx2;

                    if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && image[nRow][nCol] == parent && image[nRow][nCol] != color) {
                        dfs(nRow, nCol, n, m, parent, color, image);
                    }
                }
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        
        dfs(sr, sc, n, m, image[sr][sc], color, image);

        return image;
    }
};