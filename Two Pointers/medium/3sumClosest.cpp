// 16. 3Sum Closest
// Medium
// 9.3K
// 484
// Companies

// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

 

// Constraints:

//     3 <= nums.length <= 500
//     -1000 <= nums[i] <= 1000
//     -104 <= target <= 104

// Accepted
// 1M
// Submissions
// 2.3M
// Acceptance Rate
// 45.6%

// Time Complexity : O(N^2)
// Space Complexity : O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closeSum = nums[0] + nums[1] + nums[2];
        int diff = abs(closeSum - target);

        for(int idx = 0; idx < n - 2 ; idx++) {
            int start = idx + 1, end = n - 1;

            while(start < end) {
                int sum = nums[start] + nums[end] + nums[idx];

                if(abs(sum - target) <= diff){
                    diff = abs(sum - target);
                    closeSum = sum;
                }

                if(sum == target)
                    return target;
                else if(sum > target)
                    end -= 1;
                else 
                    start += 1;
            }
        }

        return closeSum;
    }
};