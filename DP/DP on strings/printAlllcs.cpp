// Print all LCS sequences
// HardAccuracy: 30.64%Submissions: 14K+Points: 8
// Apply for Mega Job-A-Thon: Fresher Edition | 30+ Opportunities | Avg CTC: 7 LPA  

// You are given two strings s and t. Now your task is to print all longest common sub-sequences in lexicographical order.

// Example 1:

// Input: s = abaaa, t = baabaca
// Output: aaaa abaa baaa

// Example 2:

// Input: s = aaa, t = a
// Output: a

// Your Task:
// You do not need to read or print anything. Your task is to complete the function all_longest_common_subsequences() which takes string a and b as first and second parameter respectively and returns a list of strings which contains all possible longest common subsequences in lexicographical order.
 

// Expected Time Complexity: O(n4)
// Expected Space Complexity: O(K * n) where K is a constant less than n.
//  

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    void getAlllcs(int row, int col, string &s, string &t, string str, vector<vector<int>> &dp, unordered_set<string> &lcsArray){
        if(str.size() == dp[s.size()][t.size()]){
            if(lcsArray.find(str) == lcsArray.end())
                lcsArray.insert(str);
            return;
        }
        
        if(row >= s.size() || col >= t.size()){
            return;
        }
        
        for(int i = row; i < s.size(); i++){
            for(int j = col; j < t.size(); j++){
                if(s[i] == t[j]){
                    getAlllcs(i + 1, j + 1, s, t, str + s[i], dp, lcsArray);
                }
            }
        }
    }
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    int n = s.size(), m = t.size();
		    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		    
		    for(int i = 1; i <= n; i++){
		        for(int j = 1; j <= m; j++){
		            if(s[i - 1] == t[j - 1]){
		                dp[i][j] = dp[i - 1][j - 1] + 1;
		            }else{
		                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		            }
		        }
		    }
		    

		    unordered_set<string> lcsArray;
		    getAlllcs(0, 0, s, t, "", dp, lcsArray);
		    
		    vector<string> ans(lcsArray.begin(), lcsArray.end());
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};





//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends