// 992. Subarrays with K Different Integers
// Hard
// 4.4K
// 62
// Companies

// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

//     For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

// Example 2:

// Input: nums = [1,2,1,3,4], k = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

 

// Constraints:

//     1 <= nums.length <= 2 * 104
//     1 <= nums[i], k <= nums.length

// Accepted
// 95.7K
// Submissions
// 174.2K
// Acceptance Rate
// 55.0%

// Time Complexity : O(4N)
// Space Complexity : O(K)


class Solution {
    int countSubarraysWithAtMostK(int k, vector<int> &nums) {
        int n = nums.size();

        int left = 0, subarrayCount = 0, currDistinct = 0;
        unordered_map<int, int> tracker;

        for (int right = 0; right < n; right++) {
            if (tracker.find(nums[right]) == tracker.end())
                currDistinct++;
         
            tracker[nums[right]]++;
            
            while (currDistinct > k && left <= right) {
                tracker[nums[left]]--;

                if (tracker[nums[left]] == 0) {
                    currDistinct--; 
                    tracker.erase(nums[left]);
                }

                left++;
            }

            subarrayCount += (right - left + 1);
        }

        return subarrayCount;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarraysWithAtMostK(k, nums) - countSubarraysWithAtMostK(k - 1, nums);
    }
};