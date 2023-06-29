// 2750. Ways to Split Array Into Good Subarrays
// Medium
// 181
// 2
// Companies

// You are given a binary array nums.

// A subarray of an array is good if it contains exactly one element with the value 1.

// Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [0,1,0,0,1]
// Output: 3
// Explanation: There are 3 ways to split nums into good subarrays:
// - [0,1] [0,0,1]
// - [0,1,0] [0,1]
// - [0,1,0,0] [1]

// Example 2:

// Input: nums = [0,1,0]
// Output: 1
// Explanation: There is 1 way to split nums into good subarrays:
// - [0,1,0]

 

// Constraints:

//     1 <= nums.length <= 105
//     0 <= nums[i] <= 1

// Accepted
// 9.4K
// Submissions
// 31.4K
// Acceptance Rate
// 29.9%

// Time Complexity : O(N)
// Space Complexity : O(1)

int MOD = 1000000007;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();

        int totalCount = 1;
        bool flag = false;

        for (int left = 0; left < n; left++) {
            if (nums[left] == 1) {
                flag = true;
                int right = left + 1;
                
                while(right < n && nums[right] == 0) {
                    right++;
                }
                
                if(right == n) {
                    break;
                }
                
                if(nums[right] == 1)
                    totalCount = (((long long) totalCount % MOD) * ((right - left) % MOD)) % MOD;

                left = right - 1;
            }
        }

        if (!flag)
            return 0;
        
        return totalCount;
    }
};