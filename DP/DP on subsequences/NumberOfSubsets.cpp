#include<bits/stdc++.h>
using namespace std;

int findWaysSpaceOptimization(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);

    prev[0] = curr[0] = 1;
    if(tar >= nums[0]) prev[nums[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= tar; j++){
            int notTake = prev[j];
            int take = 0;
            if(nums[i] <= j) take = prev[j - nums[i]];
            curr[j] = notTake + take;
        }
        prev = curr;
    }

    return prev[tar];
}


int findWaysTabulation(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<vector<int>>dp (n, vector<int>(tar + 1, 0));
    
    if(nums[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(n != 0 && nums[0] <= tar) dp[0][nums[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= tar; j++){
            int notTake = dp[i - 1][j];
            int take = 0;
            if(nums[i] <= j) take = dp[i - 1][j - nums[i]];

            dp[i][j] = notTake + take;
        }
    }

    return dp[n - 1][tar];
}

int helperFunMemoization(vector<int> &nums, vector<vector<int>> &dp, int n, int t){
    if(t < 0) return 0;

    if(n == 0){   
        if(t == 0 && nums[0] == 0) return 2;
        if(nums[0] == t || t == 0) return 1;
        return 0;
    }
    
    if(dp[n][t] != -1) return dp[n][t];

    int pick = helperFunMemoization(nums, dp, n - 1, t - nums[n]);
    int notPick = helperFunMemoization(nums, dp, n - 1, t);

    return dp[n][t] = pick + notPick;

}
int findWaysMemoization(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<vector<int>>dp (n, vector<int>(tar + 1, -1));
    return helperFunMemoization(nums, dp, n - 1, tar);
}

int helperFunRecursion(vector<int> &nums, int n, int t){
    if(t == 0) return 1;

    if(n == 0){
        if(t == 0 && nums[0] == 0) return 2;
        if(nums[0] == t || t == 0) return 1;
        return 0;
    }

    int pick = helperFunRecursion(nums, n - 1, t - nums[n]);
    int notPick = helperFunRecursion(nums, n - 1, t);

    return pick + notPick;
}

int findWaysRecursion(vector<int> &nums, int tar)
{
    int n = nums.size();
    return helperFunRecursion(nums, n - 1, tar);
}


int main(){
	int n, k;
	cin>>n>>k;

	vector<int>arr(n, 0);
	for(auto &e : arr)cin>>e;


    cout<<"Memoization --> "<<findWaysMemoization(arr, k)<<"\n";

	cout<<"Tabulation --> "<<findWaysTabulation(arr, k)<<"\n";

    cout<<"Space Optimization --> "<<findWaysSpaceOptimization(arr, k)<<"\n";

}