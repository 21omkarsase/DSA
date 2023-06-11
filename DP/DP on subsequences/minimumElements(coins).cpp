#include <bits/stdc++.h> 
using namespace std;

int minimumElementsSpaceOptimization(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<int> dp1(x+1, 0), dp2(x + 1, 0);

    for(int i = 0; i <= x; i++) 
       if(i % nums[0] == 0) dp1[i] = i / nums[0];
       else dp1[i] = 1e9;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= x; j++){
            int notTake = dp1[j];
            int take = INT_MAX;
            if(nums[i] <= j) take = dp2[j - nums[i]] + 1;

            dp2[j] = min(take, notTake);
        }
        dp1 = dp2;
    }

    int ans =  dp1[x];
    if(ans >= 1e9) return -1;
    else return dp1[x];
}

int minimumElementsTabulation(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<vector<int>>dp (n, vector<int>(x+1, 0));

    for(int i = 0; i <= x; i++) 
       if(i % nums[0] == 0) dp[0][i] = i / nums[0];
       else dp[0][i] = 1e9;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= x; j++){
            int notTake = dp[i - 1][j];
            int take = INT_MAX;
            if(nums[i] <= j) take = dp[i][j - nums[i]] + 1;

            dp[i][j] = min(take, notTake);
        }
    }

    int ans =  dp[n - 1][x];
    if(ans >= 1e9) return -1;
    else return dp[n - 1][x];
}

int minEleHelperMemoization(vector<int> &nums, vector<vector<int>> &dp, int n, int x){
    if(n == 0){
        if(x % nums[0] == 0) return x/nums[0];
        else return 1e9;
    }
    
    if(dp[n][x] != -1) return dp[n][x];
    int notTake = minEleHelperMemoization(nums, dp, n - 1, x);
    int take = INT_MAX;
    if(nums[n] <= x) take = minEleHelperMemoization(nums, dp, n, x - nums[n]) + 1;

    return dp[n][x] = min(take, notTake);
}

int minimumElementsMemoization(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<vector<int>>dp (n, vector<int>(x+1, -1));
    int ans =  minEleHelperMemoization(nums, dp, n - 1, x);
    if(ans == 1e9) return -1;
    else return ans;
}


int minEleHelperRecursion(vector<int> &nums, int n, int x){
    if(n == 0){
        if(x % nums[0] == 0) return x/nums[0];
        else return 1e9;
    }
    
    int notTake = minEleHelperRecursion(nums, n - 1, x);
    int take = INT_MAX;
    if(nums[n] <= x) take = minEleHelperRecursion(nums, n, x - nums[n]) + 1;

    return min(take, notTake);
}

int minimumElementsRecursion(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<vector<int>>dp (n, vector<int>(x+1, -1));
    int ans =  minEleHelperRecursion(nums, n - 1, x);
    if(ans == 1e9) return -1;
    else return ans;
}


int main(){
    int n, x;
    cin >> n >> x;

    vector<int> nums(n, 0);
    for(auto &e : nums) cin >> e;
    
    cout<<"Recursion --> "<<minimumElementsRecursion(nums, x)<<"\n";

    cout<<"Memoization --> "<<minimumElementsMemoization(nums, x)<<"\n";

    cout<<"Tabulation --> "<<minimumElementsTabulation(nums, x)<<"\n";

    cout<<"Space Optimization --> "<<minimumElementsSpaceOptimization(nums, x)<<"\n";


    return 0;
}