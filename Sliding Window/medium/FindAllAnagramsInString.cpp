// 438. Find All Anagrams in a String
// Medium
// 11.4K
// 316
// Companies

// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

 

// Constraints:

//     1 <= s.length, p.length <= 3 * 104
//     s and p consist of lowercase English letters.

// Accepted
// 771.5K
// Submissions
// 1.5M
// Acceptance Rate
// 50.3%


// Time Complexity : O(N))
// Space Complexity : O(N*M)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       int n = s.size();
       int windowSize = p.size();
        
       sort(p.begin(), p.end());
        
       int left = 0;
       vector<int> anagramIndexes;
       string substring = "";

       for (int right = 0; right < n; right++) {
           substring += s[right];

           if (substring.size() == windowSize) {
               string temp = substring;
               sort(temp.begin(), temp.end());
               
               if (temp == p)
                    anagramIndexes.push_back(right - windowSize + 1);
               
               substring = substring.substr(1);
           }
       }

       return anagramIndexes;
    }
};


// Time Complexity : O(N))
// Space Complexity : O(N*26)


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();

        unordered_map<char, int> countTracker1, countTracker2;

        for (auto ch : p) 
            countTracker1[ch]++;
        
        int left = 0;
        vector<int> anagramIndexes;

        for (int right = 0; right < n; right++) {
            countTracker2[s[right]]++;

            if (right - left + 1 == m) {
                bool flag = true;

                if (countTracker1 == countTracker2)
                    anagramIndexes.push_back(left);
                
                countTracker2[s[left]]--;

                if (countTracker2[s[left]] == 0)
                    countTracker2.erase(s[left]);
                left++;
            }
        }

        return anagramIndexes;
    }
};