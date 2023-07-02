// You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

// You have an array arr of length length with all zeros, and you have some operation to apply on arr. In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.

// Return arr after applying all the updates.

// Example 1:

// Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
// Output: [-2,0,3,5,3]
// Explanation:
// Initial state:
// [0,0,0,0,0]

// After applying operation [1,3,2]:
// [0,2,2,2,0]

// After applying operation [2,4,3]:
// [0,2,5,5,3]

// After applying operation [0,2,-2]:
// [-2,0,3,5,3]

// Example 2:

// Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
// Output: [0,-4,2,2,2,4,4,-4,-4,-4]

// Constraints:

//     1 <= length <= 10^5
//     0 <= updates.length <= 10^4
//     0 <= startIdxi <= endIdxi < length
//     -1000 <= inci <= 1000



#include <iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

 totalRange(vector<vector<int>> &interval) {
    int n = interval.size();

    vector<int> range(n + 1, 0);

    for (int idx = 0; idx < n; idx++) {
        int start = interval[idx][0], end = interval[idx][1], inc = interval[idx][2];

        range[start] += inc;
        range[end + 1] -= inc;
    }

    for (int idx = 1; idx <= n; idx++) {
        range[idx] += range[idx - 1];  
    }

    for (auto ele : range)
        cout<<ele<<" : ";

    cout<<"\n";
}

int main() {
    vector<vector<vector<int>>> intervals;

    intervals.push_back({{{1,3,2},{2,4,3},{0,2,-2}}});

    for (auto vec : intervals)
        totalRange(vec);

    return 0;
}
