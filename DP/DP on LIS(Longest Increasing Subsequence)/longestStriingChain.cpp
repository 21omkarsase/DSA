#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b){
    int n = a.size(), m = b.size();
    if(m != n + 1) return false;

    int i = 0, j = 0, cnt = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            j++;
            i++;
        }else{
            j++;
            cnt++;
        }
    }

    if(cnt > 1) return false;
    return true;
}

int longestStrChain(vector<string>& words) {
    int n = words.size();
    sort(words.begin(), words.end(),  
        [](const string & a, const string & b) -> bool
        { 
            return a.size() < b.size(); 
        }
    );

    vector<int>dp (n,1);

    int ans = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(compare(words[j], words[i]) && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
        if(dp[i] > ans){
            ans = dp[i];
        }
    }

    return ans;
}

int main(){
    int n;
    cin>> n;
    vector<string> str(n, "");
    for(auto &e : str) cin >> e;
    cout<<longestStrChain(str)<<"\n";
    return 0;
}