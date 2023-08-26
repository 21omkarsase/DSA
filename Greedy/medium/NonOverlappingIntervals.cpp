// 435. Non-overlapping Intervals
// Medium
// 6.1K
// 164
// Companies

// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

// Example 3:

// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

 

// Constraints:

//     1 <= intervals.length <= 105
//     intervals[i].length == 2
//     -5 * 104 <= starti < endi <= 5 * 104

// Accepted
// 381.7K
// Submissions
// 754.6K
// Acceptance Rate
// 50.6%

// Time Complexity : O(N*LogN)
// Space Complexity : O(N)  // for sort

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());
        
        int lastEnd = intervals[0][1];
        int ans = 0;

        for (int idx = 1; idx < n; idx++) {
            if (lastEnd > intervals[idx][0]) {
                lastEnd = min(lastEnd, intervals[idx][1]);
                ans++;
            } else 
                lastEnd = intervals[idx][1];
        }

        return ans;
    }
};