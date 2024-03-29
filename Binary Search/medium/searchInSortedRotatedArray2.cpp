// 81. Search in Rotated Sorted Array II
// Medium
// 6.2K
// 853
// Companies

// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

 

// Example 1:

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

// Example 2:

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false

 

// Constraints:

//     1 <= nums.length <= 5000
//     -104 <= nums[i] <= 104
//     nums is guaranteed to be rotated at some pivot.
//     -104 <= target <= 104

 

// Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
// Accepted
// 517.4K
// Submissions
// 1.4M
// Acceptance Rate
// 35.7%
// Seen this question in a real interview before?
// 1/4
// Yes
// No
// Discussion (25)
// Similar Questions
// Search in Rotated Sorted Array
// Medium
// Related Topics
// Array
// Binary Search

// Time Complexity : O(N / 2) + O(LogN)
// space complexity : O(1)

class Solution {
    int binarySearch(int st, int en, int &n, int &target, vector<int> &nums){
        if(st > en)
            return false;
        int mid = st + (en - st) / 2;

        if(nums[mid] == target)
            return true;
        
        if(nums[mid] > nums[st]){
            if(nums[mid] > target && nums[st] <= target){
                if(binarySearch(st, mid - 1, n, target, nums))
                    return true;
            }else if(binarySearch(mid + 1, en, n, target, nums))
                return true;
        }else if(nums[mid] < nums[st]){
            if(nums[mid] < target && nums[en] >= target){
                if(binarySearch(mid + 1, en, n, target, nums))
                    return true;
            }else if(binarySearch(st, mid - 1, n, target, nums))
                return true;
        }else{
            return binarySearch(st, mid - 1, n, target, nums) || binarySearch(mid + 1, en, n, target, nums);
        }

        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearch(0, n - 1, n, target, nums);
    }
};


// Time Complexity : O(N/2)
// space complexity : O(1)

class Solution {
    bool binarySearch(int start, int end, int &target, vector<int> &nums) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return true;
            }
            
            if (nums[mid] == nums[start] && nums[mid] == nums[end]) {
                // shrinking the search space
                start++;
                end--;
                continue;
            }

            if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else {
                if (target >= nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }

        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        return binarySearch(0, n - 1, target, nums);
    }
};