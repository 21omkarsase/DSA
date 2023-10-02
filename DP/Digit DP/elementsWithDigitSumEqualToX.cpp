#include<bits/stdc++.h>
using namespace std;

int calculateTotalPossibleElementsCount(string str, int n, int sum, bool flag, vector<vector<vector<int>>> &dp) {
	if (sum < 0) {
		return 0;
	}
	
	if (n == 1) {
		if (sum >= 0 && sum <= 9) {
			return 1;
		}

		return 0;
	}

	if (dp[n][sum][flag] != -1) {
		return dp[n][sum][flag];
	}

	int up = flag ? str[str.size() - n] - '0' : 9;

	int ans = 0;

	for (int digit = 0; digit <= up; digit++) {
		if (flag && digit == up) {
			ans += calculateTotalPossibleElementsCount(str, n - 1, sum - digit, 1, dp);
		}
		else {
			ans += calculateTotalPossibleElementsCount(str, n - 1, sum - digit, 0, dp);			
		}
	}

	return dp[n][sum][flag] = ans;
}

int main(){
	string str;
	cin >> str;

	int sum;
	cin >> sum;

	vector<vector<vector<int>>> dp(str.size() + 1, vector<vector<int>>(sum + 1, vector<int>(2, -1)));

	cout<<calculateTotalPossibleElementsCount(str, str.size(), sum, 1, dp);
	
	return 0;
}