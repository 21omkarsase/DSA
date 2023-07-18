// 496. Next Greater Element I
// Easy
// 6.4K
// 463
// Companies

// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

 

// Constraints:

//     1 <= nums1.length <= nums2.length <= 1000
//     0 <= nums1[i], nums2[i] <= 104
//     All integers in nums1 and nums2 are unique.
//     All the integers of nums1 also appear in nums2.

 
// Follow up: Could you find an O(nums1.length + nums2.length) solution?
// Accepted
// 547.8K
// Submissions
// 766.7K
// Acceptance Rate
// 71.5%

// Time Complexity : O(N + M)
// Space Complexity : O(N)

// we will store next greater element of every element of nums in hash table
// to get next greater element we will store numbers in stack in decreasing order (till we encounter num greater than top)
// if top is lesser than curr -> for every stack ele lesser than curr -> curr is nge
// push curr in to stack

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        stack<int> st;
        unordered_map<int, int> tracker;

        for (int idx = 0; idx < m; idx++) {
            if (st.empty()) {
                st.push(nums2[idx]);
                continue;
            }

            while(!st.empty() && st.top() < nums2[idx]) {
                tracker[st.top()] = nums2[idx];
                st.pop();
            }

            st.push(nums2[idx]);
        }

        vector<int> nge(n, -1);

        for (int idx = 0; idx < n; idx++) {
            if (tracker.find(nums1[idx]) != tracker.end())
                nge[idx] = tracker[nums1[idx]];
            else
                nge[idx] = -1;
        }

        return nge;
    }
};