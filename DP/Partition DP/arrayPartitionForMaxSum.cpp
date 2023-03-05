#include<bits/stdc++.h>
using namespace std;

int maxSumAfterPartitioningTabulation(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n + 1, 0);

    for(int i = n - 1; i >= 0; i--){
        int ans = INT_MIN;
        int len = 0, mx = INT_MIN;
        for(int j = i; j < min(i + k, n); j++){
            len++;
            mx = max(mx, nums[j]);
            int sum = len * mx + dp[j + 1];
            ans = max(ans, sum);
        }
        dp[i] = ans;  
    }

    return dp[0];
}

int mxpHelperMemoizaion(vector<int> &nums, vector<int> &dp, int i , int n, int k){
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int ans = INT_MIN;
    int len = 0, mx = INT_MIN;
    for(int j = i; j < min(i + k, n); j++){
        len++;
        mx = max(mx, nums[j]);
        int sum = len * mx + mxpHelperMemoizaion(nums, dp, j + 1, n, k);
        ans = max(ans, sum);
    }

    return dp[i] = ans;
}
int maxSumAfterPartitioningMemoizaion(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return mxpHelperMemoizaion(arr, dp, 0, n, k);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for(auto &e : nums) cin >> e;

    cout<<maxSumAfterPartitioningMemoizaion(nums, k)<<"\n";

    cout<<maxSumAfterPartitioningTabulation(nums, k)<<"\n";

    return 0;
}