// 2260. Minimum Consecutive Cards to Pick Up
// Medium
// 736
// 21
// Companies

// You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.

// Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.

 

// Example 1:

// Input: cards = [3,4,2,3,4,7]
// Output: 4
// Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.

// Example 2:

// Input: cards = [1,0,5,3]
// Output: -1
// Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.

 

// Constraints:

//     1 <= cards.length <= 105
//     0 <= cards[i] <= 106

// Accepted
// 45.3K
// Submissions
// 89.1K
// Acceptance Rate
// 50.9%

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();

        int windowSize = n + 1;
        unordered_map<int, int> tracker;
        
        for (int idx = 0; idx < n; idx++) {
            if (tracker.find(cards[idx]) != tracker.end()) 
                windowSize = min(windowSize, (idx - tracker[cards[idx]] + 1));

            tracker[cards[idx]] = idx;
        }
        return windowSize == n + 1 ? -1 : windowSize;
    }
};