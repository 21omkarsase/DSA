// A set of real numbers can be represented as the union of several disjoint intervals, where each interval is in the form [a, b). A real number x is in the set if one of its intervals [a, b) contains x (i.e. a <= x < b).

// You are given a sorted list of disjoint intervals intervals representing a set of real numbers as described above, where intervals[i] = [a, b] represents the interval [a, b). You are also given another interval toBeRemoved.

// Return the set of real numbers with the interval toBeRemoved removed from intervals. In other words, return the set of real numbers such that every x in the set is in intervals but not in toBeRemoved. Your answer should be a sorted list of disjoint intervals as described above.

// Example 1:

// Input: intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
// Output: [[0,1],[6,7]]
// Explanation: The intervals [0,2] and [5,7] are remaining after removing [1,6] from [[0,2],[3,4],[5,7]].

// Example 2:

// Input: intervals = [[0,5]], toBeRemoved = [2,3]
// Output: [[0,2],[3,5]]
// Explanation: The interval [2,3] is removed and the remaining intervals are [[0,2],[3,5]].

// Constraints:

//     1 <= intervals.length <= 10^4
//     -10^9 <= a_i < b_i <= 10^9
//     intervals is sorted by ascending order of a_i.
//     toBeRemoved.length == 2
//     -10^9 <= toBeRemoved[0] < toBeRemoved[1] <= 10^9

// In this problem, you are given a sorted list of disjoint intervals that represent a set of real numbers. Each interval is represented by a pair [a, b] which denotes the interval [a, b).

// Your task is to remove the interval toBeRemoved from the given intervals list and return the remaining intervals as a sorted list of disjoint intervals.

// To remove the toBeRemoved interval, you need to split the intervals into smaller intervals or completely remove an interval if it overlaps with toBeRemoved. The result should be a sorted list of disjoint intervals that do not include any part of the toBeRemoved interval.

// Your solution should handle different scenarios, such as removing an interval completely, splitting an interval into two smaller intervals, or leaving an interval unchanged if it doesn't overlap with toBeRemoved.

// The constraints state that the number of intervals can be up to 10^4, and the interval bounds can range from -10^9 to 10^9.

// Your solution should efficiently remove the toBeRemoved interval and return the remaining intervals as a sorted list.



#include<bits/stdc++.h>
using namespace std;

struct Event {
    int time;
    bool isStart;

    Event(int t, bool start) : time(t), isStart(start) {}
};

void removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
    vector<Event> events;
    for (const auto& interval : intervals) {
        events.emplace_back(interval[0], true);   // Start point event
        events.emplace_back(interval[1], false);  // End point event
    }
    events.emplace_back(toBeRemoved[0], true);     // Start point event for toBeRemoved
    events.emplace_back(toBeRemoved[1], false);    // End point event for toBeRemoved

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.time < b.time;
    });

    vector<vector<int>> result;
    int counter = 0;
    int start = -1;

    for (const auto& event : events) {
        if (event.isStart) {
            if (counter == 0) {
                start = event.time;
            }
            counter++;
        } else {
            counter--;
            if (counter == 0) {
                result.push_back({start, event.time});
                cout<<start<<" : "<<event.time<<"\n";
            }
        }
    }

    // return result;
}


int main(){
    vector<vector<vector<int>>> intervals;

    intervals.push_back({{1, 20}});
    intervals.push_back({{1, 5}, {8, 10}, {12, 15}});
    intervals.push_back( {{1, 3}, {5, 8}, {10, 12}});

    vector<int> toBeRemoved = {4, 7};

    for (auto vec : intervals)
        removeInterval(vec, toBeRemoved);
    
    return 0;
}






































