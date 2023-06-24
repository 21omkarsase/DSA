// 1004. Max Consecutive Ones III
// Medium
// 6.6K
// 73
// Companies

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

 

// Constraints:

//     1 <= nums.length <= 105
//     nums[i] is either 0 or 1.
//     0 <= k <= nums.length

// Accepted
// 311.9K
// Submissions
// 494.8K
// Acceptance Rate
// 63.0%

// Time Complexity : O(N)
// Space Complexity : O(1)



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int zeroCnt = 0, oneCnt = 0, maxSubArraySize = 0;

        while(right < n){
            nums[right] == 0 ? zeroCnt++ : oneCnt++;

            if(zeroCnt <= k) {
                maxSubArraySize = max(maxSubArraySize, right - left + 1);
                right++;
            } else{
                nums[left++] == 0 ? zeroCnt-- : oneCnt--;
                right++;
            }
        }

        return maxSubArraySize;
    }
};