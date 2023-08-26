// 646. Maximum Length of Pair Chain
// Medium
// 3.9K
// 126
// Companies

// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.

 

// Example 1:

// Input: pairs = [[1,2],[2,3],[3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4].

// Example 2:

// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].

 

// Constraints:

//     n == pairs.length
//     1 <= n <= 1000
//     -1000 <= lefti < righti <= 1000

// Accepted
// 178.9K
// Submissions
// 306K
// Acceptance Rate
// 58.5%

// Time Complexity : O(N*N)
// Space Complexity : O(N*N) + O(N + N)

class Solution {
    int calculateLongestChainLength(int currIdx, int prevIdx, vector<vector<int>> &pairs, vector<vector<int>> &dp) {
        if (currIdx >= pairs.size()) {
            return 0;
        }

        if (dp[currIdx + 1][prevIdx + 1] != -1) {
            return dp[currIdx + 1][prevIdx + 1];
        }

        int take = 0, notTake = 0;

        if (prevIdx == -1 || pairs[prevIdx][1] < pairs[currIdx][0]) {
            take = calculateLongestChainLength(currIdx + 1, currIdx, pairs, dp) + 1;
        }

        notTake = calculateLongestChainLength(currIdx + 1, prevIdx, pairs, dp);
        
        return dp[currIdx + 1][prevIdx + 1] = max(take, notTake);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return calculateLongestChainLength(0, -1, pairs, dp);
    }
};


// Time Complexity : O(N*N)
// Space Complexity : O(N*N)

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int currIdx = n; currIdx >= 1; currIdx--) {
            for (int prevIdx = n - 1; prevIdx >= 0; prevIdx--) {
                int take = 0, notTake = 0;

                if (prevIdx == 0 || pairs[prevIdx - 1][1] < pairs[currIdx - 1][0]) {
                    take = dp[currIdx + 1][currIdx] + 1;
                }

                notTake = dp[currIdx + 1][prevIdx];
                
                dp[currIdx][prevIdx] = max(take, notTake);
            }
        }

        return dp[1][0];
    }
};



// Time Complexity : O(N*N)
// Space Complexity : O(N)

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end());
        vector<int> curr(n + 1, 0), prev(n + 1, 0);

        for (int currIdx = n; currIdx >= 1; currIdx--) {
            for (int prevIdx = n - 1; prevIdx >= 0; prevIdx--) {
                int take = 0, notTake = 0;

                if (prevIdx == 0 || pairs[prevIdx - 1][1] < pairs[currIdx - 1][0]) {
                    take = prev[currIdx] + 1;
                }

                notTake = prev[prevIdx];
                
                curr[prevIdx] = max(take, notTake);
            }

            prev = curr;
        }

        return prev[0];
    }
};


// Time Complexity : O(N*LogN)
// Space Complexity : O(1) (O(N) for sorting)

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();

        int longestChainLength = n;
        int lastEnd = pairs[0][1];

        for (int idx = 1; idx < n; idx++) {
            if (pairs[idx][0] <= lastEnd) {
                longestChainLength--;
                lastEnd = min(lastEnd, pairs[idx][1]);
            }
            else {
                lastEnd = pairs[idx][1];
            }
        }

        return longestChainLength;
    }
};