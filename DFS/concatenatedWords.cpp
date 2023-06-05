// 472. Concatenated Words
// Hard
// 3.6K
// 274
// Companies

// Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

// A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necesssarily distinct) in the given array.

 

// Example 1:

// Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
// "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

// Example 2:

// Input: words = ["cat","dog","catdog"]
// Output: ["catdog"]

 

// Constraints:

//     1 <= words.length <= 104
//     1 <= words[i].length <= 30
//     words[i] consists of only lowercase English letters.
//     All the strings of words are unique.
//     1 <= sum(words[i].length) <= 105

// Accepted
// 208.4K
// Submissions
// 417.6K
// Acceptance Rate
// 49.9%
// Seen this question in a real interview before?
// 1/4
// Yes
// No
// Discussion (54)
// Similar Questions
// Word Break II
// Hard
// Related Topics
// Array
// String
// Dynamic Programming
// Depth-First Search
// Trie
// Copyright ©️ 2023 LeetCode All rights reserved

class Solution {
    bool dfs(string s, unordered_set<string> &dict, unordered_map<string, bool> &dp){
        if(dp.find(s) != dp.end())
            return dp[s];
            
        for(int i = 1; i < s.size(); i++){
            string prefix = s.substr(0, i);
            string suffix = s.substr(i);
            if(dict.find(prefix) != dict.end() && (dict.find(suffix) != dict.end() || dfs(suffix, dict, dp)))
                return dp[s] = true;
        }
        return dp[s] = false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict;
        for(auto w : words)
            dict.insert(w);
        
        vector<string>ans;
        unordered_map<string, bool> dp;
        for(int i = 0; i < words.size(); i++){
            if(dfs(words[i], dict, dp))
                ans.push_back(words[i]);
        }

        return ans;
    }
};