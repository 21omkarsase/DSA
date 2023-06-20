// 1793. Maximum Score of a Good Subarray
// Hard
// 939
// 29
// Companies

// You are given an array of integers nums (0-indexed) and an integer k.

// The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.

// Return the maximum possible score of a good subarray.

 

// Example 1:

// Input: nums = [1,4,3,7,4,5], k = 3
// Output: 15
// Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 

// Example 2:

// Input: nums = [5,5,4,5,4,1,1,1], k = 0
// Output: 20
// Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.

 

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 2 * 104
//     0 <= k < nums.length

// Accepted
// 20.7K
// Submissions
// 38.7K
// Acceptance Rate
// 53.7%

// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(); 

        int left = k, right = k;
        int minNum = nums[k], maxScore = nums[k];

        while(left > 0 || right < n - 1) {
            if(left == 0)
                right++;
            else if(right == n - 1)
                left--;
            else if(nums[left - 1] < nums[right + 1])
                right++;
            else 
                left--;

            minNum = min(minNum, min(nums[left], nums[right]));
            maxScore = max(maxScore, minNum * (right - left + 1));
        }

        return maxScore;
    }
};


// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(); 

        int left = k - 1, right = k + 1;

        int minNum = nums[k], maxScore = nums[k];
        while(left >= 0 && right < n) {
            if(nums[left] > nums[right]) {
                minNum = min(minNum, nums[left]);
                int tempScore = (right - left) * minNum;
                maxScore = max(maxScore, tempScore);
                left--;
            }else {
                minNum = min(minNum, nums[right]);
                int tempScore = (right - left) * minNum;
                maxScore = max(maxScore, tempScore);
                right++;
            }
        }

        while(left >= 0){
            minNum = min(minNum, nums[left]);
            int tempScore = (right - left) * minNum;
            maxScore = max(maxScore, tempScore);
            left--;
        }

        while(right < n){
            minNum = min(minNum, nums[right]);
            int tempScore = (right - left) * minNum;
            maxScore = max(maxScore, tempScore);
            right++;
        }

        return maxScore;
    }
};