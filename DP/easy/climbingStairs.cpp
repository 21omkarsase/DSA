class Solution {
public:
    // int getCount(vector<int> &dp,int n){
	//     if(n==1 || n==0)return 1;
	    
	//     int left = dp[n-1]!=0 ? dp[n-1] : dp[n-1]=getCount(dp,n-1);
	//     int right= dp[n-2]!=0 ? dp[n-2] : dp[n-2]=getCount(dp,n-2);
	    
	//     return left+right;
    // }
    // int climbStairs(int n) {
    //     vector<int>dp(n+1,0);
    //     return getCount(dp,n);
    // }

    // int climbStairs(int n){
    //     vector<int>dp(n+1,0);
    //     dp[0]=1,dp[1]=1;
    //     for(int i=2;i<=n;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }

    int climbStairs(int n){
        int prev=1, prevPrev=1;
        for(int i=2;i<=n;i++){
            int temp=prev;
            prev=prev+prevPrev;
            prevPrev=temp;
        }
        return prev;
    }
};