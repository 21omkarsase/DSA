#include<bits/stdc++.h>
using namespace std;


int deleteAndEarnSpaceOptimization(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());
    vector<int>dp(n + 1, 0);

    for(int i = n - 1; i >= 0; i--){
        int currValue = nums[i];
        int currSum  = nums[i];
        int idx = i + 1;

        while(i + 1 < n && nums[idx] == currValue){
            currSum += nums[i];
            idx++;
        }

        while(i + 1 < n && nums[idx] == currValue + 1){
            idx++;
        }

        dp[i] =  max(currSum + dp[idx], dp[i + 1]);
    }

    return dp[0];
}

int deleteAndEarnTabulation(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());
    vector<int>dp(n + 1, 0);

    for(int i = n - 1; i >= 0; i--){
        int currValue = nums[i];
        int currSum  = nums[i];
        int idx = i + 1;

        while(i + 1 < n && nums[idx] == currValue){
            currSum += nums[i];
            idx++;
        }

        while(i + 1 < n && nums[idx] == currValue + 1){
            idx++;
        }

        dp[i] =  max(currSum + dp[idx], dp[i + 1]);
    }

    return dp[0];
}


int daeHelperMemoization(vector<int> &nums, vector<int>& dp, int i){
    if(i >= nums.size()) 
        return 0;

    if(dp[i] != -1)
        return dp[i];
    
    int currValue = nums[i];
    int currSum  = nums[i];
    int idx = i + 1;

    while(i + 1 < nums.size() && nums[idx] == currValue){
        currSum += nums[i];
        idx++;
    }

    while(i + 1 < nums.size() && nums[idx] == currValue + 1){
        idx++;
    }

    return dp[i] =  max(currSum + daeHelperMemoization(nums, dp, idx), daeHelperMemoization(nums, dp, i + 1));
}
int deleteAndEarnMemoization(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int>dp(nums.size(), -1);

    return daeHelperMemoization(nums, dp, 0);
}


int main(){
    int n;cin>>n;
    vector<int>nums(n, 0);
    for(auto &e : nums)
        cin >> e;
    cout<<deleteAndEarnMemoization(nums)<<"\n";
    cout<<deleteAndEarnTabulation(nums)<<"\n";
    return 0;
}