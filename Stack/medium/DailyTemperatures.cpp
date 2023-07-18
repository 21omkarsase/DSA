// 739. Daily Temperatures
// Medium
// 11.1K
// 245
// Companies

// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]

 

// Constraints:

//     1 <= temperatures.length <= 105
//     30 <= temperatures[i] <= 100

// Accepted
// 643.5K
// Submissions
// 973.4K
// Acceptance Rate
// 66.1%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        vector<int> ans(n, 0);
        stack<int> st;

        for (int idx = 0; idx < n; idx++) {
            while(!st.empty() && temperatures[st.top()] < temperatures[idx]) {
                ans[st.top()] = idx - st.top();
                st.pop();
            }

            st.push(idx);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        vector<int> ans(n, 0);
        stack<int> st;

        for (int idx = n - 1; idx >= 0; idx--) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[idx]) {
                st.pop();
            }

            if (!st.empty())
                ans[idx] = st.top() - idx;

            st.push(idx);
        }

        return ans;
    }
};