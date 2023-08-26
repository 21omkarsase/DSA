// 239. Sliding Window Maximum
// Hard
// 15.9K
// 529
// Companies

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

 

// Constraints:

//     1 <= nums.length <= 105
//     -104 <= nums[i] <= 104
//     1 <= k <= nums.length

// Accepted
// 829.4K
// Submissions
// 1.8M
// Acceptance Rate
// 46.3%

// Time Complexity : O(N*LogN)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;

        vector<int> ans;
        map<int, int, greater<int>> tracker;

        for (int right = 0; right < n; right++) {
            tracker[nums[right]]++;

            if (right - left + 1 == k) {
                ans.push_back(tracker.begin()->first);

                tracker[nums[left]]--;

                if (tracker[nums[left]] == 0) {
                    tracker.erase(nums[left]);
                }

                left++;
            }
        }

        return ans;
    }
};