#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent1(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(nums[j] < nums[i]){
                    ans[i]++;
                }
            }
        }

        return ans;
    }


    vector<int> smallerNumbersThanCurrent2(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(101, 0), ans(n, 0);
        
        for(auto e : nums)
            cnt[e]++;

        for(int i = 1; i < 101; i++){
            cnt[i] += cnt[i - 1];
        }

        for(int i = 0; i < n; i++){
            if(nums[i] != 0)
                ans[i] = cnt[nums[i] - 1];
        }

        return ans;
    }
};


int main(){
    int n;cin>>n;
    vector<int> nums(n, 0);
    for(auto &e : nums)
        cin >> e;

    Solution *s = new Solution();

   vector<int> ans = s->smallerNumbersThanCurrent1(nums);
   for(auto e : ans)
       cout<<e<<" --> ";
   cout<<"\n";


   ans = s->smallerNumbersThanCurrent2(nums);
   for(auto e : ans)
       cout<<e<<" --> ";
   cout<<"\n";
    
    return 0;
}