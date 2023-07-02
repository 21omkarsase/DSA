// Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

// Example 1:

// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: false

// Example 2:

// Input: intervals = [[7,10],[2,4]]
// Output: true

// Constraints:

//     0 <= intervals.length <= 10^4
//     intervals[i].length == 2
//     0 <= starti < endi <= 10^6

// In this problem, you are given an array of meeting time intervals. Each interval consists of two integers: the start time and end time of a meeting. Your task is to determine if a person can attend all the meetings without any overlap.

// If there are no overlaps and it is possible for a person to attend all meetings, return true. Otherwise, if there is any overlap and it is not possible to attend all meetings, return false.

// The intervals are provided in no particular order, and the start and end times of the meetings can be any non-negative integers.

// The constraints state that the number of intervals can be up to 10^4, and the start and end times of each interval can be up to 10^6.

// Your solution should efficiently determine whether it is possible for a person to attend all meetings without any overlap and return the corresponding boolean value.

// for each interval array
// Time Complexity : O(N*LogN)
// Space Complexity : O(1)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isPossibleToAttendAllMeets(vector<pair<int, int>> &interval) {
    int n = interval.size();

    sort(interval.begin(), interval.end());

    int lastEnd = interval[0].second;

    for (int idx = 1; idx < n; idx++) {
        if (interval[idx].first <= lastEnd)
            return false;

        lastEnd = max(lastEnd, interval[idx].second);
    }

    return true;
}

int main() {
    vector<vector<pair<int, int>>> intervals;

    intervals.push_back({{5,8},{4,6},{1,3}});
    intervals.push_back({{5,8},{9,10},{1,3}});
    intervals.push_back({{5,8},{8,6},{1,3}});
    intervals.push_back({{10,12},{4,6},{7,8}});

    for (auto vec : intervals)
        cout<<(isPossibleToAttendAllMeets(vec))<<" \n";


    return 0;
}



























