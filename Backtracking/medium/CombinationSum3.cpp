// 216. Combination Sum III
// Medium
// 5.5K
// 99
// Companies

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

//     Only numbers 1 through 9 are used.
//     Each number is used at most once.

// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.

// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

 

// Constraints:

//     2 <= k <= 9
//     1 <= n <= 60

// Accepted
// 435.6K
// Submissions
// 636K
// Acceptance Rate
// 68.5%

// Time Complexity : O(2^9)
// Space Complexity : O(N)

class Solution {
    void calculateTotalCombinations(int idx, const int &k, int n, vector<int> &combination, vector<vector<int>> &combinations) {
        if (n == 0 && combination.size() == k) {
            combinations.push_back(combination);
            
            return;
        }

        if (idx <= 9) {
            if (n - idx >= 0 && combination.size() + 1 <= k) {
                combination.push_back(idx);

                calculateTotalCombinations(idx + 1, k, n - idx, combination, combinations);
                
                combination.pop_back();
            }

            calculateTotalCombinations(idx + 1, k, n, combination, combinations);
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        vector<vector<int>> combinations;

        calculateTotalCombinations(1, k, n, combination, combinations);
        
        return combinations;
    }
};