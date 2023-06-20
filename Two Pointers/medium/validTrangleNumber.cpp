// 611. Valid Triangle Number
// Medium
// 3.4K
// 188
// Companies

// Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

 

// Example 1:

// Input: nums = [2,2,3,4]
// Output: 3
// Explanation: Valid combinations are: 
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3

// Example 2:

// Input: nums = [4,2,3,4]
// Output: 4

 

// Constraints:

//     1 <= nums.length <= 1000
//     0 <= nums[i] <= 1000

// Accepted
// 171K
// Submissions
// 337.8K
// Acceptance Rate
// 50.6%

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        if(n<3) 
            return 0;
        
        sort(nums.begin(), nums.end());

        for(int i = 2; i < n; i++){
            int start = 0, end = i - 1;

            int target = nums[i];
            while(start < end){
                int sum = nums[start] + nums[end];

                if(target >= sum)
                    start++;
                else{
                    cnt += (end - start);
                    break;
                }
            }
        }
        
        return cnt;
    }
};