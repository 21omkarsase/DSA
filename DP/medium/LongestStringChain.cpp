// 1048. Longest String Chain
// Solved
// Medium
// Topics
// Companies
// Hint

// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

//     For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

 

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

 

// Constraints:

//     1 <= words.length <= 1000
//     1 <= words[i].length <= 16
//     words[i] only consists of lowercase English letters.

// Accepted
// 325.5K
// Submissions
// 545.9K
// Acceptance Rate
// 59.6%

// Time Complexity : O(N * N * 16)
// Space Complexity : O(N * N + 2N)
 bool check(string a, string b) {
    return a.size() < b.size();
}
    
class Solution {
    int calculateLongestStrChain(int prev, int curr, const vector<string> &words, vector<vector<int>> &dp) {
        if (curr >= words.size()) {
            return 0;
        }

        if (dp[prev + 1][curr + 1] != -1) {
            return dp[prev + 1][curr + 1];
        }

        int take = 0, notTake = 0;

        if (prev == -1) {
            take = 1 + calculateLongestStrChain(curr, curr + 1, words, dp);
        }
        else if (words[curr].size() == words[prev].size() + 1){
            int idx1 = words[curr].size() - 1, idx2 = words[prev].size() - 1;
            bool flag = true;

            while (idx2 >= 0) {
                if (words[curr][idx1] != words[prev][idx2]) {
                    if (flag) {
                        idx1--;
                        flag = false;
                    }
                    else {
                        break;
                    }
                }
                else {
                    idx1--, idx2--;
                }
            }

            if ((idx1 == -1 && idx2 == -1) || (flag && idx1 == 0)) {
                take = 1 + calculateLongestStrChain(curr, curr + 1, words, dp);
            }
        }
            
        notTake = calculateLongestStrChain(prev, curr + 1, words, dp);

        return dp[prev + 1][curr + 1] = max(take, notTake);
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), check);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
       
        return calculateLongestStrChain(-1, 0, words, dp);
    }
};