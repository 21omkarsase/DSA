// 403. Frog Jump
// Hard
// 4.5K
// 212
// Companies

// A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

// Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

// If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

 

// Example 1:

// Input: stones = [0,1,3,5,6,8,12,17]
// Output: true
// Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.

// Example 2:

// Input: stones = [0,1,2,3,4,8,9,11]
// Output: false
// Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.

 

// Constraints:

//     2 <= stones.length <= 2000
//     0 <= stones[i] <= 231 - 1
//     stones[0] == 0
//     stones is sorted in a strictly increasing order.

// Accepted
// 206.3K
// Submissions
// 467K
// Acceptance Rate
// 44.2%








// **************************INSTEAD OF USING VECTOR, USE HASH TABLE FOR DP

// Time Complexity : O(N^2)
// Space Complexity : O(N^2)

class Solution {
    bool isPossibleToCrossTheRiver(int idx, int k, unordered_map<int, int> &tracker, const vector<int> &stones, vector<vector<int>> &dp) {
        cout<<idx<<" : "<<k<<"\n";
        
        if (idx == stones.size() - 1) {
            return true;
        }

       if (dp[idx][k] != -1) {
           return dp[idx][k];
       }

       if (idx == 0) {
           if (tracker.find(stones[idx] + 1) != tracker.end() && tracker[stones[idx] + 1] > idx) {
               if (isPossibleToCrossTheRiver(tracker[stones[idx] + 1], 1, tracker, stones, dp)) {
                    return dp[idx][k] = true;
                }
                
                return dp[idx][k] = false;
           }
           
           return dp[idx][k] = false;
       }
       
       if (tracker.find(stones[idx] + k - 1) != tracker.end() && tracker[stones[idx] + k - 1] > idx) {
           if (isPossibleToCrossTheRiver(tracker[stones[idx] + k - 1], k - 1, tracker, stones, dp)) {
               return dp[idx][k] = true;
           }
       }
       
       if (tracker.find(stones[idx] + k) != tracker.end() && tracker[stones[idx] + k] > idx) {
           if (isPossibleToCrossTheRiver(tracker[stones[idx] + k], k, tracker, stones, dp)) {
               return dp[idx][k] = true;
           }
       }
       
       if (tracker.find(stones[idx] + k + 1) != tracker.end() && tracker[stones[idx] + k + 1] > idx) {
           if (isPossibleToCrossTheRiver(tracker[stones[idx] + k + 1], k + 1, tracker, stones, dp)) {
               return dp[idx][k] = true;
           }
       }

       return dp[idx][k] = false;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, int> tracker;

        for (int idx = 0; idx < n; idx++) {
            tracker[stones[idx]] = idx;
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        return isPossibleToCrossTheRiver(0, 1, tracker, stones, dp);
    }
};

// Time Complexity : O(N^2)
// Space Complexity : O(N^2)

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, int> tracker;

        for (int idx = 0; idx < n; idx++) {
            tracker[stones[idx]] = idx;
        }

        vector<vector<bool>> dp(n, vector<bool>(n + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int k = n; k >= 1; k--) {
                if (idx == stones.size() - 1) {
                    dp[idx][k] = true;
                }
                else if (idx == 0) {
                    if (tracker.find(stones[idx] + 1) != tracker.end() && dp[tracker[stones[idx] + 1]][1]) {
                            dp[idx][k] = true;
                    }
                    else {
                        dp[idx][k] = false;
                    }
                }
                else if (tracker.find(stones[idx] + k - 1) != tracker.end() && tracker[stones[idx] + k - 1] > idx && dp[tracker[stones[idx] + k - 1]][k - 1]) {
                    dp[idx][k] = true;
                }
                else if (tracker.find(stones[idx] + k) != tracker.end() && tracker[stones[idx] + k] > idx && dp[tracker[stones[idx] + k]][k]) {
                    dp[idx][k] = true;
                }
                else if (tracker.find(stones[idx] + k + 1) != tracker.end() && tracker[stones[idx] + k + 1] > idx && dp[tracker[stones[idx] + k + 1]][k + 1]) {
                    dp[idx][k] = true;
                }
                else {
                    dp[idx][k] = false;
                }
            }
        }

        return dp[0][1];
    }
};


class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int k = n - 1; k >= 1; k--) {
                if (idx == n - 1) {
                    dp[idx][k] = true;
                }
                else if (idx == 0) {
                    if (stones[1] - stones[idx] == k && dp[idx + 1][k]) {
                        dp[idx][k] = true;
                    }
                    else {
                        dp[idx][k] = false;
                    }
                }
                else {
                    for (int curr = idx + 1; curr < stones.size(); curr++) {
                        int jump = stones[curr] - stones[idx];

                        if (jump == k && dp[curr][k]) {
                            dp[idx][k] = true;
                        }
                        else if (jump == k - 1 && dp[curr][k - 1]) {
                            dp[idx][k] = true;
                        }
                        else if (jump == k + 1 && dp[curr][k + 1]) {
                            dp[idx][k] = true;
                        }
                    }                    
                }
            }
        }
        
        return dp[0][1];
    }
};