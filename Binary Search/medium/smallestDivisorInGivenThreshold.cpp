// 1283. Find the Smallest Divisor Given a Threshold
// Medium
// 2.2K
// 172
// Companies

// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

// The test cases are generated so that there will be an answer.

 

// Example 1:

// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

// Example 2:

// Input: nums = [44,22,33,11,1], threshold = 5
// Output: 44

 

// Constraints:

//     1 <= nums.length <= 5 * 104
//     1 <= nums[i] <= 106
//     nums.length <= threshold <= 106

// Accepted
// 112.3K
// Submissions
// 198.7K
// Acceptance Rate
// 56.5%

class Solution {
    bool isValidDivisor(int divisor, int thresh, vector<int> &nums){
        int sum = 0;
        for(auto ele : nums){
            sum += ele / divisor;
            if(ele % divisor != 0)
                sum += 1;
        }

        return sum <= thresh;
    }
public:
    int smallestDivisor(vector<int>& nums, int thresh) {
        int n = nums.size();
        
        if(thresh < n)
            return -1;
        if(thresh == 0)
            return 0;
        
        int st = 1, en = *max_element(nums.begin(), nums.end());

        while(st <= en){
            int mid = st + (en - st) / 2;

            if(isValidDivisor(mid, thresh, nums))
                en = mid - 1;
            else st = mid + 1;
        }

        return st;
    }
};