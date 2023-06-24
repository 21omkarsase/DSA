// 2461. Maximum Sum of Distinct Subarrays With Length K
// Medium
// 796
// 11
// Companies

// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

//     The length of the subarray is k, and
//     All the elements of the subarray are distinct.

// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

// Example 2:

// Input: nums = [4,4,4], k = 3
// Output: 0
// Explanation: The subarrays of nums with length 3 are:
// - [4,4,4] which does not meet the requirements because the element 4 is repeated.
// We return 0 because no subarrays meet the conditions.

 

// Constraints:

//     1 <= k <= nums.length <= 105
//     1 <= nums[i] <= 105

// Accepted
// 26.9K
// Submissions
// 78.8K
// Acceptance Rate
// 34.1%

// Time Complexity : O(N)
// Space Complexity : O(k)

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;
        long long sum = 0, maxSum = 0;
        unordered_map<int, int> tracker; 

        for(int right = 0; right < n; right++) {
            tracker[nums[right]]++;     
            sum += nums[right];

            if(right - left == k - 1){
                if(tracker.size() == k)
                    maxSum = max(maxSum, sum);

                sum -= nums[left];
                tracker[nums[left]]--;

                if(tracker[nums[left]] == 0)
                    tracker.erase(nums[left]);
                left++;
            }
        }

        return maxSum;
    }
};