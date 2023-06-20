// 2149. Rearrange Array Elements by Sign
// Medium
// 1.7K
// 79
// Companies

// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should rearrange the elements of nums such that the modified array follows the given conditions:

//     Every consecutive pair of integers have opposite signs.
//     For all integers with the same sign, the order in which they were present in nums is preserved.
//     The rearranged array begins with a positive integer.

// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 

// Example 1:

// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]
// Explanation:
// The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
// The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
// Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

// Example 2:

// Input: nums = [-1,1]
// Output: [1,-1]
// Explanation:
// 1 is the only positive integer and -1 the only negative integer in nums.
// So nums is rearranged to [1,-1].

 

// Constraints:

//     2 <= nums.length <= 2 * 105
//     nums.length is even
//     1 <= |nums[i]| <= 105
//     nums consists of equal number of positive and negative integers.

// Accepted
// 89.1K
// Submissions
// 109.6K
// Acceptance Rate
// 81.3%


// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> signSorted(n, 0);

        int positiveEleIdx = 0, negativeEleIdx = 1;

        for(auto ele : nums){
            if(ele > 0){
                signSorted[positiveEleIdx] = ele;
                positiveEleIdx += 2;
            }
            if(ele < 0){
                signSorted[negativeEleIdx] = ele;
                negativeEleIdx += 2;
            }
        }

        return signSorted;
    }
};

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> signSorted(n, 0);

        int left = 0, right = n - 1, start = 0, end = n - 1;

        while(start < n){
            if(nums[start] > 0){
                signSorted[left] = nums[start];
                left += 2;
            }
            if(nums[end] < 0){
                signSorted[right] = nums[end];
                right -= 2;
            }
            start++, end--; 
        }

        return signSorted;
    }
};