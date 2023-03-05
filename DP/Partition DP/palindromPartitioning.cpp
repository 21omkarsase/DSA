// Given a string s, partition s such that every
// substring
// of the partition is a
// palindrome
// .

// Return the minimum cuts needed for a palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

// Example 2:

// Input: s = "a"
// Output: 0

// Example 3:

// Input: s = "ab"
// Output: 1

 

// Constraints:

//     1 <= s.length <= 2000
//     s consists of lowercase English letters only.



#include<bits/stdc++.h>
using namespace std;

// int maxCoinsTabulation(vector<int>& nums) {
//     int n = nums.size();
//     int ans = INT_MAX;

//     nums.push_back(1);
//     nums.insert(nums.begin(), 1);

//     vector<vector<int>> dp(n + 3, vector<int>(n + 3, 0));

//     for(int i = n; i >= 1; i--){
//         for(int j = i; j <= n; j++){
//             int ans = INT_MIN;
//             for(int k = i; k <= j; k++){
//                 int cost = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
//                 ans = max(ans, cost);
//             }

//             dp[i][j] =  ans;
//         }
//     }

//     return dp[1][n];
// }


bool isPalindrome(string &s, int i, int j){
    while(i <= j){
        if(s[i++] != s[j--]) return false;
    }

    return true;
}

int minCutTabulation(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);

    for(int i = n - 1; i >= 0; i--){
        int cuts = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalindrome(s, i, j)){
                int ans = dp[j + 1] + 1;
                cuts = min(cuts, ans);
            }
        }

        dp[i] = cuts;
    }

    return dp[0] - 1;
}


int minCutHelperMemoization(string &s, vector<int> &dp, int i, int n){
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int cuts = INT_MAX;
    for(int j = i; j < n; j++){
        if(isPalindrome(s, i, j)){
           int ans = minCutHelperMemoization(s, dp, j + 1, n) + 1;
           cuts = min(cuts, ans);
        }
    }

    return dp[i] = cuts;
}
int minCutMemoization(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return minCutHelperMemoization(s, dp, 0, n) - 1;
}

int main(){
    string s; 
    cin >> s;

    cout<<minCutMemoization(s)<<"\n";

    cout<<minCutTabulation(s)<<"\n";

    return 0;
}