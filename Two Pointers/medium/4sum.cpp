// 18. 4Sum
// Medium
// 9.5K
// 1.1K
// Companies

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

//     0 <= a, b, c, d < n
//     a, b, c, and d are distinct.
//     nums[a] + nums[b] + nums[c] + nums[d] == target

// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

 

// Constraints:

//     1 <= nums.length <= 200
//     -109 <= nums[i] <= 109
//     -109 <= target <= 109

// Accepted
// 753.5K
// Submissions
// 2.1M
// Acceptance Rate
// 35.8%


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> quadruplets;
        for(int idx1 = 0; idx1 < n - 3; idx1++){
            if(idx1 != 0 && nums[idx1] == nums[idx1 - 1])
                continue;
            for(int idx2 = idx1 + 1; idx2 < n - 2; idx2++){
                if(idx2 != idx1 + 1 && nums[idx2] == nums[idx2 - 1])
                    continue;

                int start = idx2 + 1, end = n - 1;
                
                long long sum = nums[idx1] + nums[idx2];
                while(start < end){
                    long long totalSum = nums[start] + nums[end] + sum;
                    if(totalSum == target){
                        vector<int> quadruplet = {nums[idx1], nums[idx2], nums[start], nums[end]};
                        sort(quadruplet.begin(), quadruplet.end());
                        quadruplets.push_back(quadruplet);
                        
                        start++, end--;
                        while(start < n && nums[start] == nums[start - 1])
                            start++;

                        while(end >= 0 && nums[end] == nums[end + 1])
                            end--;

                    }else if(totalSum < target)
                        start++;
                    else end--;
                }
            }
        }

        return quadruplets;
    }
};