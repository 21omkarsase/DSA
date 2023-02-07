#include<bits/stdc++.h>
using namespace std;

int ninjaTrainingTabulation(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(4, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][1], max(points[0][0], points[0][2]));

    for(int i=1;i<n;i++){
        for(int j=0;j<4;j++){
            dp[i][j] = 0;
            int mx = INT_MIN;
            for(int k=0;k<3;k++){
                if(j != k){
                    dp[i][j] = max(dp[i][j], points[i][k] + dp[i - 1][k]);
                }
            }
        }
    }
    return dp[n-1][3];
}

int ninjaHelperMemoization(vector<vector<int>> &points, vector<vector<int>> &dp, int n, int last){
    if(n == 0){
        int mx = INT_MIN;
        for(int i=0;i<3;i++){
            if(i != last)
               mx = max(mx, points[n][i]);
        }
        return dp[0][last] = mx;
    }
    
    int mx = INT_MIN;
    for(int i=0;i<3;i++){
        if(i != last){
            int val = dp[n-1][i] == -1 ? points[n][i] + ninjaHelperMemoization(points, dp, n - 1, i) : points[n][i] + dp[n-1][i];
            mx = max(mx, val);
        }
    }

    return dp[n][last] = mx;
}

int ninjaTrainingMemoization(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return ninjaHelperMemoization(points, dp, n-1, 3);
}

int main(){
    int n;cin>>n;
    vector<vector<int>> points;
    for(int i=0;i<n;i++){
        vector<int>v;
        for(int i=0;i<3;i++){
            int x;cin>>x;
            v.push_back(x);
        }
        points.push_back(v);
    }
    

    cout<<"recursion(memoization) --> "<<ninjaTrainingMemoization(n,points)<<"\n";

    cout<<"tabulation --> "<<ninjaTrainingTabulation(n,points)<<"\n";

    return 0;
}