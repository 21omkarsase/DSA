// 377. Combination Sum IV
// Medium
// 6.8K
// 621
// Companies

// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

// The test cases are generated so that the answer can fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.

// Example 2:

// Input: nums = [9], target = 3
// Output: 0

 

// Constraints:

//     1 <= nums.length <= 200
//     1 <= nums[i] <= 1000
//     All the elements of nums are unique.
//     1 <= target <= 1000

 

// Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?
// Accepted
// 425.3K
// Submissions
// 795K
// Acceptance Rate
// 53.5%

// Time Complexity : O(target * N)
// Space Complexity : O(2* target) 

class Solution {
    int calculateNoOfCombinations(int target, vector<int> &nums, vector<int> &dp) {
        if (target == 0) {
            return 1;
        }

        if (dp[target] != -1) {
            return dp[target];
        }

        int combinations = 0;

        for (int idx = 0; idx < nums.size(); idx++) {
            if (target - nums[idx] >= 0) {
                combinations += calculateNoOfCombinations(target - nums[idx], nums, dp);
            }
        }
        
        return dp[target] = combinations;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);

        return calculateNoOfCombinations(target, nums, dp);
    }
};


// Time Complexity : O(target * N)
// Space Complexity : O(target) 

class Solution {
public:
    int combinationSum4(vector<int>& nums, int sum) {
        vector<int> dp(sum + 1, 0);
        
        dp[0] = 1; 

        for (int target = 1; target <= sum; target++) {
            int combinations = 0;

            for (int idx = 0; idx < nums.size(); idx++) {
                if (target - nums[idx] >= 0) {
                    combinations = (long long) combinations + dp[target - nums[idx]];
                }
            }
        
            dp[target] = combinations;
        }

        return dp[sum];
    }
};