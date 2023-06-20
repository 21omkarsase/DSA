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

class Solution {
    int findMedian(int &p1, int &p2, vector<int> &nums1, vector<int> &nums2){
        if(p1 < nums1.size() && p2 < nums2.size())
            return nums1[p1] > nums2[p2] ? nums2[p2++] : nums1[p1++];
        else if(p1 < nums1.size())
            return nums1[p1++];
        else
            return nums2[p2++];
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int p1 = 0, p2 = 0;
        
        double firstMedEle;
        for(int i = 0; i < (n1 + n2) / 2; i++){
            firstMedEle = findMedian(p1, p2, nums1, nums2);
        }

        if((n1 + n2) & 1){
            return findMedian(p1, p2, nums1, nums2);
        }else{
            double secondMedEle = findMedian(p1, p2, nums1, nums2);
            return (firstMedEle + secondMedEle) / 2;
        }

    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int low = 0, high = n1;

         if(n1 > n2)
            swap(nums1, nums2);
        n1 = nums1.size(), n2 = nums2.size(), high = n1;

        while(low <= high){
            int mid1 = low + (high - low) / 2;
            int mid2 = (n1 + n2 + 1) / 2 - mid1;

            int left1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
            int left2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];

            int right1 = mid1 == n1 ? INT_MAX : nums1[mid1];
            int right2 = mid2 == n2 ? INT_MAX : nums2[mid2];

            if(left1 <= right2 && left2 <= right1){
                if((n1 + n2) % 2 == 0){
                    return (double)(max(left1, left2) + min(right1, right2)) / 2;
                }
                return max(left1, left2);
            }else if(left1 > right2){
                high = mid1 - 1;
            }else low = mid1 + 1;
        }

        return 0.0;
    }
};