// 2574. Left and Right Sum Differences
// Easy
// 587
// 42
// Companies

// Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:

//     answer.length == nums.length.
//     answer[i] = |leftSum[i] - rightSum[i]|.

// Where:

//     leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
//     rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.

// Return the array answer.

 

// Example 1:

// Input: nums = [10,4,8,3]
// Output: [15,1,11,22]
// Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
// The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].

// Example 2:

// Input: nums = [1]
// Output: [0]
// Explanation: The array leftSum is [0] and the array rightSum is [0].
// The array answer is [|0 - 0|] = [0].

 

// Constraints:

//     1 <= nums.length <= 1000
//     1 <= nums[i] <= 105

// Accepted
// 63.2K
// Submissions
// 72.4K
// Acceptance Rate
// 87.2%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0, totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> difference(n, 0);

        for (int idx = 0; idx < n; idx++) {
            difference[idx] = abs(sum - (totalSum - nums[idx] - sum));

            sum += nums[idx];
        }

        return difference;
    }
};

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        
        int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> difference(n, 0);

        for (int idx = 0; idx < n; idx++) {
            rightSum -= nums[idx];

            difference[idx] = abs(rightSum - leftSum);

            leftSum += nums[idx];
        }

        return difference;
    }
};