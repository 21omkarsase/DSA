// 1248. Count Number of Nice Subarrays
// Medium
// 3K
// 64
// Companies

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

 

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There is no odd numbers in the array.

// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16

 

// Constraints:

//     1 <= nums.length <= 50000
//     1 <= nums[i] <= 10^5
//     1 <= k <= nums.length

// Accepted
// 85.8K
// Submissions
// 139K
// Acceptance Rate
// 61.7%


// this approach is preferred when we don't know how/when to shrink window 
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        int oddElementsCount = 0, niceSubarraysCount = 0;
        unordered_map<int, int> oddCountTracker;

        for (int idx = 0; idx < n; idx++) {
            if (nums[idx] & 1) 
                oddElementsCount++;
            
            if (oddElementsCount == k)
               niceSubarraysCount++;

            if (oddCountTracker.find(oddElementsCount - k) != oddCountTracker.end())
                niceSubarraysCount += (oddCountTracker[oddElementsCount - k]);

            oddCountTracker[oddElementsCount]++; 
        }

        return niceSubarraysCount;
    }
};

// this approach is preferred when we don't know how/when to shrink window 
// Time Complexity : O(2N)
// Space Complexity : O(1)

class Solution {
    int countSubarraysForKOddElements(int k, vector<int> &nums) {
        int n = nums.size();

        int left = 0, oddElementsCount = 0, niceSubarraysCount = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] & 1) 
                oddElementsCount++;

            while (oddElementsCount > k && left <= right) {
                if (nums[left] & 1)
                    oddElementsCount--;
                
                left++;
            } 

            niceSubarraysCount += (right - left + 1);
        }

        return niceSubarraysCount;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubarraysForKOddElements(k, nums) - countSubarraysForKOddElements(k - 1, nums);
        // all subarrays with odd count k - all subarrays with count k - 1 = all subarrays with count exactly k
    }
};