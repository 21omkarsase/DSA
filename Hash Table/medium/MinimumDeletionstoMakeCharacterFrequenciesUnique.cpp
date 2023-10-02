// 1647. Minimum Deletions to Make Character Frequencies Unique
// Medium
// 3.9K
// 58
// Companies

// A string s is called good if there are no two different characters in s that have the same frequency.

// Given a string s, return the minimum number of characters you need to delete to make s good.

// The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

 

// Example 1:

// Input: s = "aab"
// Output: 0
// Explanation: s is already good.

// Example 2:

// Input: s = "aaabbbcc"
// Output: 2
// Explanation: You can delete two 'b's resulting in the good string "aaabcc".
// Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".

// Example 3:

// Input: s = "ceabaacb"
// Output: 2
// Explanation: You can delete both 'c's resulting in the good string "eabaab".
// Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).

 

// Constraints:

//     1 <= s.length <= 105
//     s contains only lowercase English letters.

// Accepted
// 199.2K
// Submissions
// 333.3K
// Acceptance Rate
// 59.8%

// Time Complexity :  O(N + K) ->(K -> no. of groups)
// Space Complexity : O(N)

class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        
        unordered_map<char, int> char_freq;
        unordered_set<int> freq_taken;

        for (int idx = 0; idx < n; idx++) {
            char_freq[s[idx]]++;
        }

        int ans = 0;

        for (auto p : char_freq) {
            if (freq_taken.find(p.second) == freq_taken.end()) {
                freq_taken.insert(p.second);
            }
            else {
                int temp = p.second;
                
                while (temp > 0 && freq_taken.find(temp) != freq_taken.end()) {
                    temp--;
                    ans++;
                }

                if (temp > 0) {
                    freq_taken.insert(temp);
                }
            }
        }

        return ans;
    }
};