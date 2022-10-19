vector<int> getConcatenation(vector<int>& nums) {
     // vector<int>ans;
     // for(int i=1;i<=2;i++){
     //     for(int j=0;j<nums.size();j++){
     //         ans.push_back(nums[j]);
     //     }
     // }
     // return ans;
     vector<int> a(nums);   //coping vector
     copy(nums.begin(), nums.end(), back_inserter(a)); //pushing new vector at end of a
     return a;
 }