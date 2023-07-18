// 126. Word Ladder II
// Hard
// 5.4K
// 684
// Companies

// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

//     Every adjacent pair of words differs by a single letter.
//     Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
//     sk == endWord

// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"

// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

 

// Constraints:

//     1 <= beginWord.length <= 5
//     endWord.length == beginWord.length
//     1 <= wordList.length <= 500
//     wordList[i].length == beginWord.length
//     beginWord, endWord, and wordList[i] consist of lowercase English letters.
//     beginWord != endWord
//     All the words in wordList are unique.
//     The sum of all shortest transformation sequences does not exceed 105.

// Accepted
// 344.5K
// Submissions
// 1.3M
// Acceptance Rate
// 27.4%

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        queue<pair<string, vector<string>>> q;
        unordered_set<string> tracker(wordList.begin(), wordList.end());

        vector<vector<string>> sts;
        q.push({beginWord, {beginWord}});

        tracker.erase(beginWord);

        bool flag = true, mainFlag = true;

        while (!q.empty()) {
            int size = q.size();
            unordered_set<string> temp;

            while (size--) {
                string str = q.front().first;
                vector<string> prevVector = q.front().second;

                q.pop();

                if (!mainFlag && endWord == str) {
                    sts.push_back(prevVector);
                }
                
                if (mainFlag) {

                    for (int idx1 = 0; idx1 < str.size(); idx1++) {
                        char prev = str[idx1];

                        for (int idx2 = 0; idx2 < 26; idx2++) {
                            char curr = 'a' + idx2;

                            str[idx1] = curr;

                            if (tracker.find(str) != tracker.end()) {
                                prevVector.push_back(str);

                                q.push({str, prevVector});
                                
                                if(str != endWord) 
                                    temp.insert(str);

                                prevVector.pop_back();

                                if (str == endWord) {
                                    flag = false;
                                }
                            }

                            str[idx1] = prev;
                        }
                    }
                    
                } 
            }

            for (auto t : temp) {
                if (tracker.find(t) != tracker.end())
                    tracker.erase(t);
            }

            if (!flag)
                mainFlag = false;
        }

        return sts;
    }
};

