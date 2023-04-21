#include<bits/stdc++.h>
using namespace std;

bool wbHelper3(string s, vector<int> &dp, unordered_set<string> &us, int start){
    if(s.size() == start)
        return 1;

    if(dp[start] != -1) return dp[start];

    for(int i = start; i < s.size(); i++){
        if(us.count(s.substr(start, i + 1 - start)) && wbHelper3(s, dp, us, i + 1)){
            return dp[start] = true;
        }
    }

    return dp[start] = false;
}
bool wordBreak3(string s, vector<string>& wordDict) {
    vector<int>dp(s.size(), -1);
    unordered_set<string> us(wordDict.begin(), wordDict.end());
    return wbHelper3(s, dp, us, 0);
}

bool wbHelper2(string s, unordered_set<string> &us, int start){
    if(s.size() == start)
        return 1;

    for(int i = start; i < s.size(); i++){
        if(us.count(s.substr(start, i + 1 - start)) && wbHelper2(s, us, i + 1)){
            return true;
        }
    }

    return false;
}
bool wordBreak2(string s, vector<string>& wordDict) {
    unordered_set<string> us(wordDict.begin(), wordDict.end());
    return wbHelper2(s, us, 0);
}


bool wbHelper1(string s, unordered_set<string> &us){
    if(s.size() == 0)
        return 1;

    for(int i = 0; i < s.size(); i++){
        if(us.count(s.substr(0, i + 1)) && wbHelper1(s.substr(i + 1), us)){
            return true;
        }
    }

    return false;
}
bool wordBreak1(string s, vector<string>& wordDict) {
    unordered_set<string> us(wordDict.begin(), wordDict.end());
    return wbHelper1(s, us);
}

int main(){
    int n;cin>>n;
    vector<string>wd(n, "");
    for(auto &e : wd) 
        cin >> e;
    string s;
    cin >> s;

    cout<<wordBreak1(s, wd)<<"\n";
    cout<<wordBreak2(s, wd)<<"\n";
    cout<<wordBreak3(s, wd)<<"\n";
    
    return 0;
}