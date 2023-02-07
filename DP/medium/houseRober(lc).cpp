#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robSpaceOptimization(vector<int>& nums) {
        int n = nums.size();
        int minusOne, minusTwo;

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        minusOne = max(nums[0], nums[1]), minusTwo = nums[0];
        
        int curr = nums[0];
        for(int i=2;i<n;i++){
            int t1 = nums[i] + minusTwo;
            int t2 = minusOne;

            minusTwo = minusOne;
            minusOne =  max(t1, t2);
            
        }

        return minusOne;
    }

    int robTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        dp[0] = nums[0];

        if(n == 1) return dp[0];
        for(int i=1;i<n;i++){
            int picked = 0, notPicked;
            if(i - 2 >= 0) picked = nums[i] + dp[i - 2];
            else picked = nums[i];

            notPicked = dp[i - 1];

            dp[i] = max(picked, notPicked);
        }

        return max(dp[n-1], dp[n-2]);
    }

    int robHelper2(vector<int>& nums, vector<int>& dp, int n){
        if(n == 0) return nums[n];
        if(n < 0) return 0;

        int picked, notPicked;  
        if(n - 2 >= 0 && dp[n - 2] != -1)
            picked = dp[n - 2] + nums[n];
        else picked = nums[n] + robHelper2(nums, dp, n - 2);
        
        notPicked = dp[n - 1] == -1 ? robHelper2(nums, dp, n - 1) : dp[n - 1];
        
        return dp[n] = max(picked, notPicked);
    }

    int robMemoization(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        dp[0] = nums[0];
        return robHelper2(nums, dp, nums.size()-1);
    }

    int robHelper1(vector<int>& nums, int n){
        if(n == 0) return nums[n];
        if(n < 0) return 0;

        int picked = robHelper1(nums, n - 2) + nums[n];

        int notPicked = robHelper1(nums, n - 1);

        return max(picked, notPicked);
    }

    int robRecursion(vector<int>& nums) {
        return robHelper1(nums, nums.size()-1);
    }
};

int main(){
    int n;cin>>n;
    vector<int> nums1(n);
    for(auto &e : nums1)cin>>e;
    Solution s;
    
    cout<<"using recursion --> "<<s.robRecursion(nums1)<<"\n";

    vector<int>nums2(nums1);
    cout<<"using memoization --> "<<s.robMemoization(nums2)<<"\n";

    vector<int>nums3(nums1);
    cout<<"using tabulation --> "<<s.robTabulation(nums3)<<"\n";

    vector<int>nums4(nums1);
    cout<<"space optimization --> "<<s.robSpaceOptimization(nums4)<<"\n";

    return 0;
}