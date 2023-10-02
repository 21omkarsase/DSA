// 1751. Maximum Number of Events That Can Be Attended II
// Hard
// 1.9K
// 35
// Companies

// You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

// You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

// Return the maximum sum of values that you can receive by attending events.

 

// Example 1:

// Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
// Output: 7
// Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.

// Example 2:

// Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
// Output: 10
// Explanation: Choose event 2 for a total value of 10.
// Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.

// Example 3:

// Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
// Output: 9
// Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.

 

// Constraints:

//     1 <= k <= events.length
//     1 <= k * events.length <= 106
//     1 <= startDayi <= endDayi <= 109
//     1 <= valuei <= 106

// Accepted
// 68.5K
// Submissions
// 108.3K
// Acceptance Rate
// 63.2%

// Time Complexity : O(N * K * Log(N))
// Space Complexity : O(N * K) + O(N + K)

class Solution {
    int findNextPossibleEvent(const int &limit, int start, int end, const vector<vector<int>> &events) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (events[mid][0] > limit) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return start;
    }
    int calculateMaxValue(int idx, int k, const int &n,  const vector<vector<int>> &events, vector<vector<int>> &dp) {
        if (idx == n || k == 0) {
            return 0;
        }

        if (dp[idx][k] != -1) {
            return dp[idx][k];
        }

        int nextEventToAttend = findNextPossibleEvent(events[idx][1], idx + 1, n - 1, events);

        int take = calculateMaxValue(nextEventToAttend, k - 1, n, events, dp) + events[idx][2];
        int notTake = calculateMaxValue(idx + 1, k, n, events, dp);

        return dp[idx][k] = max(take, notTake);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        return calculateMaxValue(0, k, n, events, dp);
    }
};


// Time Complexity : O(N * K * Log(N))
// Space Complexity : O(N * K)

class Solution {
    int findNextPossibleEvent(const int &limit, int start, int end, const vector<vector<int>> &events) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (events[mid][0] > limit) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

       return start;
    }
public:
    int maxValue(vector<vector<int>>& events, int limit) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<vector<int>> dp(n + 1, vector<int>(limit + 1, 0));

        for (int idx = n; idx >= 0; idx--) {
            for (int k = 0; k <= limit; k++) {
                if (idx == n || k == 0) {
                    dp[idx][k] = 0;
                }
                else {
                    int nextEventToAttend = findNextPossibleEvent(events[idx][1], idx + 1, n - 1, events);

                    int take = dp[nextEventToAttend][k - 1] + events[idx][2];
                    int notTake = dp[idx + 1][k];

                    dp[idx][k] = max(take, notTake);
                }
            }
        }

        return dp[0][limit];
    }
};