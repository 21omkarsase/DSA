// 4. Median of Two Sorted Arrays
// Hard
// 23.8K
// 2.7K
// Companies

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

 

// Constraints:

//     nums1.length == m
//     nums2.length == n
//     0 <= m <= 1000
//     0 <= n <= 1000
//     1 <= m + n <= 2000
//     -106 <= nums1[i], nums2[i] <= 106

// Accepted
// 1.9M
// Submissions
// 5.3M
// Acceptance Rate
// 36.6%

// Time Complexity : O((n1 + n2) / 2)
// Space Complexity : O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        int prev = -1, curr = -1;
        int idx1 = 0, idx2 = 0;

        while (idx1 + idx2 < ((n + m) / 2) + 1) {
            if (idx1 < n && (idx2 >= m || nums1[idx1] <= nums2[idx2])) {
                prev = curr;
                curr = nums1[idx1];
                idx1++;
            }
            else if (idx2 < m && (idx1 >= n || nums2[idx2] <= nums1[idx1])) {
                prev = curr;
                curr = nums2[idx2];
                idx2++;
            }
        }

        if ((n + m) & 1) {
            return curr;
        }

        return (prev + curr) / 2.0;
    }
};


// Time Complexity : O(Log(N + M))
// Space Complexity : O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 > n2) {
            swap(nums1, nums2);
            
            n1 = nums1.size(), n2 = nums2.size();
        }

        int low = 0, high = n1;

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = (n1 + n2) / 2 - mid1;

            int left1 = mid1 - 1 >= 0 ? nums1[mid1 - 1] : INT_MIN;
            int left2 = mid2 - 1 >= 0 ? nums2[mid2 - 1] : INT_MIN;

            int right1 = mid1 < n1 ? nums1[mid1] : INT_MAX;
            int right2 = mid2 < n2 ? nums2[mid2] : INT_MAX;

            if (left1 <= right2 && right1 >= left2) {
                if ((n1 + n2) & 1) {
                    return min(right1, right2);
                }

                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            if (left1 > right2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }

        return 0;
    }
};