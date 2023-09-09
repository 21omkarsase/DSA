// 2366. Minimum Replacements to Sort the Array
// Hard
// 1.5K
// 48
// Companies

// You are given a 0-indexed integer array nums. In one operation you can replace any element of the array with any two elements that sum to it.

//     For example, consider nums = [5,6,7]. In one operation, we can replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].

// Return the minimum number of operations to make an array that is sorted in non-decreasing order.

 

// Example 1:

// Input: nums = [3,9,3]
// Output: 2
// Explanation: Here are the steps to sort the array in non-decreasing order:
// - From [3,9,3], replace the 9 with 3 and 6 so the array becomes [3,3,6,3]
// - From [3,3,6,3], replace the 6 with 3 and 3 so the array becomes [3,3,3,3,3]
// There are 2 steps to sort the array in non-decreasing order. Therefore, we return 2.

// Example 2:

// Input: nums = [1,2,3,4,5]
// Output: 0
// Explanation: The array is already in non-decreasing order. Therefore, we return 0. 

 

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 109

// Accepted
// 41.8K
// Submissions
// 79.4K
// Acceptance Rate
// 52.6%

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();

        int mn = nums[n - 1];
        long long cnt = 0;

        for (int idx = n - 2; idx >= 0; idx--) {
            if (nums[idx] > mn) {
               int addition = nums[idx] / mn;

                if (nums[idx] % mn != 0) {
                    addition++;
                    mn = nums[idx] / addition;
                }

                cnt += (addition - 1);
            }
            else {
                mn = nums[idx];
            }
        }

        return cnt;
    }
};
