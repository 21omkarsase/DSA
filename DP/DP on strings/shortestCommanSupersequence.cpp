#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequenceTabulation(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string s = "";
    
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s1[i - 1] == s2[j - 1]){
            s += s1[i - 1];
            i--, j--;
        }else if(dp[i][j - 1] > dp[i - 1][j]){
            s += s2[j - 1];
            j--;
        }else{
            s += s1[i - 1];
            i--;
        }
    } 

    while(i > 0){
        s += s1[i - 1];
        i--;
    }
    while(j > 0){
        s += s2[j - 1];
        j--;
    }

    reverse(s.begin(), s.end());

    return s;
}

int main(){
    string s1, s2;
    cin>> s1 >> s2;

    cout<<shortestCommonSupersequenceTabulation(s1, s2)<<"\n";


    return 0;
}