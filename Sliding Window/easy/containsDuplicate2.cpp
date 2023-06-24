// 219. Contains Duplicate II
// Easy
// 5K
// 2.7K
// Companies

// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true

// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true

// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

 

// Constraints:

//     1 <= nums.length <= 105
//     -109 <= nums[i] <= 109
//     0 <= k <= 105

// Accepted
// 688.1K
// Submissions
// 1.6M
// Acceptance Rate
// 42.8%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> tracker;

        int left = 0;
        for(int right = 0; right < n; right++) {
            if(right - left > k){
                tracker[nums[left]]--;
                left++;
            }
            
            tracker[nums[right]]++;
            if(tracker[nums[right]] > 1)
                return true;            
        }

        return false;
    }
};