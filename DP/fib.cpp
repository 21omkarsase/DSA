#include<bits/stdc++.h>
using namespace std;

int fibOptimal(int n, int prev, int prevPrev){
    for(int i=2;i<=n;i++){
        int temp=prev;
        prev=prev+prevPrev;
        prevPrev=temp;
    }
    return prev;
}

int fibTabulation(vector<int> &dp,int n){
    dp[0]=0, dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n-1];
}

int fibRecursion(vector<int> &dp,int n){
    if(n<=1)return n;

    if(dp[n]!=-1)return dp[n];
    return dp[n]=fibRecursion(dp,n-1) + fibRecursion(dp,n-2);
}

int main(){
    int n;cin>>n;
    vector<int>dp(n+1,-1);
    dp[0]=0,dp[1]=1;

    cout<<"using recursion : "<<fibRecursion(dp,n)<<"\n"; //t.c o(n) using memoization 
                                    //s.c o(n)+o(n) recursion stack + array 
    dp.erase(dp.begin(),dp.end());

    cout<<"using tabulation : "<<fibTabulation(dp,n+1)<<"\n";  //s.c o(n)
    dp.erase(dp.begin(),dp.end());
    

    cout<<"reducing space-complexity : "<<fibOptimal(n,1,0)<<"\n"; //s.c constant
    return 0;
}