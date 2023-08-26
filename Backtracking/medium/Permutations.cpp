// 46. Permutations
// Medium
// 16.6K
// 268
// Companies

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:

// Input: nums = [1]
// Output: [[1]]

 

// Constraints:

//     1 <= nums.length <= 6
//     -10 <= nums[i] <= 10
//     All the integers of nums are unique.

// Accepted
// 1.7M
// Submissions
// 2.2M
// Acceptance Rate
// 76.4%

// Time Complexity : O(N!)
// for each call we will make n - len(permutation) calls i.e n * (n - 1) * (n - 2) * (n - 3) * .... * 1 
// Space Complexity : O(N) + O(N) + O(N) (auxillary)
// Total Space Complexity : O(N!)

class Solution {
    void getAllPermutations(int n, vector<int> &nums, unordered_set<int> &tracker, vector<int> &permutation, vector<vector<int>> &permutations) {
        if (permutation.size() == n) {
            permutations.push_back(permutation);

            return;
        }


        for (int idx = 0; idx < n; idx++) {
            if (tracker.find(nums[idx]) == tracker.end()) {
                permutation.push_back(nums[idx]);
                tracker.insert(nums[idx]);

                getAllPermutations(n, nums, tracker, permutation, permutations);
                
                permutation.pop_back();
                tracker.erase(nums[idx]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> permutations;
        vector<int> permutation;
        unordered_set<int> tracker;

        getAllPermutations(n, nums, tracker, permutation, permutations);
        
        return permutations;
    }
};