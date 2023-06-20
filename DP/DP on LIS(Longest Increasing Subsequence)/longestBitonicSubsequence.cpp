//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int LongestBitonicSequence(vector<int>nums)
    {
        int n = nums.size();
        vector<int> dp1(n, 1), dp2(n, 1);
        
        for(int idx1 = 1; idx1 < n; idx1++){
            for(int idx2 = 0; idx2 < idx1; idx2++){
                if(nums[idx1] > nums[idx2] && dp1[idx1] < dp1[idx2] + 1){
                    dp1[idx1] = dp1[idx2] + 1;
                }
            }
        }
        
        for(int idx1 = n - 1; idx1 >= 0; idx1--){
            for(int idx2 = n - 1; idx2 > idx1; idx2--){
                if(nums[idx1] > nums[idx2] && dp2[idx1] < dp2[idx2] + 1){
                    dp2[idx1] = dp2[idx2] + 1;
                }
            }
        }
        
        int lbsSize = 0;
        for(int idx = 0; idx < n; idx++){
            lbsSize = max(lbsSize, (dp1[idx] + dp2[idx] - 1));
        }
        
        return lbsSize;
    }
};

//{ Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.LongestBitonicSequence(nums);
        cout << ans <<"\n";
    }
    return 0;
}
// } Driver Code Ends