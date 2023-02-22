#include<bits/stdc++.h>
using namespace std;

bool helper(string &p, string &t, vector<vector<int>> &dp, int n, int m){
   if(n == 0 && m == 0) return true;

   if(n == 0) return false;

   if(m == 0){
      for(int x = 0; x <= n - 1; x++){
         if(p[x] != '*') return false;
      }
      return true;
   } 

   if(dp[n][m] != -1) return dp[n][m];

   if(p[n - 1] == t[m - 1] || p[n - 1] == '?') return dp[n][m] = helper(p, t, dp, n - 1, m - 1);
   
   if(p[n - 1] == '*'){
      return dp[n][m] = helper(p, t, dp, n, m - 1) || helper(p, t, dp, n - 1, m);
   }

   return dp[n][m] = false;
}

bool wildcardMatching(string p, string t)
{
   int n = p.size(), m = t.size();
   vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
   
   return helper(p, t, dp, n, m);

}


int main(){
    string s1, s2;
    cin>> s1 >> s2;

    cout<<wildcardMatching(s1, s2)<<"\n";

    return 0;
}