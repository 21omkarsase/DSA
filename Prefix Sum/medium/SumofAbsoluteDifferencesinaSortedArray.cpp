// 1685. Sum of Absolute Differences in a Sorted Array
// Medium
// 1.1K
// 31
// Companies

// You are given an integer array nums sorted in non-decreasing order.

// Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

// In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

 

// Example 1:

// Input: nums = [2,3,5]
// Output: [4,3,5]
// Explanation: Assuming the arrays are 0-indexed, then
// result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
// result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
// result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.

// Example 2:

// Input: nums = [1,4,6,8,10]
// Output: [24,15,13,15,21]

 

// Constraints:

//     2 <= nums.length <= 105
//     1 <= nums[i] <= nums[i + 1] <= 104

// Accepted
// 28.3K
// Submissions
// 45K
// Acceptance Rate
// 62.9%


// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> postSum(n, 0);

        for (int idx = n - 2; idx >= 0; idx--) 
            postSum[idx] = postSum[idx + 1] + nums[idx + 1];
        
        int sum = 0;
        vector<int> sumDifference(n, 0);

        for (int idx = 0; idx < n; idx++) {
            int leftSum = idx * nums[idx] - sum;
            int rightSum = postSum[idx] - ((n - idx - 1) * nums[idx]);

            sumDifference[idx] = leftSum + rightSum;

            sum += nums[idx];
        }

        return sumDifference;
    }
};



// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        int preSum = 0, postSum = 0;
        int left = 0, right = n - 1;
        vector<int> sumDifference(n, 0);

        while (left < n) {
            int leftSum = nums[left] * left - preSum;
            int rightSum = postSum - nums[right] * (n - right - 1);

            sumDifference[left] += leftSum;
            sumDifference[right] += rightSum;

            preSum += nums[left++];
            postSum += nums[right--];
        }

        return sumDifference;
    }
};

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        int preSum = 0, postSum = 0;
        vector<int> sumDifference(n, 0);

        for (int idx = 0; idx < n; idx++) {
            int leftSum = nums[idx] * idx - preSum;
            int rightSum = postSum - nums[n - idx - 1] * idx;

            sumDifference[idx] += leftSum;
            sumDifference[n - idx - 1] += rightSum;

            preSum += nums[idx];
            postSum += nums[n - idx - 1];
        }

        return sumDifference;
    }
};