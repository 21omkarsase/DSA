// 2369. Check if There is a Valid Partition For The Array
// Medium
// 784
// 126
// Companies

// You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

// We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

//     The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
//     The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
//     The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.

// Return true if the array has at least one valid partition. Otherwise, return false.

 

// Example 1:

// Input: nums = [4,4,4,5,6]
// Output: true
// Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
// This partition is valid, so we return true.

// Example 2:

// Input: nums = [1,1,1,2]
// Output: false
// Explanation: There is no valid partition for this array.

 

// Constraints:

//     2 <= nums.length <= 105
//     1 <= nums[i] <= 106

// Accepted
// 29.3K
// Submissions
// 64.8K
// Acceptance Rate
// 45.2%

// Time Complexity : O(N)
// Space Complexity : O(2N)

class Solution {
    bool isValidPartition(int start, int end, vector<int> &nums, vector<int> &dp) {
        if (start > end) {
            return true;
        }
        
        if (start == end) {
            return false;
        }

        if (end - start + 1 == 2) {
            if (nums[start] == nums[end]) {
                return 1;
            }

            return false;
        }

        if (dp[start] != -1) {
            return dp[start];
        }

        if (nums[start] == nums[start + 1] - 1 && nums[start + 1] == nums[start + 2] - 1) {
            return dp[start] = isValidPartition(start + 3, end, nums, dp);
        }
        else if (nums[start] == nums[start + 1] && nums[start + 1] == nums[start + 2]) {
            return dp[start] = isValidPartition(start + 2, end, nums, dp) || 
                                    isValidPartition(start + 3, end, nums, dp);
        }
        else if (nums[start] == nums[start + 1]) {
            return dp[start] = isValidPartition(start + 2, end, nums, dp);
        }

        return dp[start] = false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return isValidPartition(0, n - 1, nums, dp);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)


class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size(), end = n - 1;
        
        vector<int> dp(n + 1, 0);

        for (int start = n; start >= 0; start--) {
            if (start > end) {
                dp[start] = true;
            }
            else if (start == end) {
                dp[start] = false;
            }
            else if (end - start + 1 == 2) {
                if (nums[start] == nums[end]) {
                    dp[start] = true;
                }
                else {
                    dp[start] = false;
                }
            }
            else if (nums[start] == nums[start + 1] - 1 && nums[start + 1] == nums[start + 2] - 1) {
                dp[start] = dp[start + 3];
            }
            else if (nums[start] == nums[start + 1] && nums[start + 1] == nums[start + 2]) {
                dp[start] = dp[start + 2] || dp[start + 3];
            }
            else if (nums[start] == nums[start + 1]) {
                dp[start] = dp[start + 2];
            }
            else {
                dp[start] = false;
            }
        }

        return dp[0];
    }
};