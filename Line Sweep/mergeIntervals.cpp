// 56. Merge Intervals
// Medium
// 19.5K
// 662
// Companies

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

 

// Constraints:

//     1 <= intervals.length <= 104
//     intervals[i].length == 2
//     0 <= starti <= endi <= 104

// Accepted
// 1.9M
// Submissions
// 4.2M
// Acceptance Rate
// 46.3%

// Time Complexity : O(N*LogN)
// Space Complexity : O(N) (for sort)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());
        
        int prevStart = intervals[0][0], prevEnd = intervals[0][1];
        vector<vector<int>> nonOverlappingIntervals;

        for (int idx = 1; idx < n; idx++) {
            int currStart = intervals[idx][0], currEnd = intervals[idx][1];

            if (currStart <= prevEnd) {
                prevEnd = max(prevEnd, currEnd);
                continue;
            }

            nonOverlappingIntervals.push_back({prevStart, prevEnd});
            
            prevStart = currStart;
            prevEnd = currEnd;
        }

        nonOverlappingIntervals.push_back({prevStart, prevEnd});

        return nonOverlappingIntervals;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& originalIntervals) {
        vector<vector<int>> intervals = originalIntervals;
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> nonOverlappingIntervals;

        for (int idx = 0; idx < n; idx++) {
           if(idx == 0 || intervals[idx][0] > nonOverlappingIntervals.back()[1])
                nonOverlappingIntervals.push_back(intervals[idx]);
            else {
                nonOverlappingIntervals.back()[1] = max(nonOverlappingIntervals.back()[1], intervals[idx][1]);
            }
        }

        return nonOverlappingIntervals;
    }
};

// using line sweep


// Time Complexity : O(N*LogN)
// Space Complexity : O(N)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int n = intervals.size();

       map<int, int> tracker;

       for (auto interval : intervals) {
           tracker[interval[0]]++;
           tracker[interval[1]]--;
       }

       int prefixSum = 0;
       vector<vector<int>> mergedIntervals;

       for (auto [key, value] : tracker) {
           prefixSum += value;

           if (prefixSum == value) 
               mergedIntervals.push_back({key, -1});

           if (prefixSum == 0) 
               mergedIntervals.back()[1] = key;
       }

       return mergedIntervals;
    }
};