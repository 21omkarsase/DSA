// 2272. Substring With Largest Variance
// Hard
// 1.7K
// 194
// Companies

// The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

// Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: s = "aababbb"
// Output: 3
// Explanation:
// All possible variances along with their respective substrings are listed below:
// - Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
// - Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
// - Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
// - Variance 3 for substring "babbb".
// Since the largest possible variance is 3, we return it.

// Example 2:

// Input: s = "abcde"
// Output: 0
// Explanation:
// No letter occurs more than once in s, so the variance of every substring is 0.

 

// Constraints:

//     1 <= s.length <= 104
//     s consists of lowercase English letters.

// Accepted
// 62.3K
// Submissions
// 131.7K
// Acceptance Rate
// 47.3%

// we are interested only 2 characters
// to cover all possiblities -> check for all pairs of 26 characters
// for finding largest diff use kadane's algo idea (if char1Cnt < char2Cnt) set count of both to 0
//  i.e start new substring from there
// previous similar operations on reversed array (to cover all possiblities)

// Time Complexity : O(2*26*26*N)
// Space Complexity : O(N)

class Solution {
public:
    int largestVariance(string s) {
        int variance = 0;
        
        int iteration = 2;

        unordered_set<char> characters(begin(s), end(s));

        while (iteration--) {
            for (auto ch1 : characters) {
                for (auto ch2 : characters) {
                    int ch1Count = 0, ch2Count = 0;

                    for (int idx = 0; idx < s.size(); idx++) {
                        if (s[idx] == ch1)
                            ch1Count++;

                        if (s[idx] == ch2)
                            ch2Count++;
                        
                        if (ch1Count < ch2Count) {
                            ch1Count = 0, ch2Count = 0;
                        }

                        if (ch2Count > 0 && ch1Count > ch2Count) {
                            variance = max(variance, ch1Count - ch2Count);
                        }
                    }    
                }
            }
            if (iteration == 1)
                reverse(s.begin(), s.end());
        }

        return variance;
    }
};