// 26. Remove Duplicates from Sorted Array
// Easy
// 11.3K
// 15.2K
// Companies

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

//     Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
//     Return k.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }

// If all assertions pass, then your solution will be accepted.

 

// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Example 2:

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

 

// Constraints:

//     1 <= nums.length <= 3 * 104
//     -100 <= nums[i] <= 100
//     nums is sorted in non-decreasing order.

// Accepted
// 3.1M
// Submissions
// 5.9M



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        for(int end = 1; end < n; end++){
            if(nums[start] != nums[end]){
                nums[++start] = nums[end];
            }
        }

        return start + 1;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        for(int idx = 0; idx < n; idx++){
            int start = idx, end = idx + 1;

            while(end < n && nums[end] == nums[end - 1])
                end++;
            end--;

            for(int idx2 = start + 1; idx2 <= end; idx2++)
                nums[idx2] = -101;

            idx = start;
        }

        int start = 0, end = 1;

        while(start < n && nums[start] != -101)
            start++;

        end = start;
        while(end < n && nums[end] == -101)
            end++;

        while(end < n){
            swap(nums[start], nums[end]);

            while(start < n && nums[start] != -101)
                start++;
            
            while(end < n && nums[end] == -101)
                end++;
        }

        return find(nums.begin(), nums.end(), -101) - nums.begin();
    }
};













