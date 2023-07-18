// 1218. Longest Arithmetic Subsequence of Given Difference
// Medium
// 2.9K
// 80
// Companies

// Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

// A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: arr = [1,2,3,4], difference = 1
// Output: 4
// Explanation: The longest arithmetic subsequence is [1,2,3,4].

// Example 2:

// Input: arr = [1,3,5,7], difference = 1
// Output: 1
// Explanation: The longest arithmetic subsequence is any single element.

// Example 3:

// Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
// Output: 4
// Explanation: The longest arithmetic subsequence is [7,5,3,1].

 

// Constraints:

//     1 <= arr.length <= 105
//     -104 <= arr[i], difference <= 104

// Accepted
// 120.9K
// Submissions
// 218.2K
// Acceptance Rate
// 55.4%

class Solution {
public:
    int longestSubsequence(vector<int>& nums, int d) {
        int n = nums.size();

        unordered_map<int, int> tracker;

        for (int idx = 0; idx < n; idx++) {
            if (tracker.find(nums[idx] - d) != tracker.end()) {
                tracker[nums[idx]] = tracker[nums[idx] - d] + 1;
            } else {
                if (tracker.find(nums[idx]) == tracker.end())
                    tracker[nums[idx]] = 0;
            }
        }

        int len = 0;
        for (auto [key, value] : tracker) {
            len = max(len, value);
        }

        return len +1;                                      
    }
};
