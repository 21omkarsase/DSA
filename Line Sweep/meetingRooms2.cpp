// Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

// Example 1:

// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: 2

// Example 2:

// Input: intervals = [[7,10],[2,4]]
// Output: 1

// Constraints:

//     1 <= intervals.length <= 10^4
//     intervals[i].length == 2
//     0 <= starti < endi <= 10^6

// In this problem, you are given an array of meeting time intervals. Each interval consists of two integers: the start time and end time of a meeting. Your task is to find the minimum number of conference rooms required to hold all the meetings without any overlap.

// The intervals are provided in no particular order, and the start and end times of the meetings can be any non-negative integers.

// Your solution should efficiently determine the minimum number of conference rooms required and return that value.

// The constraints state that the number of intervals can be up to 10^4, and the start and end times of each interval can be up to 10^6.

// Note that a conference room can only be used for one meeting at a time. If a meeting starts at the same time another meeting ends, they are considered not to overlap.

// Your solution should calculate the minimum number of conference rooms required based on the given intervals and return that number.


#include <iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int calculateRooms(vector<pair<int, int>> &interval) {
    int n = interval.size();

    sort(interval.begin(), interval.end());


    map<int, int> tracker;

    for (int idx = 0; idx < n; idx++) {
        int start = interval[idx].first, end = interval[idx].second;

        tracker[start]++;
        tracker[end + 1]--;
    }

    int roomCount = 0;
    int prefixSum = 0;

    for (auto it : tracker) {
        prefixSum += it.second;
        cout<<prefixSum<<" : ";
        roomCount = max(roomCount, prefixSum);
    }
    cout<<"\n";

    return roomCount;
}

int main() {
    vector<vector<pair<int, int>>> intervals;

    intervals.push_back({{5,8},{4,6},{1,3}});
    intervals.push_back({{5,8},{9,10},{1,3}});
    intervals.push_back({{5,8},{8,11},{1,3}});
    intervals.push_back({{1,5},{5,8},{8,11},{1,3}});
    intervals.push_back({{10,12},{4,6},{7,8}});

    for (auto vec : intervals)
        cout<<(calculateRooms(vec))<<" \n";

    return 0;
}






































