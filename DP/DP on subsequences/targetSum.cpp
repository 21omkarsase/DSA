#include <bits/stdc++.h> 
using namespace std;

int findTargetSumWaysSpaceOptimization(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = 0;
    for(auto e : nums) sum += e;
    if(sum - target < 0 || (sum - target)  % 2 != 0) return 0;
    int t = (sum - target) / 2;
    vector<int> prev(t + 1, 0), curr(t + 1, 0);
    
    if(nums[0] == 0) prev[nums[0]] = 2;
    else prev[0] = 1;

    if(nums[0] != 0 && nums[0] <= t) prev[nums[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= t; j++){
            int take = 0;
            if(j >= nums[i]) take = prev[j - nums[i]];
            int notTake = prev[j];

            curr[j] = take + notTake;
        }
        prev = curr;
    }
    return prev[t];
}

int findTargetSumWaysTabulation(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = 0;
    for(auto e : nums) sum += e;
    if(sum - target < 0 || (sum - target)  % 2 != 0) return 0;
    int t = (sum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));
    
    if(nums[0] == 0) dp[0][nums[0]] = 2;
    else dp[0][0] = 1;

    if(nums[0] != 0 && nums[0] <= t) dp[0][nums[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= t; j++){
            int take = 0;
            if(j >= nums[i]) take = dp[i - 1][j - nums[i]];
            int notTake = dp[i - 1][j];

            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][t];
}

int findTargetSumWaysHelperMemiozation(vector<int> &nums, vector<vector<int>> &dp, int t, int n){
    if(t < 0) return 0;

    if(n == 0){
        if(nums[0] == 0 && t == 0) return 2;
        if(t == 0 || nums[0] == t)return 1;
        return 0;
    }
    
    if(dp[n][t] != -1) return dp[n][t];

    int pick = findTargetSumWaysHelperMemiozation(nums, dp, t - nums[n], n - 1);
    int notPick = findTargetSumWaysHelperMemiozation(nums, dp, t, n - 1);

    return dp[n][t] = pick + notPick;
}
int findTargetSumWaysMemiozation(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = 0;
    for(auto e : nums) sum += e;
    if(sum - target < 0 || (sum - target)  % 2 != 0) return 0;
    int t = (sum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(t + 1, -1));
    return findTargetSumWaysHelperMemiozation(nums, dp, t, n - 1);
}


int findTargetSumWaysHelperRecursion(vector<int> &nums, int t, int n){
    if(t < 0) return 0;

    if(n == 0){
        if(nums[0] == 0 && t == 0) return 2;
        if(t == 0 || nums[0] == t)return 1;
        return 0;
    }

    int pick = findTargetSumWaysHelperRecursion(nums, t - nums[n], n - 1);
    int notPick = findTargetSumWaysHelperRecursion(nums, t, n - 1);

    return pick + notPick;
}
int findTargetSumWaysRecursion(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = 0;
    for(auto e : nums) sum += e;
    if(sum - target < 0 || (sum - target)  % 2 != 0) return 0;
    return findTargetSumWaysHelperRecursion(nums, (sum - target) / 2, n - 1);
}


int main(){
    int n, d;
    cin >> n >> d;

    vector<int>arr(n, 0);
    for(auto &e : arr) cin>>e;


    cout<<"Recursion --> "<<findTargetSumWaysRecursion(arr, d)<<"\n";

    cout<<"Memoization --> "<<findTargetSumWaysMemiozation(arr, d)<<"\n";

    cout<<"Tabulation --> "<<findTargetSumWaysTabulation(arr, d)<<"\n";

    cout<<"Space Optimization --> "<<findTargetSumWaysSpaceOptimization(arr, d)<<"\n";
}