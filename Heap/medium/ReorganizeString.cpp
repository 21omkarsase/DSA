// 767. Reorganize String
// Medium
// 6.9K
// 215
// Companies

// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

 

// Example 1:

// Input: s = "aab"
// Output: "aba"

// Example 2:

// Input: s = "aaab"
// Output: ""

 

// Constraints:

//     1 <= s.length <= 500
//     s consists of lowercase English letters.

// Accepted
// 288.7K
// Submissions
// 540.7K
// Acceptance Rate
// 53.4%

// Time Complexity : O(N * LogK)
// Space Complexity : O(N)

class Solution {
    const pair<int, char> NONE_PAIR = {-1, '\0'};
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> tracker;

        for (auto ch : s) {
            tracker[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto p : tracker) {
            pq.push({p.second, p.first});
        }
        
        string ans = "";
        pair<int, char> prev = NONE_PAIR; 

        while (!pq.empty() || prev != NONE_PAIR) {
            if (pq.empty() && prev != NONE_PAIR) {
                return "";
            }

            int cnt = pq.top().first;
            char ch = pq.top().second;

            pq.pop();
        
            ans += ch;
            cnt--;

            if (prev != NONE_PAIR) {
                pq.push(prev);
                prev = NONE_PAIR;
            }

            if (cnt != 0) {
                prev = {cnt, ch};
            }
        }

        return ans;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> tracker;

        for (auto ch : s) {
            tracker[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto p : tracker) {
            pq.push({p.second, p.first});
        }
        
        string ans = "";
        
        while (pq.size() > 1) {
            auto pair1 = pq.top();
            pq.pop();

            auto pair2 = pq.top();
            pq.pop();

            ans += pair1.second;
            ans += pair2.second;

            pair1.first--;
            pair2.first--;

            if (pair1.first != 0) {
                pq.push(pair1);
            }

            if (pair2.first != 0) {
                pq.push(pair2);
            }
        }

        if (!pq.empty()) {
            if (pq.top().first > 1) {
                return "";
            }
            
            ans += pq.top().second;
        }
        
        return ans;
    }
};