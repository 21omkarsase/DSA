#include <bits/stdc++.h> 
using namespace std;

int changeSpaceOptimization(int target, vector<int>& nums) {
    int n  = nums.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    for(int i = 0; i <= target; i++){
        if(i % nums[0] == 0) prev[i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){
            int take = 0;
            if(j >= nums[i]) take = curr[j - nums[i]];
            int notTake = prev[j];

            curr[j] = take + notTake;
        }
        prev = curr;
    }
    return prev[target];
}

int changeTabulation(int target, vector<int>& nums) {
    int n  = nums.size();
    vector<vector<int>>dp (n, vector<int>(target + 1, 0));

    for(int i = 0; i <= target; i++){
        if(i % nums[0] == 0) dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){
            int take = 0;
            if(j >= nums[i]) take = dp[i][j - nums[i]];
            int notTake = dp[i - 1][j];

            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][target];
}

int changeHelper(vector<int> &nums, vector<vector<int>> &dp, int target, int n){
    if(n == 0) return (target % nums[0] == 0);
    
    if(dp[n][target] != -1) return dp[n][target];

    int take = 0;
    if(target >= nums[n]) take = changeHelper(nums, dp, target - nums[n], n);
    int notTake = changeHelper(nums, dp, target, n - 1);

    return dp[n][target] = take + notTake;
}
int changeMemoization(int target, vector<int>& nums) {
    int n  = nums.size();
    vector<vector<int>>dp (n, vector<int>(target + 1, -1));
    return changeHelper(nums, dp, target, n - 1);
}


int main(){
    int n, x;
    cin >> n >> x;

    vector<int> nums(n, 0);
    for(auto &e : nums) cin >> e;
    

    cout<<"Memoization --> "<<changeMemoization(x, nums)<<"\n";

    cout<<"Tabulation --> "<<changeTabulation(x, nums)<<"\n";

    cout<<"Space Optimization --> "<<changeSpaceOptimization(x, nums)<<"\n";


    return 0;
}