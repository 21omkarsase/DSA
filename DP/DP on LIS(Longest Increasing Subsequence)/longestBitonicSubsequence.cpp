#include<bits/stdc++.h>
using namespace std;

int longestBitonicSequence(vector<int>& nums, int n) {
    vector<int>dp1(n, 1), dp2(n, 1);

    int ans1 = 0, lastIdx1 = 0;
    vector<int> lbs1(n, -1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j] && dp1[i] < dp1[j] + 1){
                dp1[i] = dp1[j] + 1;
                lbs1[i] = j;
            }
        }   
        if(dp1[i] > ans1){
            ans1 = dp1[i];
            lastIdx1 = i;
        }
    }
    
    vector<int>temp1;
    while(lastIdx1 >= 0){
        temp1.push_back(nums[lastIdx1]);
        lastIdx1 = lbs1[lastIdx1];
    }
    reverse(temp1.begin(), temp1.end());

    for(auto e : temp1) 
        cout<<e<<" --> ";
    
    int ans2 = 0, lastIdx2 = 0;
    vector<int> lbs2(n, -1);
    
    int finalAns = 0, finalIdx = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j > i; j--){
            if(nums[i] > nums[j] && dp2[i]  < dp2[j] + 1){
                dp2[i] = dp2[j] + 1;
                lbs2[i] = j;
            }
        }
        if(finalAns < dp1[i] + dp2[i] - 1){
            finalAns = dp1[i] + dp2[i] - 1;
            finalIdx = i;
        }

        if(dp2[i] > ans2){
            ans2 = dp2[i];
            lastIdx2 = i;
        }
    }

    vector<int>temp2;
    while(lastIdx2 >= 0){
        temp2.push_back(nums[lastIdx2]);
        lastIdx2 = lbs2[lastIdx2];
    }

    for(int i = finalIdx; i < temp2.size(); i++){
        cout<<temp2[i]<<" - -> ";
    } 
    cout<<"\n";

    return ans2;
} 



int main(){
    int n;
    cin>> n;
    vector<int> nums(n, 0);
    for(auto &e : nums) cin >> e;
    cout<<longestBitonicSequence(nums, n)<<"\n";
    return 0;
}