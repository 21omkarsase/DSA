#include<bits/stdc++.h>
using namespace std;

int helper (int i, int diff, vector<int> &nums, unordered_map<int,int> dp[]){  
   if(i <= -1) return 0;
   
   if(dp[i].count(diff))
       return dp[i][diff];
       
   int ans = 0;
   for(int k = i - 1; k >= 0; k--){
       if(nums[i] - nums[k] == diff){
           ans = max(ans, 1 + helper(k, diff, nums, dp));
       }
   }
   return dp[i][diff] = ans;
}

int longestArithSeqLength (vector<int>& nums) {
    int n =  nums.size(), ans = 0;

    if(n <= 2) return n;
    
    unordered_map<int, int> dp[n + 1];

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            ans = max(ans, 2 + helper(i, nums[j] - nums[i], nums, dp));
        }   
    }

    return ans;
}

int longestArithSeqLength2 (vector<int>& nums) {
    int n =  nums.size(), ans = 0;

    if(n <= 2) return n;
    
    unordered_map<int, int> dp[n + 1];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            int cnt = 1;
            int diff = nums[i] - nums[j];
            if(dp[j].count(diff))
                cnt = dp[j][diff];
            
            
            dp[i][diff] = cnt + 1;
            ans = max(ans, dp[i][diff]);
        }   
    }

    return ans;
}


int main(){
    int n;cin>>n;

    vector<int>nums(n,0);

    for(auto &e : nums) cin >> e;

    cout<<longestArithSeqLength(nums)<<"\n";

    cout<<longestArithSeqLength2(nums)<<"\n";
    
    return 0;
}