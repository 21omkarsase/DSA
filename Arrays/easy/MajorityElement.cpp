// 169. Majority Element
// Solved
// Easy
// Topics
// Companies

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3

// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

 

// Constraints:

//     n == nums.length
//     1 <= n <= 5 * 104
//     -109 <= nums[i] <= 109

 
// Follow-up: Could you solve the problem in linear time and in O(1) space?
// Accepted
// 2.1M
// Submissions
// 3.3M
// Acceptance Rate
// 63.8%

// Time Complexity : O(N)
// Space Complexity : O(1)

// Moore's voting algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num = 0, cnt = 0;

        for (int idx = 0; idx < n; idx++) {
            if (cnt == 0) {
                num = nums[idx];
                cnt++;
            }
            else  {
                if (nums[idx] == num) {
                    cnt++;
                }
                else {
                    cnt--;
                }
            }
        }

        return num;
    }
};  