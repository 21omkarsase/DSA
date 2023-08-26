// 128. Longest Consecutive Sequence
// Medium
// 17.7K
// 774
// Companies

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

 

// Constraints:

//     0 <= nums.length <= 105
//     -109 <= nums[i] <= 109

// Accepted
// 1.3M
// Submissions
// 2.7M
// Acceptance Rate
// 47.7%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;
        unordered_set<int> tracker;

        for (auto &num : nums) {
            tracker.insert(num);
        }

        for (auto &num : nums) {
            if (tracker.find(num - 1) != tracker.end()) {
                continue;
            }
            
            int it = num;
            while (tracker.find(it) != tracker.end()) {
                it++;
            }

            ans = max(ans, it - num);
        }
        
        return ans;
    }
};