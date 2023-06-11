// 34. Find First and Last Position of Element in Sorted Array
// Medium
// 17.1K
// 415
// Companies

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]

 

// Constraints:

//     0 <= nums.length <= 105
//     -109 <= nums[i] <= 109
//     nums is a non-decreasing array.
//     -109 <= target <= 109

// Accepted
// 1.5M
// Submissions
// 3.7M
// Acceptance Rate
// 42.1%

class Solution {
    int getFirstPos(int st, int &n, int &target, vector<int> &nums){
        int en = n - 1, ans = -1;

        while(st <= en){
            int mid = st + (en - st) / 2;
            
            if(nums[mid] >= target){
                if(nums[mid] == target)
                    ans = mid;
                en = mid - 1;
            }
            else st = mid + 1;
        }
        return ans;
    }
    int getLastPos(int st, int &n, int &target, vector<int> &nums){
        int en = n - 1, ans = -1;

        while(st <= en){
            int mid = st + (en - st) / 2;
            
            if(nums[mid] <= target){
                if(nums[mid] == target)
                    ans = mid;
                st = mid + 1;
            }
            else en = mid - 1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int firstPos = getFirstPos(0, n, target, nums);
        if(firstPos == -1){
            return {-1, -1};
        }
        int lastPos = getLastPos(0, n, target, nums);

        return {firstPos, lastPos};
    }
};