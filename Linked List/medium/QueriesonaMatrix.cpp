//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
       vector<vector<int>>ans(n,vector<int>(n,0));

       // for(int k=0;k<Queries.size();k++){
       //  for(int i=Queries[k][0];i<=Queries[k][2];i++){
       //      for(int j=Queries[k][1];j<=Queries[k][3];j++){
       //          ans[i][j]++;
       //      }
       //  }
       // }


       for(int k=0;k<Queries.size();k++){
        for(int i=Queries[k][0];i<=Queries[k][2];i++){
           ans[i][Queries[k][1]]++;
           if(Queries[k][3]+1<n)
            ans[i][Queries[k][3]+1]--;
        }
       }
       for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            ans[i][j]+=ans[i][j-1];
        }
       }



       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends