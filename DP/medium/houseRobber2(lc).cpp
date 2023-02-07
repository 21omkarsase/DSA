#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n, minusOne, minusTwo;
        
        n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        minusOne = max(nums[0], nums[1]), minusTwo = nums[0];
        
        for(int i=2;i<n-1;i++){
            int t1 = nums[i] + minusTwo;
            int t2 = minusOne;

            minusTwo = minusOne;
            minusOne =  max(t1, t2);
            
        }

        int finalAns = minusOne;

        minusOne = max(nums[n-1], nums[n-2]), minusTwo = nums[n-1];
        for(int i=n-3;i>=1;i--){
            int t1 = nums[i] + minusTwo;
            int t2 = minusOne;

            minusTwo = minusOne;
            minusOne =  max(t1, t2);
            
        }

        return max(finalAns, minusOne);
    }
};

int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(auto &e : nums)cin>>e;
    Solution s;

    cout<<s.rob(nums)<<"\n";
    return 0;
}