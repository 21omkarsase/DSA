// 1738. Find Kth Largest XOR Coordinate Value
// Medium
// 456
// 66
// Companies

// You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.

// The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).

// Find the kth largest value (1-indexed) of all the coordinates of matrix.

 

// Example 1:

// Input: matrix = [[5,2],[1,6]], k = 1
// Output: 7
// Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.

// Example 2:

// Input: matrix = [[5,2],[1,6]], k = 2
// Output: 5
// Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.

// Example 3:

// Input: matrix = [[5,2],[1,6]], k = 3
// Output: 4
// Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.

 

// Constraints:

//     m == matrix.length
//     n == matrix[i].length
//     1 <= m, n <= 1000
//     0 <= matrix[i][j] <= 106
//     1 <= k <= m * n

// Accepted
// 19.1K
// Submissions
// 31.2K
// Acceptance Rate
// 61.1%


// Time Complexity : O(N * M(Log(no of ele present in pq at time of insertion)))
// Space Complexity : O(N * M)

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        
        priority_queue<int> pq;
        vector<vector<int>> xors(n + 1, vector<int>(m + 1, 0));

        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= m; col++) {
                xors[row][col] = matrix[row - 1][col - 1] ^ xors[row - 1][col] ^ xors[row][col - 1] ^ xors[row - 1][col - 1];
                pq.push(xors[row][col]);
            }
        }

        k--;

        while (k--) {
            pq.pop();
        }

        return pq.top();
    }
};