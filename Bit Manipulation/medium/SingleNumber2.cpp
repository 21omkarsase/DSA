// 137. Single Number II
// Medium
// 5.8K
// 556
// Companies

// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3

// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99

 

// Constraints:

//     1 <= nums.length <= 3 * 104
//     -231 <= nums[i] <= 231 - 1
//     Each element in nums appears exactly three times except for one element which appears once.

// Accepted
// 424.4K
// Submissions
// 719.4K
// Acceptance Rate
// 59.0%

// can be solved using hash table or sorting


// Time Complexity : O(32*N) worse than O(N*LogN)
// Time Complexity : O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n =  nums.size();

        int ans = 0;

        for (int idx1 = 0; idx1 < 32; idx1++) {
            int x = 1 << idx1, ones = 0;

            for (int idx2 = 0; idx2 < n; idx2++) {
                if (nums[idx2] & x)
                    ones++;
            }

            if (ones % 3 != 0) 
                ans += (1 << idx1);
        }

        return ans;
    }
};



// Time Complexity : O(N) 
// Time Complexity : O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n =  nums.size();

        int ones = 0, twos = 0;

        for (int idx = 0; idx < n; idx++) {
            ones = (ones ^ nums[idx]) & (~twos); // storing nums occured single time
            twos = (twos ^ nums[idx]) & (~ones); // storing nums occured twice
        }

        return ones;
    }
};