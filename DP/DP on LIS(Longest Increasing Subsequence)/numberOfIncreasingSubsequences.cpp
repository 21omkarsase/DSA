// 673. Number of Longest Increasing Subsequence
// Medium
// 5.4K
// 221
// Companies

// Given an integer array nums, return the number of longest increasing subsequences.

// Notice that the sequence has to be strictly increasing.

 

// Example 1:

// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

// Example 2:

// Input: nums = [2,2,2,2,2]
// Output: 5
// Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.

 

// Constraints:

//     1 <= nums.length <= 2000
//     -106 <= nums[i] <= 106

// Accepted
// 163.4K
// Submissions
// 367.7K
// Acceptance Rate
// 44.4%

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1); //for storing LIS till ith idx;
        vector<int> cnt(n , 1); // for storing count of lis till ith idx;
        
        int lisLength = 0;

        for (int idx = 0; idx < n; idx++) {
            for (int prev = 0; prev < idx; prev++) {
                if (nums[idx] > nums[prev]) {
                    if (dp[idx] < dp[prev] + 1) { 
                        //if we get lis length better than previous lis length
                        //as we are first time getting this lis length
                        //count will reset to lis count of prev
                        dp[idx] = dp[prev] + 1;
                        cnt[idx] = cnt[prev]; 
                    } else if(dp[idx] == dp[prev] + 1) {
                        //we are getting same lis length
                        //so we will add prev lis count to curr lis count
                        cnt[idx] += cnt[prev];
                    }
                }
            }

            lisLength = max(lisLength, dp[idx]);
        }

        // lisLenth  -> stores longest increasing length
        // we might have got lisLength at diff indexes 
        // for which have lis count for those indexes
        
        int totalNoOfLIS = 0;

        for (int idx = 0; idx < n; idx++) {
            if (dp[idx] == lisLength) {
                totalNoOfLIS += cnt[idx];
            }
        }

        return totalNoOfLIS;
    }
};