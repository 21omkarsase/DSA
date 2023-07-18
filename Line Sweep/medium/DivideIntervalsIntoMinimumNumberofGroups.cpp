// 2406. Divide Intervals Into Minimum Number of Groups
// Medium
// 676
// 10
// Companies

// You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

// You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

// Return the minimum number of groups you need to make.

// Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.

 

// Example 1:

// Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
// Output: 3
// Explanation: We can divide the intervals into the following groups:
// - Group 1: [1, 5], [6, 8].
// - Group 2: [2, 3], [5, 10].
// - Group 3: [1, 10].
// It can be proven that it is not possible to divide the intervals into fewer than 3 groups.

// Example 2:

// Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
// Output: 1
// Explanation: None of the intervals overlap, so we can put all of them in one group.

 

// Constraints:

//     1 <= intervals.length <= 105
//     intervals[i].length == 2
//     1 <= lefti <= righti <= 106

// Accepted
// 22.1K
// Submissions
// 47.8K
// Acceptance Rate
// 46.2%

// Time Complexity : O(N^2)
// Space Complexity : O(N)


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int totalCnt = 0;
        vector<int> visited(n, 0);

        for (int idx1 = 0; idx1 < n; idx1++) {
            int x1 = intervals[idx1][0], y1 = intervals[idx1][1];
        
            if (!visited[idx1]) {
                totalCnt++;
                visited[idx1] = 1;
                
                for (int idx2 = idx1 + 1; idx2 < n; idx2++) {
                    if (!visited[idx2]) {
                        int x2 = intervals[idx2][0], y2 = intervals[idx2][1];

                        if (x2 > y1) {
                            visited[idx2] = 1;
                            y1 = y2;
                        }
                    }
                }
            }
        }

        return totalCnt;
    }
};

// similar solution to minimum no. of platfoms required
// Time Complexity : O(N*LogN)
// Space Complexity : O(N)

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> arrivalTime(n, 0), departureTime(n, 0);
    
        for (int idx = 0; idx < n; idx++) {
            arrivalTime[idx] = intervals[idx][0];
            departureTime[idx] = intervals[idx][1];
        }

        sort(arrivalTime.begin(), arrivalTime.end());
        sort(departureTime.begin(), departureTime.end());
        
        int totalPlatfoms = 0, freePlatfoms = 0;
        int arrival = 0, departure = 0;

        // while (arrival < n) {
        //     if (arrivalTime[arrival] > departureTime[departure]) {
        //         if (freePlatfoms > 0) {
        //             freePlatfoms++;
        //         }
        //         departure++;
        //     } else {
        //         if (freePlatfoms > 0) {
        //             freePlatfoms--;
        //             departure++;
        //         } else
        //             totalPlatfoms++;
        //     }
            
        //     arrival++;
        // }
        
        // return totalPlatfoms;

        while (arrival < n) {
            if (arrivalTime[arrival] <= departureTime[departure]){
                if (freePlatfoms > 0) {
                    freePlatfoms--;
                } else {
                    totalPlatfoms++;
                    departure--;
                }
            }
            
            arrival++, departure++;
        }
        
        return totalPlatfoms;
    }
};

//using priority queue

// Time Complexity : O(N*LogN)
// Space Complexity : O(K)


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());
        
        int groupCnt = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int idx = 0; idx < n; idx++) {
            int first = intervals[idx][0], second = intervals[idx][1];

            if (pq.empty() || pq.top() >= first) // will always compare with previou smallest element (if present in queue)
                groupCnt++;
            else 
                pq.pop(); // as we have sorted array and curr ele is greater than top, we can put it into same grp (but it is imp to update last(max))

            pq.push(second);
        } 
        
        return groupCnt;
    }
};




// using line sweep algo (used intersection problems)
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<int> sum(1000005, 0);

        for (int idx = 0; idx < n; idx++) {
            int first = intervals[idx][0], second = intervals[idx][1];

            sum[first]++, sum[second + 1]--;
        }

        int groupCnt = 0;
        int prefix = 0;

        for (int idx = 0; idx < sum.size(); idx++) {
            prefix += sum[idx];
            groupCnt = max(groupCnt, prefix);
        }
        
        return groupCnt;
    }
};

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        map<int, int> tracker;

        for (int idx = 0; idx < n; idx++) {
            int first = intervals[idx][0], second = intervals[idx][1];

            tracker[first]++, tracker[second + 1]--;
        }

        int groupCnt = 0;
        int prefix = 0;

        for (auto it : tracker) {
            prefix += it.second;
            groupCnt = max(groupCnt, prefix);
        }
        
        return groupCnt;
    }
};