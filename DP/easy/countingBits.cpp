class Solution {
public:
    // int findOnesCount(vector<int> &dp,int n){
    //     if(n==0)return 0;

    //     if(dp[n] != 0)return dp[n];

    //     return dp[n] = n & 1 ? findOnesCount(dp , n/2) + 1 : findOnesCount(dp , n/2) ;    
    // }
    //  vector<int> countBits(int n) {
    //     vector<int> dp(n + 1,0);
    //     for(int i=0;i<=n;i++){
    //         dp[i] = findOnesCount(dp,i);
    //     }
    //     return dp;
    // }
    
    // int countOnes(int num){
    //     int cnt=0;
    //     while(num){
    //         if(num&1)cnt++;
    //         num=num>>1;
    //     }
    //     return cnt;
    // }
    // vector<int> countBits(int n) {
    //     vector<int>ans(n+1,0);
    //     for(int i=0;i<=n;i++){
    //         ans[i]=countOnes(i);
    //     }
    //     return ans;
    // }

    // vector<int> countBits(int n){
    //     vector<int>dp(n+1,0);
    //     dp[0]=0;

    // //for positive num --> number of ones in that number == number of ones in (num/2) 
    // //for positive num --> number of ones in that number == number of ones in (num/2)+1  
    //     for(int i=1;i<=n;i++){
    //         dp[i]=dp[i/2] + i%2;
    //     }
    //     return dp;
    // }

    // vector<int>countBits(int n){
    //     vector<int>dp(n+1, 0);
    //     dp[0]=0;
    //     for(int i=1;i<=n;i++){
    //         dp[i]=dp[i&(i-1)]+1;
    //     }
    //     return dp;
    // }
};