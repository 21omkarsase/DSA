//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    int nthStair(int n);
    // int nthStair(int n) {
    //     return n/2+1;
    // }
    
    // int nthStair(int n){
    //     if(n<0)return 0;
    //     if(n==0)return 1;
        
    //     return nthStair(n-2)+1;
    // }
    
    // int nthStairMemoization(vector<int> &dp, int n){
    //     if(n<0)return 0;
    //     if(n==0)return 1;
        
    //     if(dp[n]!=-1)return dp[n];
        
    //     return nthStairMemoization(dp,n-2)+1;
    // }
    // int nthStair(int n){
    //     vector<int>dp(n+1,-1);
    //     return nthStairMemoization(dp,n);
    // }
    
    //   int nthStair(int n){
    //       vector<int>dp(n+1,0);
    //       dp[0]=1, dp[1]=1;
           
    //       for(int i=2;i<=n;i++){
    //           dp[i]=dp[i-2]+1;
    //       }
           
    //       return dp[n];
    //   }
    
        // int nthStair(int n){
        //     if(n==1)return 1;
        //     int ans=0,prev=1, prevPrev=1;
        //     for(int i=2;i<=n;i++){
        //         int temp=prev;
        //         ans=prevPrev+1;  
        //         prev=ans;
        //         prevPrev=temp;
        //     }
        //     return ans;
        // }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends