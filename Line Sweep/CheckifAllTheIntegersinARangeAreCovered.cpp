// 1893. Check if All the Integers in a Range Are Covered
// Easy
// 474
// 85
// Companies

// You are given a 2D integer array ranges and two integers left and right. Each ranges[i] = [starti, endi] represents an inclusive interval between starti and endi.

// Return true if each integer in the inclusive range [left, right] is covered by at least one interval in ranges. Return false otherwise.

// An integer x is covered by an interval ranges[i] = [starti, endi] if starti <= x <= endi.

 

// Example 1:

// Input: ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
// Output: true
// Explanation: Every integer between 2 and 5 is covered:
// - 2 is covered by the first range.
// - 3 and 4 are covered by the second range.
// - 5 is covered by the third range.

// Example 2:

// Input: ranges = [[1,10],[10,20]], left = 21, right = 21
// Output: false
// Explanation: 21 is not covered by any range.

 

// Constraints:

//     1 <= ranges.length <= 50
//     1 <= starti <= endi <= 50
//     1 <= left <= right <= 50

// Accepted
// 33K
// Submissions
// 65.8K
// Acceptance Rate
// 50.1%

// Time Complexity : O(N)
// Space Complexity : O(N)
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int n = ranges.size();

        vector<int> tracker(52, 0);

        for (auto range : ranges) {
            tracker[range[0]]++;
            tracker[range[1] + 1]--;
        }

        int prefixSum = 0;

        for (int idx = 1; idx <= right; idx++) {
            prefixSum += tracker[idx];

            if(idx >= left && idx <= right && prefixSum <= 0)
                return false;
                
        }

        return true;
    }
};