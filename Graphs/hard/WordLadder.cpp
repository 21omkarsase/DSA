// 127. Word Ladder
// Hard
// 10.7K
// 1.8K
// Companies

// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

//     Every adjacent pair of words differs by a single letter.
//     Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
//     sk == endWord

// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

 

// Constraints:

//     1 <= beginWord.length <= 10
//     endWord.length == beginWord.length
//     1 <= wordList.length <= 5000
//     wordList[i].length == beginWord.length
//     beginWord, endWord, and wordList[i] consist of lowercase English letters.
//     beginWord != endWord
//     All the words in wordList are unique.

// Accepted
// 923.5K
// Submissions
// 2.5M
// Acceptance Rate
// 37.5%

// Time Complexity : O(N*wordLength*26)
// Space Complexity : O(N)


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        
        int level = 0;

        unordered_map<string, int> tracker;
        queue<string> q;

        for (auto word : wordList)
            tracker[word]++;

        q.push(beginWord);

        while (!q.empty()) {
            int size = q.size();
            level++;

            for (int x = 0; x < size; x++) {
                string str = q.front();
                tracker[str]--;

                q.pop();

                if (str == endWord)
                    return level;

                for (int idx1 = 0; idx1 < str.size(); idx1++) {
                    char ch1 = str[idx1];
                    bool flag = false;

                    for (int idx2 = 0; idx2 < 26; idx2++) {
                        char ch2 = 'a' + idx2;

                        str[idx1] = ch2;

                        if(tracker.find(str) != tracker.end() && tracker[str] > 0) {
                            q.push(str);
                            flag = true;
                        }
                        
                        str[idx1] = ch1;
                    }
                }
            }
        }

        return 0;
    }
};