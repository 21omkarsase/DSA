// 485. Max Consecutive Ones
// Easy
// 4.5K
// 432
// Companies

// Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

// Example 1:

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

// Example 2:

// Input: nums = [1,0,1,1,0,1]
// Output: 2

 

// Constraints:

//     1 <= nums.length <= 105
//     nums[i] is either 0 or 1.

// Accepted
// 885.9K
// Submissions
// 1.6M
// Acceptance Rate
// 56.9%

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        
        int start = 0, mx = 0;
        for(int end = 0; end < n; end++){
            if(nums[end] == 1)
                mx = max(mx, end - start + 1);
            else start = end + 1;
        }

        return mx;
    }
};