#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int mx = nums[0], mn = nums[0], ans = nums[0];
        
        for(int i = 1; i < n; i++){
            if(nums[i] < 0)
                swap(mx, mn);
            
            mx = max(nums[i], nums[i] * mx);
            mn = min(nums[i], nums[i] * mn);
            ans = max(ans, mx);
        }

        return ans;
    }

    int naiveApproach(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int mup = nums[i];
            ans = max(ans, mup);
            for(int j = i + 1; j < n; j++){
                mup = mup * nums[j];
                ans = max(ans, mup);
            }
            ans = max(ans, mup);
        }

        return ans;
    }
};


int main(){
    int n;
    cin >> n;

    vector<int>nums(n, 0);
    for(auto &e : nums)
        cin >> e;

    Solution* s = new Solution();

    cout<<s->naiveApproach(nums)<<"\n";

    cout<<s->maxProduct(nums)<<"\n";

    return 0;
}