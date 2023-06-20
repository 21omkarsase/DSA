// 643. Maximum Average Subarray I
// Easy
// 2.5K
// 202
// Companies

// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:

// Input: nums = [5], k = 1
// Output: 5.00000

 

// Constraints:

//     n == nums.length
//     1 <= k <= n <= 105
//     -104 <= nums[i] <= 104

// Accepted
// 226.1K
// Submissions
// 518.3K
// Acceptance Rate
// 43.6%


// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0, sum = 0, maxSum = INT_MIN;
        for(int right = 0; right < n; right++) {
            sum += nums[right];
            if(right < k - 1)
                continue;
            
            maxSum = max(maxSum, sum);
            sum -= nums[left++];
        }

        return (double) maxSum / k;
    }
};

