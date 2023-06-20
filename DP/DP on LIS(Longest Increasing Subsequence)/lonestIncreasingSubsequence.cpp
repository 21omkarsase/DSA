#include<bits/stdc++.h>
using namespace std;

int printLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), temp(n, -1);
    
    if(n == 1) return 1;
    
    int ans = 1, lastIdx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    temp[i] = j;
                }                    
            }
        }
        if(ans < dp[i]){ 
            ans = dp[i];
            lastIdx = i;
        }
    }
    cout<<ans<<"\n";
    vector<int>lis;
    while(lastIdx >= 0){
        lis.push_back(nums[lastIdx]);
        if(temp[lastIdx] == -1){
            break;
        }
        lastIdx = temp[lastIdx];
    }

    reverse(lis.begin(), lis.end());
    for(auto e : lis) 
        cout<<e<<" --> ";
    cout<<"\n";

    return ans;
}

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> dp(n, INT_MAX);
//         dp[0] = nums[0];
//         for(int idx = 1; idx < n; idx++){
//             auto lb = lower_bound(dp.begin(), dp.begin() + idx, nums[idx]) - dp.begin();
//             dp[lb] = nums[idx];
//         }

//         return find(dp.begin(), dp.end(), INT_MAX) - dp.begin();
//     }
// };

int lengthOfLISBinarySearch(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp;
    dp.push_back(nums[0]);
    for(int i = 1; i < n; i++){
        if(nums[i] > dp.back()){
            dp.push_back(nums[i]);
        }else{
            int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[idx] = nums[i];
        }
    }
    return dp.size();
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    
    if(n == 1) return 1;
    
    int ans = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

int lengthOfLISpaceOptimization(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return 1;
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    
    prev[n] = 1;
    for(int i = 0; i < n; i++){
        if(nums[0] < nums[i]) prev[i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= n; j++){
            int pick = 0, notPick = 0;

            if(j == nums.size() || nums[i] < nums[j]){
                pick = prev[i] + 1;
            }
            notPick = prev[j];

            curr[j] = max(pick, notPick);
        }
        prev = curr;
    }
    return prev[n];
}

int lengthOfLISTabulation(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return 1;
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    
    dp[0][n] = 1;
    for(int i = 0; i < n; i++){
        if(nums[0] < nums[i]) dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= n; j++){
            int pick = 0, notPick = 0;

            if(j == nums.size() || nums[i] < nums[j]){
                pick = dp[i - 1][i] + 1;
            }
            notPick = dp[i - 1][j];

            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n - 1][n];
}

int lisHelperMemoization(vector<int>& nums, vector<vector<int>> &dp, int n, int m){
    if(n == 0){
        if(m == nums.size() || nums[0] < nums[m]) return 1;
        return 0;
    }

    if(dp[n][m] != -1) return dp[n][m];

    int pick = 0, notPick = 0;
    if(m == nums.size() || nums[n] < nums[m]){
        pick = lisHelperMemoization(nums, dp, n - 1, n) + 1;
    }

    notPick = lisHelperMemoization(nums, dp, n - 1, m);

    return dp[n][m] = max(pick, notPick);

}
int lengthOfLISMemoization(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return 1;
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return lisHelperMemoization(nums, dp, n - 1, n);
}

int main(){
	int n;cin>>n;
	vector<int>nums(n, 0);
	for(auto &e : nums) cin>>e;

	cout<<lengthOfLISMemoization(nums)<<"\n";

    cout<<lengthOfLISTabulation(nums)<<"\n";

    cout<<lengthOfLISpaceOptimization(nums)<<"\n";

    cout<<lengthOfLIS(nums)<<"\n";

    cout<<lengthOfLISBinarySearch(nums)<<"\n";

    cout<<printLIS(nums)<<"\n";
	
	return 0;
}