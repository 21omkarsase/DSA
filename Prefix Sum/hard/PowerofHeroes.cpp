// 2681. Power of Heroes
// Hard
// 246
// 13
// Companies

// You are given a 0-indexed integer array nums representing the strength of some heroes. The power of a group of heroes is defined as follows:

//     Let i0, i1, ... ,ik be the indices of the heroes in a group. Then, the power of this group is max(nums[i0], nums[i1], ... ,nums[ik])2 * min(nums[i0], nums[i1], ... ,nums[ik]).

// Return the sum of the power of all non-empty groups of heroes possible. Since the sum could be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [2,1,4]
// Output: 141
// Explanation: 
// 1st group: [2] has power = 22 * 2 = 8.
// 2nd group: [1] has power = 12 * 1 = 1. 
// 3rd group: [4] has power = 42 * 4 = 64. 
// 4th group: [2,1] has power = 22 * 1 = 4. 
// 5th group: [2,4] has power = 42 * 2 = 32. 
// 6th group: [1,4] has power = 42 * 1 = 16. 
// ​​​​​​​7th group: [2,1,4] has power = 42​​​​​​​ * 1 = 16. 
// The sum of powers of all groups is 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141.

// Example 2:

// Input: nums = [1,1,1]
// Output: 7
// Explanation: A total of 7 groups are possible, and the power of each group will be 1. Therefore, the sum of the powers of all groups is 7.

 

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 109

// Accepted
// 6.5K
// Submissions
// 21.7K
// Acceptance Rate
// 29.9%

// Time Complexity : O(N*LogN)
// Space Complexity : O(N)


// checking for all possible subsets will give tle
// since we are only interested in max and min of every subset
// sorting the array will not affect 
// 3 5 7 10
// for all subsets of 10->
// ans += (10 ^ 2) * (10) + (10 ^ 2) * (7) + (10 ^ 2) * (5 + 5) + (10 ^ 2) * (3 + 3 + 3 + 3) 
// ans += (10 ^ 2) (7 + 5 + 5 + 5 + 3 + 3 + 3 + 3)

// use prefix sum variable to store sum of all nums ->(num(0) * freq(num(0)) to (num(i - 1) * freq(num(i - 1)) till curr num

int MOD = 1e9 + 7;

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int prefix = 0;
        int sum = 0;

        for (int idx = 0; idx < n; idx++) {
            int prev = ((long long) ((long long) sortedNums[idx] * sortedNums[idx]) % MOD * prefix) % MOD;
            int curr = ((long long) ((long long) sortedNums[idx] * sortedNums[idx]) % MOD * sortedNums[idx]) % MOD;

            sum = ((long long) sum + prev + curr) % MOD;
            prefix = ((long long) prefix * 2) % MOD + sortedNums[idx];
        }

        return sum;
    }
};