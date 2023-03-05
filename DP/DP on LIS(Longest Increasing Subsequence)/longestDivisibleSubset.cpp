#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<int> dp(n, 1), lis(n + 1, -1);
    
    int lastIdx = 0, ans = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] % nums[j] == 0){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    lis[i] = j;
                }
            }
        }
        if(dp[i] > ans){
            ans = dp[i];
            lastIdx = i;
        }
    }

    vector<int>temp;
    while(lastIdx >= 0){
        temp.push_back(nums[lastIdx]);
        lastIdx = lis[lastIdx]; 
    }

    reverse(temp.begin(), temp.end());

    return temp;
}

vector<int> temp, dp;
int ldsHelperMemoization(vector<int> &nums, vector<int> ans, int n, int m){
    if(n == nums.size()){
        if(ans.size() > temp.size()){
            temp = ans;
        }
        return 0;
    }

    int take = 0 , notTake = 0;
    
    if(m == -1 || nums[n] % ans[m] == 0 && (int) ans.size() > dp[n]){
        dp[n]=ans.size();
        ans.push_back(nums[n]);
        take = ldsHelperMemoization(nums, ans, n + 1, m + 1) + 1;
        ans.pop_back();
    }

    notTake = ldsHelperMemoization(nums, ans, n + 1, m);

    return max(take, notTake);
}
vector<int> largestDivisibleSubsetMemoization(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i <= n; i++) dp.push_back(-1);
    vector<int> ans;
    cout<<ldsHelperMemoization(nums, ans, 0, -1)<<" : "<<temp.size()<<"\n";
    return temp;
}

int ldsHelperRecursion(vector<int> &nums, vector<int> ans, int n){
    if(n == nums.size()){
        if(ans.size() > temp.size()){
            temp = ans;
        }
        return 0;
    }

    int take = 0 , notTake = 0;
    
    if(ans.size() == 0 || nums[n] % ans[ans.size() - 1] == 0){
        ans.push_back(nums[n]);
        take = ldsHelperRecursion(nums, ans, n + 1) + 1;
        ans.pop_back();
    }

    notTake = ldsHelperRecursion(nums, ans, n + 1);

    return max(take, notTake);
}

vector<int> largestDivisibleSubsetRecursion(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> ans;
    cout<<ldsHelperRecursion(nums, ans, 0)<<"\n";
    return temp;
}


int main(){
    int n;cin>>n;
    vector<int>nums(n, 0);
    for(auto &e : nums) cin>>e;
    
    vector<int> ans = largestDivisibleSubsetMemoization(nums);

    for(auto e : ans) 
        cout<<e<<" : ";
    cout<<"\n";

    ans = largestDivisibleSubsetRecursion(nums);

    for(auto e : ans) 
        cout<<e<<" : ";
    cout<<"\n";
    
    ans = largestDivisibleSubset(nums);
    
    for(auto e : ans) 
        cout<<e<<" : ";
    cout<<"\n";

    return 0;
}