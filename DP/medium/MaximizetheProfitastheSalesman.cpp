// 2830. Maximize the Profit as the Salesman
// Medium
// 392
// 14
// Companies

// You are given an integer n representing the number of houses on a number line, numbered from 0 to n - 1.

// Additionally, you are given a 2D integer array offers where offers[i] = [starti, endi, goldi], indicating that ith buyer wants to buy all the houses from starti to endi for goldi amount of gold.

// As a salesman, your goal is to maximize your earnings by strategically selecting and selling houses to buyers.

// Return the maximum amount of gold you can earn.

// Note that different buyers can't buy the same house, and some houses may remain unsold.

 

// Example 1:

// Input: n = 5, offers = [[0,0,1],[0,2,2],[1,3,2]]
// Output: 3
// Explanation: There are 5 houses numbered from 0 to 4 and there are 3 purchase offers.
// We sell houses in the range [0,0] to 1st buyer for 1 gold and houses in the range [1,3] to 3rd buyer for 2 golds.
// It can be proven that 3 is the maximum amount of gold we can achieve.

// Example 2:

// Input: n = 5, offers = [[0,0,1],[0,2,10],[1,3,2]]
// Output: 10
// Explanation: There are 5 houses numbered from 0 to 4 and there are 3 purchase offers.
// We sell houses in the range [0,2] to 2nd buyer for 10 golds.
// It can be proven that 10 is the maximum amount of gold we can achieve.

 

// Constraints:

//     1 <= n <= 105
//     1 <= offers.length <= 105
//     offers[i].length == 3
//     0 <= starti <= endi <= n - 1
//     1 <= goldi <= 103

// Accepted
// 12.6K
// Submissions
// 38.5K
// Acceptance Rate
// 32.7%

// Time Complexity : O(M * LogM)
// Space Complexity : O(M)

class Solution {
    int findNextHouseToSell(int idx, const int &n, const vector<vector<int>> &offers) {
        int start = idx + 1, end = n - 1;
        int ans = n;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (offers[idx][1] >= offers[mid][0]) {
                start = mid + 1;
            }
            else {
                ans = mid;
                end = mid - 1;
            }
        }
        
        return ans;
    }

    int calculateMaxProfit(int idx, const int &n,  const vector<vector<int>> &offers, vector<int> &dp) {
        if (idx >= n) {
            return 0;
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }

        int nextToTake = findNextHouseToSell(idx, n, offers);

        int take = offers[idx][2] + calculateMaxProfit(nextToTake, n, offers, dp);
        
        int notTake = calculateMaxProfit(idx + 1, n, offers, dp);

        return dp[idx] = max(take, notTake);
    }
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        
        sort(offers.begin(), offers.end());
        vector<int> dp(m, -1);

        return calculateMaxProfit(0, m, offers, dp);
    }
};