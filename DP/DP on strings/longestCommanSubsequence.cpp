#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequenceSpaceOptimization(string text1, string text2) {
    int idx1 = text1.size(), idx2 = text2.size();
    if(idx1 == 0 || idx2 == 0) return 0;
    vector<int> prev(idx2 + 1, 0), curr(idx2 + 1, 0); 

    for(int i = 1; i <= idx1; i++){
        for(int j = 1; j <= idx2; j++){
            if(text1[i - 1] == text2[j - 1])
               curr[j] = prev[j - 1] + 1;
            else curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return curr[idx2];
}

int longestCommonSubsequenceTabulation(string text1, string text2) {
    int idx1 = text1.size(), idx2 = text2.size();
    if(idx1 == 0 || idx2 == 0) return 0;
    string str;
    vector<vector<int>>dp (idx1 + 1, vector<int>(idx2 + 1, 0));

    for(int i = 1; i <= idx1; i++){
        for(int j = 1; j <= idx2; j++){
            if(text1[i - 1] == text2[j - 1]){
               dp[i][j] = dp[i - 1][j - 1] + 1;
               str.push_back(text1[i - 1]);
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    int len = dp[idx1][idx2];
    string lcs = "";
    for(int i = 0; i < len ;i++) lcs+="$";
    // Time complexity --> o(n + m)
    int i = idx1, j = idx2, idx = len - 1;
    while(i > 0 && j > 0){
        if(text1[i - 1] == text2[j - 1]){
            lcs[idx] = text1[i - 1];
            i--, j--, idx--;
        }else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }else{
            j--;
        }
    }

    cout<<"LCS : "<<lcs<<"\n";

    return dp[idx1][idx2];
}

int lcsHelperMemoization(string &s1, string &s2, vector<vector<int>> &dp, int n1, int n2){
    if(n1 < 0 || n2 < 0) return 0;
    
    if(dp[n1][n2] != -1) return dp[n1][n2];

    if(s1[n1] == s2[n2]) return dp[n1][n2] = lcsHelperMemoization(s1, s2, dp, n1 - 1, n2 - 1) + 1;

    return dp[n1][n2] = max(lcsHelperMemoization(s1, s2, dp, n1 - 1, n2), lcsHelperMemoization(s1, s2, dp, n1, n2 - 1));
}
int longestCommonSubsequenceMemoization(string text1, string text2) {
    //Time complexity --> o(n * m)  Space complexity --> o(n * m) + o(n + m)
    int idx1 = text1.size(), idx2 = text2.size();
    if(idx1 == 0 || idx2 == 0) return 0;
    vector<vector<int>>dp (idx1, vector<int>(idx2, -1));
    return lcsHelperMemoization(text1, text2, dp, idx1 - 1, idx2 - 1);
}

int main(){
    string s1, s2;
    cin>> s1 >> s2;

    cout<<"Memoization --> "<<longestCommonSubsequenceMemoization(s1, s2)<<"\n";

    cout<<"Tabulation --> "<<longestCommonSubsequenceTabulation(s1, s2)<<"\n";

    cout<<"Space Optimization --> "<<longestCommonSubsequenceSpaceOptimization(s1, s2)<<"\n";

    return 0;
}