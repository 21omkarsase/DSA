// 560. Subarray Sum Equals K
// Medium
// 18.6K
// 547
// Companies

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

 

// Constraints:

//     1 <= nums.length <= 2 * 104
//     -1000 <= nums[i] <= 1000
//     -107 <= k <= 107

// Accepted
// 990.4K
// Submissions
// 2.3M
// Acceptance Rate
// 43.5%

// Time Complexity : O(N^2)
// Space Complexity : O(1)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int subarrayCount = 0;

        for(int idx1 = 0; idx1 < n; idx1++) {
            int sum = 0;
            for(int idx2 = idx1; idx2 < n; idx2++) {
                sum += nums[idx2];
                if(sum == k)
                    subarrayCount++;
            }
        }

        return subarrayCount;
    }
};


// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0, subarrayCount = 0;

        unordered_map<int, int>tracker;
        tracker[0] = 1;


        for (int idx = 0; idx < n; idx++) {
            sum += nums[idx];

            int requireSum = sum - k;

            if(tracker.find(requireSum) != tracker.end())
                subarrayCount += tracker[requireSum];
            
            tracker[sum]++;
        }

        return subarrayCount;

    }
};