#include <bits/stdc++.h>
using namespace std;

int uniquePathsSpaceOptimization(int m, int n){
    
    vector<int> prev(n, 0);

	for(int i = 0; i < m; i++){
		vector<int> temp(n, 0);
		for(int j=0; j < n; j++){
			if(i == 0 && j == 0) temp[0]= 1;
			else temp[j] = (i - 1 >= 0 ? prev[j] : 0) + (j - 1 >= 0 ? temp[j - 1] : 0);
		}
		prev = temp;
	}

	return prev[n - 1];
}

//  **************** Time Complexity = m * n****************************
//  **************** Space Complexity = m * n****************************
int uniquePathsTabulation(int m, int n){
	vector<vector<int>>dp (m, vector<int>(n, -1));
    
    // dp[0][0] = 1;
	// for(int i = 1; i < n; i++) dp[0][i] = 1;
	// for(int i = 1; i < m; i++) dp[i][0] = 1;

	for(int i = 0; i < m; i++){
		for(int j=0; j < n; j++){
			if(i == 0 && j == 0) dp[0][0] = 1;
			else dp[i][j] = (i - 1 >= 0 ? dp[i - 1][j] : 0) + (j - 1 >= 0 ? dp[i][j - 1] : 0);
		}
	}

	return dp[m - 1][n - 1];
}


//  **************** Time Complexity = 2^(m * n)****************************
//  **************** Space Complexity = Path length ((n - 1)  + (m - 1))****************************
int uniquePathsRecursionHelper(int m, int n){
	if(m == 0 && n == 0)return 1;
	
	if(n < 0 || m < 0) return 0;
	int right = uniquePathsRecursionHelper(m - 1, n);
	int down =  uniquePathsRecursionHelper(m, n - 1);
    
	return right + down;
}

int uniquePathsRecursion(int m, int n) {
    return uniquePathsRecursionHelper(m - 1, n - 1);
}

//  **************** Time Complexity = m * n****************************
//  **************** Space Complexity =  ((n - 1)  + (m - 1)) --> Path length + (m * n)****************************
int uniquePathsMemoizationHelper(vector<vector<int>> &dp, int m, int n){
	if(m == 0 && n == 0)return 1;

	if(m < 0 || n < 0) return 0;

    if(dp[m][n] != -1) return dp[m][n];

	int left = uniquePathsMemoizationHelper(dp, m - 1, n);
	int up = uniquePathsMemoizationHelper(dp, m, n - 1);

	return dp[m][n] = left + up;
}
int uniquePathsMemoization(int m, int n) {
	vector<vector<int>>dp (m, vector<int>(n, -1));
	return uniquePathsMemoizationHelper(dp, m-1, n-1);
}

int main(){
	int m, n;
	cin>>m>>n;

	cout<<"uniquePaths : Recursion count --> "<<uniquePathsRecursion(m, n)<<"\n";
	
	cout<<"uniquePaths : Memoization count --> "<<uniquePathsMemoization(m, n)<<"\n";

	cout<<"uniquePaths : Tabulation count --> "<<uniquePathsTabulation(m, n)<<"\n";
	
	cout<<"uniquePaths : Space Optimization count --> "<<uniquePathsSpaceOptimization(m, n)<<"\n";
}