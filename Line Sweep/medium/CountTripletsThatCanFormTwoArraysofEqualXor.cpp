// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
// Medium
// 1.2K
// 56
// Companies

// Given an array of integers arr.

// We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

// Let's define a and b as follows:

//     a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
//     b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]

// Note that ^ denotes the bitwise-xor operation.

// Return the number of triplets (i, j and k) Where a == b.

 

// Example 1:

// Input: arr = [2,3,1,6,7]
// Output: 4
// Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)

// Example 2:

// Input: arr = [1,1,1,1,1]
// Output: 10

 

// Constraints:

//     1 <= arr.length <= 300
//     1 <= arr[i] <= 108

// Accepted
// 32.8K
// Submissions
// 43.1K
// Acceptance Rate
// 76.2%

// Time Complexity : O(N^2)
// Space Complexity : O(1)

// In other words we need to calculate total Subarrays with xor 0

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int tripletCnt = 0;

        for (int idx1 = 0; idx1 < n; idx1++) {
            int x = 0;

            if (idx1 + 1 < n) 
                x ^= arr[idx1];

            for (int idx2 = idx1 + 1; idx2 < n; idx2++) {
                x ^= arr[idx2];

                if (x == 0) 
                    tripletCnt += (idx2 - idx1);  // there will be subarray legnth - 1 combinations to make subarray xor == 0
            }
        }

        return tripletCnt;
    }
};