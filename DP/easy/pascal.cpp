class Solution {
public:
    vector<vector<int>> generate(int n) {
        // vector<vector<int>> generate(int n) {
        //     vector<vector<int>>pascal;
        //     for(int i=0;i<n;i++){
        //         vector<int>v;
        //         for(int j=0;j<i+1;j++){
        //             if(i==j || j==0) v.push_back(1);
        //             else v.push_back(pascal[i-1][j] + pascal[i-1][j-1]);
        //         }
        //         pascal.push_back(v);
        //     }
        //     return pascal;
        // }

        // vector<vector<int>>pascal(n,vector<int>());
        // for(int i=0;i<n;i++){
        //     vector<int>v(i+1,0);
        //     pascal[i]=v;
        // }
        
        // pascal[0][0] = 1;
        // for(int i=1;i<n;i++){
        //     pascal[i][0] = pascal[i][pascal[i].size()-1] = 1;
        // }

        // for(int i=2;i<n;i++){
        //     int size = pascal[i].size();
        //     for(int j=1;j<size-1;j++){
        //         pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        //     }
        // }

        return pascal;
    }
};