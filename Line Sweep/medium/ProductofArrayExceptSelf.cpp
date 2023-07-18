// 238. Product of Array Except Self
// Medium
// 18.2K
// 997
// Companies

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

 

// Constraints:

//     2 <= nums.length <= 105
//     -30 <= nums[i] <= 30
//     The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
// Accepted
// 1.7M
// Submissions
// 2.6M
// Acceptance Rate
// 65.1%

// Time Complexity : O(2N)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int totalProduct = 1;
        int totalZeros = 0;

        for (int idx = 0; idx < n; idx++) {
            totalProduct *= nums[idx];
            
            if (nums[idx] == 0)
                totalZeros++; 
        }   
        
        int zeroIdx = -1, zeroPreProduct = 1, zeroPostProduct = 1;
        bool flag = false;
        vector<int> products(n, 0);

        if (totalZeros > 1)
            return products;
        
        for (int idx = 0; idx < n; idx++) {
            if (nums[idx] != 0) {
                flag ? zeroPostProduct *= nums[idx] : zeroPreProduct *= nums[idx];

                products[idx] = totalProduct / nums[idx];
            }else 
                zeroIdx = idx;
        }

        if (totalZeros == 1) 
            products[zeroIdx] = zeroPreProduct * zeroPostProduct;

        return products;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        int leftProduct = 1, rightProduct = 1;
        vector<int> products(n, 1);

        for (int idx = 0; idx < n; idx++) {
            products[idx] *= leftProduct;
            products[n - idx - 1] *= rightProduct;

            leftProduct *= nums[idx];
            rightProduct *= nums[n - idx - 1];
        }

        return products;
    }
};