// 713. Subarray Product Less Than K
// Medium
// 5.5K
// 172
// Companies

// Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

// Example 1:

// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

// Example 2:

// Input: nums = [1,2,3], k = 0
// Output: 0

 

// Constraints:

//     1 <= nums.length <= 3 * 104
//     1 <= nums[i] <= 1000
//     0 <= k <= 106

// Accepted
// 231.9K
// Submissions
// 503.9K
// Acceptance Rate
// 46.0%



// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int multiplication = 1;
        int left = 0, subarrayCount = 0;

        for (int right = 0; right < n; right++) {
            multiplication *= nums[right];
            
            while (multiplication >= k && left <= right) {
                multiplication /= nums[left++];
            }

            subarrayCount += (right - left + 1);
        }


        return subarrayCount;
    }
};



// Time Complexity : O(2N)
// Space Complexity : O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int prevLeft = -1, prevRight = -1;
        int left = 0, right = 0, multiplication = 1, subarrayCount = 0;

        for (right = 0; right <= n; right++) {
            if (right != n && left == right && nums[right] >= k) {
                prevLeft = -1, prevRight = -1, multiplication = 1;
                left = right + 1;
                continue;
            }

            if(right != n)
                multiplication *= nums[right];

            if ((right == n && multiplication < k) || multiplication >= k) {
                int length = right - left;
                int prevLength = 0;
                
                if (prevRight >= left)
                    prevLength = prevRight - left + 1;
                
                int totalSubarrays = (length * (length + 1)) / 2;
                int overlappingSubArrays = (prevLength * (prevLength + 1)) / 2;

                subarrayCount += (totalSubarrays - overlappingSubArrays);
                
                if(right != n) {
                    prevLeft = left, prevRight = right - 1;
                    multiplication /= nums[left++];
                    multiplication /= nums[right--];
                }
            } 
        }

        return subarrayCount;
    }
};

