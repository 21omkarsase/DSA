#include <bits/stdc++.h> 
using namespace std;

#define mod 1000000007

long long int evalExpHelperMemoization(string &exp, vector<vector<vector<long long int>>> &dp, int i, int j, bool value){
    if(i > j) return 0;

    if(i == j){
        if(value) return exp[i] == 'T';
        return exp[i] == 'F';
    }
    
    if(dp[i][j][value] != -1) return dp[i][j][value];
    long long int ways = 0;
    for(int k = i + 1; k <= j - 1; k+=2){
        long long int lt = evalExpHelperMemoization(exp, dp, i, k - 1, true) % mod;
        long long int lf = evalExpHelperMemoization(exp, dp, i, k - 1, false) % mod;
        long long int rt = evalExpHelperMemoization(exp, dp, k + 1, j, true) % mod;
        long long int rf = evalExpHelperMemoization(exp, dp, k + 1, j, false) % mod;
        

        if(exp[k] == '&'){
            if(value) ways = (ways + (lt * rt) % mod) % mod;
            else ways = (ways + ((lt * rf) % mod + (rt * lf) % mod + (rf * lf) % mod) % mod);
        }else if(exp[k] == '|'){
            if(value) ways = (ways + ((lt * rt) % mod + (lt * rf) % mod + (rt * lf) % mod) % mod);
            else ways = (ways + (lf * rf) % mod) % mod;
        }else{
            if(value) ways = (ways + ((lt * rf) % mod + (rt * lf) % mod) % mod);
            else ways = (ways + ((lt * rt) % mod + (lf * rf) % mod) % mod);
        }

    }

    return dp[i][j][value] = ways;
}

int evaluateExpMemoization(string & exp) {
    int n = exp.size();
    if(n == 1) return exp[0] == 'T';
    
    vector<vector<vector<long long int>>> dp(n, vector<vector<long long int>>(n, vector<long long int>(2, -1)));
    return evalExpHelperMemoization(exp, dp, 0, n - 1, true);
}

int main(){
    string s;
    cin >> s;

    cout<<evaluateExpMemoization(s)<<"\n";
    return 0;
}