#include<bits/stdc++.h>
using namespace std;

int numDecodingsTabultion(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);

    if(s[0] != '0')
        dp[1] = 1;
    dp[0] = 1;

    for(int i = 1; i < n; i++){        
        int takeOne = 0, takeTwo = 0;

        if(s[i] != '0') 
            takeOne = dp[i];

        if(i - 1 >= 0 && s[i - 1] != '0'){
            string tc = "";
            tc += s[i - 1];
            tc += s[i];
            if(stoi(tc) <= 26) takeTwo = dp[i - 1];
        }

        dp[i + 1] = (takeOne + takeTwo);  
    }

    return dp[n];
}

int ndHelperMemoization(string s, vector<int> &dp, int n){
    if(n == 0){
        if(s[n] != '0') return 1;
        return 0;
    }

    if(n == -1) return 1;

    if(dp[n] != -1) return dp[n];
    
    int takeOne = 0, takeTwo = 0;

    if(s[n] != '0') 
        takeOne = ndHelperMemoization(s, dp, n - 1);

    if(n - 1 >= 0 && s[n - 1] != '0'){
        string tc = "";
        tc += s[n - 1];
        tc += s[n];
        if(stoi(tc) <= 26) takeTwo = ndHelperMemoization(s, dp, n - 2);
    }

    return dp[n] = (takeOne + takeTwo);
}
int numDecodingsMemoization(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return ndHelperMemoization(s, dp, n - 1);
}

int main(){    
    string s;
    cin >> s;

    cout<<numDecodingsMemoization(s)<<"\n";

    cout<<numDecodingsTabultion(s)<<"\n";
    return 0;
}