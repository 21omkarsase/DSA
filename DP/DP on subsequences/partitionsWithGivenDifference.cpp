#include <bits/stdc++.h> 
using namespace std;

int mod = 1e9 + 7;

int countPartitionsSpaceOptimization(int n, int d, vector<int> &nums) {
    int sum = 0;
    for(auto e : nums) sum += e;
    if(sum - d < 0 || (sum - d) % 2 != 0) return 0;

    int target = (sum - d) / 2;
    vector<int> prev(target + 1, 0), curr(target + 1, 0);
    
    if(nums[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    if(n != 0 && nums[0] <= target) prev[nums[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){
            int take = 0;
            if(nums[i] <= j) take = prev[j - nums[i]];
            int notTake= prev[j];

            curr[j] = (take + notTake) % mod;
        }
        prev = curr;
    }

    return prev[target];
}

int countPartitionsTabulation(int n, int d, vector<int> &nums) {
    int sum = 0;
    for(auto e : nums) sum += e;
    if(sum - d < 0 || (sum - d) % 2 != 0) return 0;

    int target = (sum - d) / 2;
    vector<vector<int>>dp (n, vector<int>(target + 1, 0));
    
    if(nums[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(n != 0 && nums[0] <= target) dp[0][nums[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){
            int take = 0;
            if(nums[i] <= j) take = dp[i - 1][j - nums[i]];
            int notTake= dp[i - 1][j];

            dp[i][j] = (take + notTake) % mod;
        }
    }

    return dp[n - 1][target];
}

int countPartitionsHelperMemoization(vector<int>& nums, vector<vector<int>> &dp, int n, int t){
    if(t < 0) return 0;

    if(n == 0){
        if(t == 0 && nums[0] == 0) return 2;
        if(t == 0 || t == nums[0]) return 1;
        return 0;
    }
    
    if(dp[n][t] != -1) return dp[n][t];
    int take = countPartitionsHelperMemoization(nums, dp, n - 1, t - nums[n]);
    int notTake = countPartitionsHelperMemoization(nums, dp, n - 1, t);

    return dp[n][t] = (take + notTake) % mod;
}

int countPartitionsMemoization(int n, int d, vector<int> &nums) {
    int sum = 0;
    for(auto e : nums) sum += e;
    if(sum - d < 0 || (sum - d) % 2 != 0) return 0;

    int target = (sum - d) / 2;
    vector<vector<int>>dp (n, vector<int>(target + 1, -1));

    return countPartitionsHelperMemoization(nums, dp, n - 1, target);

}


int countPartitionsHelperRecursion(vector<int>& nums, int n, int t){
    if(t < 0) return 0;

    if(n == 0){
        if(t == 0 && nums[0] == 0) return 2;
        if(t == 0 || t == nums[0]) return 1;
        return 0;
    }

    int take = countPartitionsHelperRecursion(nums, n - 1, t - nums[n]);
    int notTake = countPartitionsHelperRecursion(nums, n - 1, t);

    return take + notTake;
}
int countPartitionsRecursion(int n, int d, vector<int> &nums) {
    // sum = s1 + s2
    // diff = sum - s2 - s2
    // s2 = (sum - diff) / 2

    // sum - diff --> even
    // sum - diff >= 0

    int sum = 0;
    for(auto e : nums) sum += e;
    if(sum - d < 0 || (sum - d) % 2 != 0) return 0; 
    return countPartitionsHelperRecursion(nums, n - 1, (sum - d) / 2);

}


int main(){
    int n, d;
    cin >> n >> d;

    vector<int>arr(n, 0);
    for(auto &e : arr) cin>>e;


    cout<<"Recursion --> "<<countPartitionsRecursion(n, d, arr)<<"\n";

    cout<<"Memoization --> "<<countPartitionsMemoization(n, d, arr)<<"\n";

    cout<<"Tabulation --> "<<countPartitionsTabulation(n , d, arr)<<"\n";

    cout<<"Space Optimization --> "<<countPartitionsSpaceOptimization(n, d, arr)<<"\n";
}