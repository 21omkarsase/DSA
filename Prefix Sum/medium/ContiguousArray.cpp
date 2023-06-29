// 525. Contiguous Array
// Medium
// 6.5K
// 256
// Companies

// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

 

// Constraints:

//     1 <= nums.length <= 105
//     nums[i] is either 0 or 1.

// Accepted
// 299.1K
// Submissions
// 638.8K
// Acceptance Rate
// 46.8%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        int maxSubarrayLen = 0, sum = 0;
        unordered_map<int, int> tracker;

        tracker[0] = -1;

        for (int idx = 0; idx < n; idx++) {
            sum = nums[idx] == 1 ? sum + 1 : sum - 1;

            if (tracker.find(sum) != tracker.end()) {
                maxSubarrayLen = max(maxSubarrayLen, (idx - tracker[sum]));  // from certain point in past till now sum has again become equal (so in between we had equal number of zero and one)
            } else {
                tracker[sum] = idx;
            }
        }

        return maxSubarrayLen;
    }
};