// 2762. Continuous Subarrays
// Medium
// 230
// 2
// Companies

// You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

//     Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.

// Return the total number of continuous subarrays.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [5,4,2,4]
// Output: 8
// Explanation: 
// Continuous subarray of size 1: [5], [4], [2], [4].
// Continuous subarray of size 2: [5,4], [4,2], [2,4].
// Continuous subarray of size 3: [4,2,4].
// Thereare no subarrys of size 4.
// Total continuous subarrays = 4 + 3 + 1 = 8.
// It can be shown that there are no more continuous subarrays.

 

// Example 2:

// Input: nums = [1,2,3]
// Output: 6
// Explanation: 
// Continuous subarray of size 1: [1], [2], [3].
// Continuous subarray of size 2: [1,2], [2,3].
// Continuous subarray of size 3: [1,2,3].
// Total continuous subarrays = 3 + 2 + 1 = 6.

 

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 109

// Accepted
// 6.2K
// Submissions
// 18.4K
// Acceptance Rate
// 33.5%


// Time Complexity : O(N) + O(N*Log(LogN)) (for sieve)
// Space Complexity : O(N)

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        long long subarrayCount = 0;
        int left = 0;
        int smallest, largest;

        map<int, int> smallestTracker;
        map<int, int, greater<int>> largestTracker;

        for (int right = 0; right < n; right++) {
            smallestTracker[nums[right]]++;
            largestTracker[nums[right]]++;
            
            if (smallestTracker.size() == 0) {
                smallest = nums[right];
                largest = nums[right];
            } else {
                smallest = smallestTracker.begin()->first;
                largest = largestTracker.begin()->first;
            }
            
            while (left <= right && abs(smallest - largest) > 2) {
                smallestTracker[nums[left]]--;
                largestTracker[nums[left]]--;

                if (smallestTracker[nums[left]] == 0) {
                    smallestTracker.erase(nums[left]);
                }
                
                if (largestTracker[nums[left]] == 0) {
                    largestTracker.erase(nums[left]);
                }

                left++;

                smallest = smallestTracker.begin()->first;
                largest = largestTracker.begin()->first;
            }

            subarrayCount += (right - left + 1);
        }

        return subarrayCount;
    }
};

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        long long subarrayCount = 0;
        int left = 0;

        multiset<int> tracker;

        for (int right = 0; right < n; right++) {
            tracker.insert(nums[right]);
            
            int smallest = *tracker.begin(), largest = *tracker.rbegin();
            
            while (left <= right && abs(smallest - largest) > 2) {
                auto it = tracker.find(nums[left]);
                tracker.erase(it);

                left++;

                smallest = *tracker.begin();
                largest = *tracker.rbegin();
            }

            subarrayCount += (right - left + 1);
        }

        return subarrayCount;
    }
};