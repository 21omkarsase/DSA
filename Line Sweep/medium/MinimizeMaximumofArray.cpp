// 2439. Minimize Maximum of Array
// Medium
// 2.1K
// 537
// Companies

// You are given a 0-indexed array nums comprising of n non-negative integers.

// In one operation, you must:

//     Choose an integer i such that 1 <= i < n and nums[i] > 0.
//     Decrease nums[i] by 1.
//     Increase nums[i - 1] by 1.

// Return the minimum possible value of the maximum integer of nums after performing any number of operations.

 

// Example 1:

// Input: nums = [3,7,1,6]
// Output: 5
// Explanation:
// One set of optimal operations is as follows:
// 1. Choose i = 1, and nums becomes [4,6,1,6].
// 2. Choose i = 3, and nums becomes [4,6,2,5].
// 3. Choose i = 1, and nums becomes [5,5,2,5].
// The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
// Therefore, we return 5.

// Example 2:

// Input: nums = [10,1]
// Output: 10
// Explanation:
// It is optimal to leave nums as is, and since 10 is the maximum value, we return 10.

 

// Constraints:

//     n == nums.length
//     2 <= n <= 105
//     0 <= nums[i] <= 109

// Accepted
// 69.2K
// Submissions
// 146.3K
// Acceptance Rate
// 47.3%

 // using binary serach

 // Time Complexity : O(N * Log(max(nums)))
 // Space Complexity : O(1)

class Solution {
    bool isValid(int x, int n, vector<int> &nums) {
        long long sum = 0;

        for (int idx = 0; idx < n; idx++) {
            sum += nums[idx];

             // as it is possible to decrease previous any one value 
             // we will compare the prefix sum with total max sum
            if (sum > (long long) ((long long) x * (idx + 1)))
                return false;
        }

        return true;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();

        int start = 0, end = *max_element(nums.begin(), nums.end()); // checking for every possible value of x

        while (start <= end) {
            int mid = start + (end - start / 2);

            if (isValid(mid, n, nums))
                end = mid - 1;
            else 
                start = mid + 1;
        }

        return start;
    }
};

// only using prefix sum

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();

        long long sum = nums[0];
        int minMax = nums[0];

        // we can't minmize first element

        for (int idx = 1; idx < n; idx++) {
            sum += nums[idx];

            // if avg of nums till idx is greater than sum 
            // then we will need to update our ans
            
            if (sum % (idx + 1) != 0) {
                sum / (idx + 1) + 1 > minMax ? minMax = sum / (idx + 1) + 1 : minMax;
            }
            else {
                sum / (idx + 1) > minMax ? minMax = sum / (idx + 1) : minMax;
            }
                
        }

        return minMax;
    }
};