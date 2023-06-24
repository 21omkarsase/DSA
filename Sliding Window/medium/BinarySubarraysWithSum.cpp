// 930. Binary Subarrays With Sum
// Medium
// 2.2K
// 68
// Companies

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]

// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15

 

// Constraints:

//     1 <= nums.length <= 3 * 104
//     nums[i] is either 0 or 1.
//     0 <= goal <= nums.length

// Accepted
// 71.5K
// Submissions
// 134.9K
// Acceptance Rate
// 53.0%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        
        int subarrayCount = 0, sum = 0;
        unordered_map<int, int> tracker;

        for (int idx = 0; idx < n; idx++) {
            sum += nums[idx];

            if (sum == goal) 
                subarrayCount++;
            
            if (sum >= goal && tracker.find(sum - goal) != tracker.end()) { 
                subarrayCount += tracker[sum - goal];
            }

            tracker[sum]++;
        }

        return subarrayCount;
    }
};

// Time Complexity : O(2N)
// Space Complexity : O(1)

class Solution {

    int calculateAtMostKSum(int k, vector<int> &nums) {
        int n = nums.size();

        int left = 0, sum = 0, subarrayCount = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > k && left <= right)
                sum -= nums[left++];

            subarrayCount += (right - left + 1);
        }

        return subarrayCount;
    }

public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return calculateAtMostKSum(goal, nums) - calculateAtMostKSum(goal - 1, nums);
        // all subarrays till sum k - all subarrays till sum k - 2 == all subarrays with sum exactly k
    }

};