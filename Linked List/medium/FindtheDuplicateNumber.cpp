// 287. Find the Duplicate Number
// Attempted
// Medium
// Topics
// Companies

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2

// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3

 

// Constraints:

//     1 <= n <= 105
//     nums.length == n + 1
//     1 <= nums[i] <= n
//     All the integers in nums appear only once except for precisely one integer which appears two or more times.

 

// Follow up:

//     How can we prove that at least one duplicate number must exist in nums?
//     Can you solve the problem in linear runtime complexity?

// Accepted
// 1.3M
// Submissions
// 2.2M
// Acceptance Rate
// 59.1%

//TLE

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int idx1 = 0, idx2 = 1;

        while (nums[idx1] != nums[idx2] || idx1 == idx2) {
            if (idx1 == idx2) {
                idx2 = (idx2 + 1) % n;
            }

            idx1 = (idx1 + 1) % n;
            idx2 = (idx2 + 2) % n;
        }

        return nums[idx1];
    }
};

// linked list cycle + floyds algorithm

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int slow = 0, fast = 0;

        while (slow != fast || slow == 0) {
          slow = nums[slow];
          fast = nums[nums[fast]];
        }

        slow = 0;

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int idx = 0; idx < n; idx++) {
            if (nums[abs(nums[idx])] < 0) {
                return abs(nums[idx]);
            }
            else {
                nums[abs(nums[idx])] *= -1;
            }
        }

        return -1;
    }
};