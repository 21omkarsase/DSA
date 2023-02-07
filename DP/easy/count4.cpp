//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    //t.c --> o(n)+nlog(n) not sure
    //s.c --> constant
    // bool is4Present(int num){
    //     while(num){
    //         if(num%10==4)return true;
    //         num/=10;
    //     }
    //     return false;
    // }
    // int countNumberswith4(int n) {
    //     int ans=0;
    //     for(int i=1;i<=n;i++){
    //         if(is4Present(i))ans++;
    //     }
    //     return ans;
    // }

    //t.c o(n) s.c o(n)
    int countNumberswith4(int n){
        if(n<4)return 0;
        
        int cnt=0;
        vector<bool>dp(n+1,0);
        
        for(int i=4;i<=n;i++){
            if(i%10==4 || dp[i/10])cnt++,dp[i]=1;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countNumberswith4(N) << endl;
    }
    return 0;
}
// } Driver Code Ends