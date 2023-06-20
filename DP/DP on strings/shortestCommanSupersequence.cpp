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

class Solution {
    void getAllSuperSequences(int n, int m, string &s1, string &s2, string str, unordered_set<string> &superSequences){
        if(n < 0){
            superSequences.insert(s2.substr(0, m + 1) + str);
            return;
        }

        if(m < 0){
            superSequences.insert(s1.substr(0, n + 1) + str);
            return;
        }

        if(s1[n] == s2[m]){
            getAllSuperSequences(n - 1, m - 1, s1, s2, s1[n] + str, superSequences);
            return;
        }

        getAllSuperSequences(n, m - 1, s1, s2, s2[m] + str, superSequences);
        getAllSuperSequences(n - 1, m, s1, s2, s1[n] + str, superSequences);
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        unordered_set<string> superSequences;
        int n1 = str1.size(), n2 = str2.size();

        getAllSuperSequences(n1 - 1, n2 - 1, str1, str2, "", superSequences);
        
        string ans = "";
        int len = INT_MAX;
        for(auto str : superSequences){
            if(str.size() < len){
                ans = str;
                len = str.size();
            }
        }

        return ans;
    }
};

int main(){
    string s1, s2;
    cin>> s1 >> s2;

    cout<<shortestCommonSupersequenceTabulation(s1, s2)<<"\n";


    return 0;
}