// 75. Sort Colors
// Medium
// 15.2K
// 542
// Companies

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

 

// Constraints:

//     n == nums.length
//     1 <= n <= 300
//     nums[i] is either 0, 1, or 2.

 

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?
// Accepted
// 1.5M
// Submissions
// 2.5M
// Acceptance Rate
// 59.2%


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;

        while(start < end){
            if(nums[start] == 0)
                start++;
            else if(nums[end] == 0){
                swap(nums[start], nums[end]);
            }else end--;
        }

        end = n - 1;
        while(start < end){
            if(nums[start] == 1)
                start++;
            else if(nums[end] == 1){
                swap(nums[start], nums[end]);
            }else end--;
        } 
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1, idx = 0;

        while(idx <= end){
            if(nums[idx] == 2){
                swap(nums[idx--], nums[end--]);
            }else if(nums[idx] == 0)
                swap(nums[start++], nums[idx]);
            idx++;
        }
    }
};