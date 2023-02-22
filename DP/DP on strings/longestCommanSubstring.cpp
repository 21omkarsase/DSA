#include <bits/stdc++.h> 
using namespace std;

int lcsSpaceOptimization(string &s1, string &s2){
	int n = s1.size(), m = s2.size();
	vector<int> prev(m + 1, 0), curr(m + 1, 0);

	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s1[i - 1] == s2[j - 1]){
				curr[j] = 1 + prev[j - 1];
				ans = max(ans, curr[j]);
			}
		}
		prev = curr;
		for(int p = 0; p < curr.size(); p++) curr[p] = 0;
	}

	return ans;
}

int lcsTabulation(string &s1, string &s2){
	int n = s1.size(), m = s2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s1[i - 1] == s2[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
				ans = max(ans, dp[i][j]);
			}
		}
	}

	return ans;
}

int main(){
    string s1, s2;
    cin>> s1 >> s2;


    cout<<"Tabulation --> "<<lcsTabulation(s1, s2)<<"\n";

    cout<<"Space Optimization --> "<<lcsSpaceOptimization(s1, s2)<<"\n";

    return 0;
}