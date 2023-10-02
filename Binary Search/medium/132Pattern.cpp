// 456. 132 Pattern
// Solved
// Medium
// Topics
// Companies

// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

// Return true if there is a 132 pattern in nums, otherwise, return false.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: false
// Explanation: There is no 132 pattern in the sequence.

// Example 2:

// Input: nums = [3,1,4,2]
// Output: true
// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

// Example 3:

// Input: nums = [-1,3,2,0]
// Output: true
// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

 

// Constraints:

//     n == nums.length
//     1 <= n <= 2 * 105
//     -109 <= nums[i] <= 109

// Accepted
// 199.7K
// Submissions
// 610K
// Acceptance Rate
// 32.7%

// Time Complexity : O(N) + O(N * 4(LogN))
// Space Complexity : O(2N)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        map<int, int> leftTracker, rightTracker;
        
        leftTracker[nums[0]]++;

        for (int idx = 1; idx < n; idx++) {
            rightTracker[nums[idx]]++;
        }

        for (int idx = 1; idx < n - 1; idx++) {
            rightTracker[nums[idx]]--;
            
            if (rightTracker[nums[idx]] == 0) {
                rightTracker.erase(nums[idx]);
            }

            int left = leftTracker.begin()->first;

            auto lower = rightTracker.lower_bound(left + 1);
            auto upper = rightTracker.upper_bound(nums[idx] - 1);

            if (left < nums[idx] && lower != upper && lower != rightTracker.end()) {
                return true;
            }

            leftTracker[nums[idx]]++;
        }

        return false;
    }
};

// Time Complexity : O(2N)
// space complexity : O(N)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        int mn = 1e9;
        stack<pair<int, int>> st;

        for (int idx = 0; idx < n; idx++) {
            while (!st.empty() && nums[st.top().first] <= nums[idx]) {
                st.pop();
            }

            if (!st.empty() && st.top().second < nums[idx]) {
                return true;
            }

            st.push({idx, {min(mn, nums[idx])}});
            mn = min(mn, nums[idx]);
        }

        return false;
    }
};