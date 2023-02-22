#include<bits/stdc++.h>
 using namespace std;
 

int helper(vector<int> &p, int s, int b){
    if(s == 0) return 0;

    if(b == 0) return max((p[s] - p[b]), helper(p, s - 1, s - 2));

    return max((p[s] - p[b]), helper(p, s, b - 1));
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n == 1) return 0;
    return helper(prices, n - 1, n - 2);
}


int main(){
 int n;cin>>n;
 vector<int>p(n, 0);
 
 for(auto &e : p)cin>>e;
 
 cout<<maxProfit(p)<<"\n";
 
 return 0;
} 