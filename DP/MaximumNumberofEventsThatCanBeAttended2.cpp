// 1751. Maximum Number of Events That Can Be Attended II
// Hard
// 1.6K
// 28
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
// 50K
// Submissions
// 80.6K
// Acceptance Rate
// 62.0%

class Solution {
    int findNextIdx(int idx, vector<vector<int>> &events) {
        int n = events.size();

        int start = idx + 1, end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (events[mid][0] > events[idx][1]) {
                end = mid - 1;
            } 
            else {
                start = mid + 1;
            }
        }

        if (start == n || events[start][0] <= events[idx][1])
            return n;

        return start;
    }
    int calculateMaxValue(int idx, int k, vector<vector<int>> &events, vector<vector<int>> &dp) {
        if (k == 0 || idx == events.size())
            return 0;
        
        if (dp[idx][k] != -1) {
            return dp[idx][k];
        } 

        int take = 0;
        int newIdx = findNextIdx(idx, events);    
        take = calculateMaxValue(newIdx, k - 1, events, dp) + events[idx][2];
            
        int notTake = calculateMaxValue(idx + 1, k, events, dp);

        return dp[idx][k] = max(take, notTake);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        sort(events.begin(), events.end());
        
        return calculateMaxValue(0, k, events, dp);
    }
};