// 84. Largest Rectangle in Histogram
// Hard
// 14.6K
// 207
// Companies

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Example 2:

// Input: heights = [2,4]
// Output: 4

 

// Constraints:

//     1 <= heights.length <= 105
//     0 <= heights[i] <= 104

// Accepted
// 685.4K
// Submissions
// 1.6M
// Acceptance Rate
// 42.9%



// Time Complexity : O(N) + O(N)
// Space Complexity : O(N)


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        int maxArea = 0;
        stack<int> st;

        for (int idx = 0; idx <= n; idx++) {
            while (!st.empty() && (idx == n || heights[st.top()] > heights[idx])) {
                int topHeight = heights[st.top()];
                st.pop();
                
                int leftIdx = st.empty() ? -1 : st.top();
                int area = topHeight * (idx - leftIdx - 1);
                maxArea = max (maxArea, area);
            }

            st.push(idx);
        }

        return maxArea;
    }
};


// Time Complexity : 2(O(N) + O(N))
// Space Complexity : O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> lsArray(n, 0), rsArray(n, 0);
        stack<int> st;

        // O(N) for stack (Each element will be pushed onto the stack exactly once.)

        for (int idx = 0; idx < n; idx++) {                                 // O(N)
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
};





