// 57. Insert Interval
// Medium
// 8.5K
// 606
// Companies

// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

 

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

 

// Constraints:

//     0 <= intervals.length <= 104
//     intervals[i].length == 2
//     0 <= starti <= endi <= 105
//     intervals is sorted by starti in ascending order.
//     newInterval.length == 2
//     0 <= start <= end <= 105

// Accepted
// 783.3K
// Submissions
// 2M
// Acceptance Rate
// 39.2%

// Time Complexity : O(N*LogN)
// Space Complexity : O(N) (for sort)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        
        vector<vector<int>> nonOverlappingIntervals;
        int prevStart = intervals[0][0], prevEnd = intervals[0][1];

        for (int idx = 1; idx < n; idx++) {
            int start = intervals[idx][0], end = intervals[idx][1];

            if (start <= prevEnd) {
                prevEnd = max(prevEnd, end);
                continue;
            }

            nonOverlappingIntervals.push_back({prevStart, prevEnd});
            prevStart = start;
            prevEnd = end;
        }

        nonOverlappingIntervals.push_back({prevStart, prevEnd});

        return nonOverlappingIntervals;
    }
};


// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        vector<vector<int>> nonOverlappingIntervals;

        for (int idx = 0; idx < n; idx++) {
            int currStart = intervals[idx][0], currEnd = intervals[idx][1];
            int newStart = newInterval[0], newEnd = newInterval[1];

            if(currStart > newEnd) {
                nonOverlappingIntervals.push_back(newInterval);
                
                newInterval = intervals[idx];
            }
            else if(currEnd < newStart) 
                nonOverlappingIntervals.push_back(intervals[idx]);
            else {
                newInterval[0] = min(newStart, currStart);
                newInterval[1] = max(newEnd, currEnd);
            }
        }

        nonOverlappingIntervals.push_back(newInterval);

        return nonOverlappingIntervals;
    }
};