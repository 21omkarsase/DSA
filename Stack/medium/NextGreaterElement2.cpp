// 503. Next Greater Element II
// Medium
// 7K
// 173
// Companies

// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

// Example 2:

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

 

// Constraints:

//     1 <= nums.length <= 104
//     -109 <= nums[i] <= 109

// Accepted
// 318.3K
// Submissions
// 502.8K
// Acceptance Rate
// 63.3%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n, -1);
        stack<int> st;

        for (int idx = 0; idx < n; idx++) {
            while(!st.empty() && nums[st.top()] < nums[idx]) {
                ans[st.top()] = nums[idx];
                st.pop();
            }

            st.push(idx);
        }

        for (int idx = 0; idx < n; idx++) {
            if (st.size() == 1) {
                break;
            }

            while(!st.empty() && nums[st.top()] < nums[idx]) {
                ans[st.top()] = nums[idx];
                st.pop();
            }

            if (ans[idx] == -1)
                st.push(idx);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n, -1);
        stack<int> st;

        for (int it = 0; it < (2 * n); it++) {
            int idx = it % n;

            while(!st.empty() && nums[st.top()] < nums[idx]) {
                ans[st.top()] = nums[idx];
                st.pop();
            }

            if (ans[idx] == -1)
                st.push(idx);
            else if (st.size() == 1) 
                break;
        }

        return ans;
    }
};