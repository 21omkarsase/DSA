// 1351. Count Negative Numbers in a Sorted Matrix
// Easy
// 3.3K
// 93
// Companies

// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

// Example 1:

// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.

// Example 2:

// Input: grid = [[3,2],[1,0]]
// Output: 0

 

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 100
//     -100 <= grid[i][j] <= 100

 
// Follow up: Could you find an O(n + m) solution?
// Accepted
// 249.6K
// Submissions
// 330.3K
// Acceptance Rate
// 75.5%
// Seen this question in a real interview before?
// 1/4

class Solution {
    int getNegNumCount(int row, int n, vector<vector<int>>& grid){
        int st = 0, en = n - 1;

        while(st <= en){
            int mid = (st + en) / 2;
            if(grid[row][mid] < 0)
                en = mid - 1;
            else st = mid + 1;
        }

        return n - st;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for(int i = 0; i < n; i++){
            count += getNegNumCount(i, m, grid);
        }
        
        return count;
    }
};



// Time complexity: O(mlog⁡n)O(m \log n)O(mlogn)
//     For each row of the matrix we perform a binary search which will take O(log⁡n)O(\log n)O(logn) time.
//     Thus, for mmm rows, overall we will take O(mlog⁡n)O(m \log n)O(mlogn) time.
// Space complexity: O(1)O(1)O(1)
//     We don't use any additional space.


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for(int i = 0; i < n; i++){
            int idx = upper_bound(grid[i].begin(), grid[i].end(), 0, greater<int>()) - grid[i].begin();
            count += (m - idx);
        }
        
        return count;
    }
};

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0, lastNegIdx = m - 1;

        for(vector<int> row : grid){
            while(lastNegIdx >= 0 && row[lastNegIdx] < 0)
                lastNegIdx--;
            
            count += (m - (lastNegIdx + 1));
        }
        
        return count;
    }
};