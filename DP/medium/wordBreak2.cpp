#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int i, int n, string s, vector<string> curr, vector<string>& wd, vector<string>& ans){
        if(i == n) {
            string sub = "";
            for(int j = 0; j < curr.size(); j++){
                sub += curr[j];
                if(j != curr.size() - 1){
                    sub += " ";
                }
            }
            ans.push_back(sub);
            return;
        }

        for(int j = 0; j < wd.size(); j++){
            int len = wd[j].size();

            if(i + len <= n && s.substr(i, len) == wd[j]){
                curr.push_back(wd[j]);
                helper(i + len, n, s, curr, wd, ans);
                curr.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans, curr;
        int n = s.size();
       
        helper(0, n, s, curr, wordDict, ans);

        return ans;
    }
};

int main(){
    int n;cin>>n;
    
    string s; 
    cin >> s;

    vector<string>wordDict(n, "");
    for(auto &e : wordDict){
        cin >> e;
    }

    Solution * sl = new Solution();

    vector<string> ans = sl->wordBreak(s, wordDict);

    for(auto str : ans){
        cout<<str<<" --> ";
    }

    cout<<"\n";
    
    return 0;
}