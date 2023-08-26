// 808. Soup Servings
// Medium
// 385
// 1.1K
// Companies

// There are two types of soup: type A and type B. Initially, we have n ml of each type of soup. There are four kinds of operations:

//     Serve 100 ml of soup A and 0 ml of soup B,
//     Serve 75 ml of soup A and 25 ml of soup B,
//     Serve 50 ml of soup A and 50 ml of soup B, and
//     Serve 25 ml of soup A and 75 ml of soup B.

// When we serve some soup, we give it to someone, and we no longer have it. Each turn, we will choose from the four operations with an equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as possible. We stop once we no longer have some quantity of both types of soup.

// Note that we do not have an operation where all 100 ml's of soup B are used first.

// Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input: n = 50
// Output: 0.62500
// Explanation: If we choose the first two operations, A will become empty first.
// For the third operation, A and B will become empty at the same time.
// For the fourth operation, B will become empty first.
// So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.

// Example 2:

// Input: n = 100
// Output: 0.71875

 

// Constraints:

//     0 <= n <= 109

// Accepted
// 22K
// Submissions
// 48K
// Acceptance Rate
// 45.9%


// problem want total probability when soup1 becomes 0 + both soup become 0 at same time
// we don't care what will be the probability when first b will become <= 0
// every time we are choosing one of the option from 4 options i.e 1/4 probability
class Solution {
    vector<pair<int, int>> serveSoup = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    
    double calculateProbability(int soupA, int soupB, unordered_map<int, unordered_map<int, double>> &dp) {
        if (soupA <= 0) {
            if (soupB <= 0) {
                return 0.5;
            }
            
            return 1.0;
        }

        if (soupB <= 0) {
            return 0.0;
        }

        if (dp.find(soupA) != dp.end() && dp[soupA].find(soupB) != dp[soupA].end()) {
            return dp[soupA][soupB];
        }

        double totalProbability = 0;

        for (auto [soup1Quant, soup2Quant] : serveSoup) {
            totalProbability += calculateProbability(soupA - soup1Quant, soupB - soup2Quant, dp);
        } 

        return dp[soupA][soupB] = totalProbability / 4.0;
    }
public:
    double soupServings(int n) {
        if (n > 4800) {
            return 1;
        }

        unordered_map<int, unordered_map<int, double>> dp;
        return calculateProbability(n, n, dp);
    }
};
