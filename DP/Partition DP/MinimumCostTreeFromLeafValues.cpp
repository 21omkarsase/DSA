// 1130. Minimum Cost Tree From Leaf Values
// Medium
// 4K
// 258
// Companies

// Given an array arr of positive integers, consider all binary trees such that:

//     Each node has either 0 or 2 children;
//     The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
//     The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.

// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

// A node is a leaf if and only if it has zero children.

 

// Example 1:

// Input: arr = [6,2,4]
// Output: 32
// Explanation: There are two possible trees shown.
// The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

// Example 2:

// Input: arr = [4,11]
// Output: 44

 

// Constraints:

//     2 <= arr.length <= 40
//     1 <= arr[i] <= 15
//     It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).

// Accepted
// 87.6K
// Submissions
// 128.6K
// Acceptance Rate
// 68.1%

// Time Complexity : O(N^3)
// Space Complexity : O(N^2) + O(N + N)

class Solution {
    int calculateMct(int start, int end, vector<int> &arr, vector<vector<int>> &dp) {
        if (start == end) 
            return 0;

        if (dp[start][end] != -1) 
            return dp[start][end];

        int sum = INT_MAX;
        int mxLeft = INT_MIN;

        for (int k = start; k < end; k++) {
            mxLeft = max(mxLeft, arr[k]);
            int mxRight = INT_MIN;

            for (int idx = k + 1; idx <= end; idx++) 
                mxRight = max(mxRight, arr[idx]);

            int ans = mxLeft * mxRight + calculateMct(start, k, arr, dp) + calculateMct(k + 1, end, arr, dp);
            
            sum = min(sum, ans);
        }

        return dp[start][end] = sum;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return calculateMct(0, n - 1, arr, dp);
    }
};


// Time Complexity : O(N^3)
// Space Complexity : O(N^2) 

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int start = n - 1; start >= 0; start--) {
            for (int end = start; end < n; end++) {
                if (start == end) {
                    dp[start][end] == 0;
                } else {
                    int sum = INT_MAX;
                    int mxLeft = INT_MIN;

                    for (int k = start; k < end; k++) {
                        mxLeft = max(mxLeft, arr[k]);
                        int mxRight = INT_MIN;

                        for (int idx = k + 1; idx <= end; idx++) 
                            mxRight = max(mxRight, arr[idx]);

                        int ans = mxLeft * mxRight + dp[start][k] + dp[k + 1][end];
                        
                        sum = min(sum, ans);
                    }

                    dp[start][end] = sum;
                }
            }
        }

        return dp[0][n - 1];
    }
};


//using stack

// Time Complexity : O(N)
// Space Complexity : O(N)

// store ele in non - incresing order
// if we encounter num greater than stack top
// we will add multiplication of two smallest no. we have including stack and curr ele
// if we don't get any greater ele than st top
// we will keep on multiplying smallest ele from top of the stack

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        stack<int> st;

        for (int idx = 0; idx < n; idx++) {
            while (!st.empty() && arr[st.top()] < arr[idx]) {
                int currTop = arr[st.top()];
                st.pop();

                if (st.empty())
                    sum += (arr[idx] * currTop);
                else 
                    sum += (currTop* min(arr[st.top()], arr[idx]));
            }

            st.push(idx);
        }

        while (!st.empty()) {
            int currTop = arr[st.top()];
            st.pop();

            if (!st.empty()) {
                sum += (currTop * arr[st.top()]);
            }
        }

        return sum;
    }
};