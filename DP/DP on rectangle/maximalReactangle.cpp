// 85. Maximal Rectangle
// Hard
// 8.8K
// 140
// Companies

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.

// Example 2:

// Input: matrix = [["0"]]
// Output: 0

// Example 3:

// Input: matrix = [["1"]]
// Output: 1

 

// Constraints:

//     rows == matrix.length
//     cols == matrix[i].length
//     1 <= row, cols <= 200
//     matrix[i][j] is '0' or '1'.

// Accepted
// 349.5K
// Submissions
// 774.4K
// Acceptance Rate
// 45.1%

// Time Complexity  : O(N^3)
// Space Complexity  : O(N)


class Solution {
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int maxArea = 0;
        stack<int> st;

        for (int idx = 0; idx <= n; idx++) {
            while (!st.empty() && (idx == n || heights[st.top()] > heights[idx])) {
                int topHeight = heights[st.top()];
                st.pop();

                int leftSmallerEleIdx = st.empty() ? -1 : st.top();
                int area = topHeight * (idx - leftSmallerEleIdx - 1);
                maxArea = max(maxArea, area);
            }

            st.push(idx);
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<int> histogram(m, 0);
        int maxRectangleArea = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                histogram[col] = matrix[row][col] == '1' ? histogram[col] + 1 : 0;
            }

            mllllaxRectangleArea = max(maxRectangleArea, largestRectangleArea(histogram));
        }

        return maxRectangleArea;
    }
};

class Solution {
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> lsArray(n, 0), rsArray(n, 0);
        stack<int> st;

        for (int idx = 0; idx < n; idx++) {
            while (!st.empty() && heights[st.top()] >= heights[idx])
                st.pop();
            
            lsArray[idx] = st.empty() ? -1 : st.top();

            st.push(idx);
        }

        while (!st.empty())
            st.pop();

        int maxArea = 0;
        for (int idx = n - 1; idx >= 0; idx--) {
            while (!st.empty() && heights[st.top()] >= heights[idx])
                st.pop();
            
            rsArray[idx] = st.empty() ? n : st.top();
            int area = (rsArray[idx] - lsArray[idx] - 1) * heights[idx];
            maxArea = max(maxArea, area);

            st.push(idx);
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<int> histogram(m, 0);
        int maxRectangleArea = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                histogram[col] = matrix[row][col] == '1' ? histogram[col] + 1 : 0;
            }

            maxRectangleArea = max(maxRectangleArea, largestRectangleArea(histogram));
        }

        return maxRectangleArea;
    }
};