// 2134. Minimum Swaps to Group All 1's Together II
// Medium
// 940
// 13
// Companies

// A swap is defined as taking two distinct positions in an array and swapping the values in them.

// A circular array is defined as an array where we consider the first element and the last element to be adjacent.

// Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

 

// Example 1:

// Input: nums = [0,1,0,1,1,0,0]
// Output: 1
// Explanation: Here are a few of the ways to group all the 1's together:
// [0,0,1,1,1,0,0] using 1 swap.
// [0,1,1,1,0,0,0] using 1 swap.
// [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
// There is no way to group all 1's together with 0 swaps.
// Thus, the minimum number of swaps required is 1.

// Example 2:

// Input: nums = [0,1,1,1,0,0,1,1,0]
// Output: 2
// Explanation: Here are a few of the ways to group all the 1's together:
// [1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
// [1,1,1,1,1,0,0,0,0] using 2 swaps.
// There is no way to group all 1's together with 0 or 1 swaps.
// Thus, the minimum number of swaps required is 2.

// Example 3:

// Input: nums = [1,1,0,0,1]
// Output: 0
// Explanation: All the 1's are already grouped together due to the circular property of the array.
// Thus, the minimum number of swaps required is 0.

 

// Constraints:

//     1 <= nums.length <= 105
//     nums[i] is either 0 or 1.

// Accepted
// 22.5K
// Submissions
// 43.9K
// Acceptance Rate
// 51.3%


// Time Complexity : O(N))
// Space Complexity : O(1)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnesCount = count(nums.begin(), nums.end(), 1);

        if (totalOnesCount == 0)
            return 0;

        int left = 0, right = 0, zerosCount = 0, totalSwapsReq = n;

        for (right = 0; right < n + totalOnesCount - 1; right++) {
            if (nums[right % n] == 0)
                zerosCount++;

            if (right - left + 1 == totalOnesCount) {
                totalSwapsReq = min(totalSwapsReq, zerosCount);

                if (nums[left++] == 0)
                   zerosCount--;
            }
        }

        return totalSwapsReq;
    }
};



class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnesCount = count(nums.begin(), nums.end(), 1);

        if (totalOnesCount == 0)
            return 0;

        int left = 0, right = 0, zerosCount = 0, totalSwapsReq = n;

        for (right = 0; right < n; right++) {
            if (nums[right] == 0)
                zerosCount++;

            if (right - left + 1 == totalOnesCount) {
                totalSwapsReq = min(totalSwapsReq, zerosCount);

                if (nums[left++] == 0)
                   zerosCount--;
            }
        }

        left = 0, right = n - totalOnesCount + 1;
        int leftZerosCount = 0, rightZerosCount = 0;

        for (int idx = n - 1; idx >= right; idx--) {
            if (nums[idx] == 0)
                rightZerosCount++;
        }

        while (left <= totalOnesCount - 2) {
            if(nums[left++] == 0)
                leftZerosCount++;

            totalSwapsReq = min(totalSwapsReq, leftZerosCount + rightZerosCount);
            
            if (nums[right++] == 0)
                rightZerosCount--;
        }
        

        return totalSwapsReq;
    }
};



