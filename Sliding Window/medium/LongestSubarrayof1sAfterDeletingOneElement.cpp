// 1493. Longest Subarray of 1's After Deleting One Element
// Medium
// 1.7K
// 32
// Companies

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.

 

// Constraints:

//     1 <= nums.length <= 105
//     nums[i] is either 0 or 1.

// Accepted
// 75.6K
// Submissions
// 121.9K
// Acceptance Rate
// 62.0%

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0;
        int zeroCount = 0, longestSubarrayLength = 0;

        for (int right = 0; right < n; right++) {
            while (left <= right && nums[right] == 0 && zeroCount == 1) {
                if (nums[left++] == 0)
                    zeroCount--;
            }

            if (nums[right] == 0)
                zeroCount = 1;

            longestSubarrayLength = max(longestSubarrayLength, right - left + 1);
        }

        return longestSubarrayLength - 1;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int prevSum = 0, sum = 0;
        int maxSubarrayLength = 0;

        for (int idx = 0; idx < n; idx++) {
            if (nums[idx] == 0) {
                prevSum = sum;
                sum = 0;
            } else 
                sum++;

            maxSubarrayLength = max(maxSubarrayLength, prevSum + sum);
        }

        return maxSubarrayLength == n ? maxSubarrayLength - 1 : maxSubarrayLength;
    }
};