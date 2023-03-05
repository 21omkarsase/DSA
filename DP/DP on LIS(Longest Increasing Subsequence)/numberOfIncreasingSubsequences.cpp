#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), cnt(n, 1);
    
    if(n == 1) return 1;
    
    int ans = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }else if(dp[j] + 1 == dp[i]) 
                    cnt[i] += cnt[j];
            }
        }
        if(dp[i] > ans)
            ans = dp[i];
    }

    int nos = 0;
    for(int i = 0; i < n; i++)
        if(dp[i] == ans) nos += cnt[i];

    return nos;
}

int main(){
	int n;cin>>n;

	vector<int> nums(n, 0);
	for(auto &e : nums) cin >> e;

	cout<<findNumberOfLIS(nums)<<"\n";
	
	return 0;
}