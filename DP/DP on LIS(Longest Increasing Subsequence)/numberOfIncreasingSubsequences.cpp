class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1), lisCount(n, 1);

        for(int idx1 = 1; idx1 < n; idx1++){
            for(int idx2 = 0; idx2 < idx1; idx2++){
                if(nums[idx1] > nums[idx2]){
                    if(dp[idx2] + 1 > dp[idx1])
                        dp[idx1] = dp[idx2] + 1, lisCount[idx1] = lisCount[idx2];
                    else if(dp[idx2] + 1 == dp[idx1])
                        dp[idx1] = dp[idx2] + 1, lisCount[idx1] += lisCount[idx2]; 
                }
            }
        }
        
        int maxLisCount = 0, maxLisSize = *max_element(dp.begin(), dp.end());

        for(int idx = 0; idx < n; idx++){
            if(dp[idx] == maxLisSize){
                maxLisCount += lisCount[idx];
            }
        }
        

        return maxLisCount;
    }
};

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