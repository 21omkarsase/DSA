// 77. Combinations
// Medium
// 6.4K
// 192
// Companies

// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.

 

// Constraints:

//     1 <= n <= 20
//     1 <= k <= n

// Accepted
// 696.2K
// Submissions
// 1M
// Acceptance Rate
// 67.7%

// Time Complexity : O(2^N)
// Space Complexity : O(N)

class Solution {
    void getAllCombinations(int curr, int &limit, int k, vector<int> &combination, vector<vector<int>> &combinations) {
        if (k <= 0) {
            combinations.push_back(combination);
            return;
        }

        if (curr > limit) {
            return;
        }

        combination.push_back(curr);
        getAllCombinations(curr + 1, limit, k - 1, combination, combinations);
        combination.pop_back();
        getAllCombinations(curr + 1, limit, k, combination, combinations);

    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        vector<vector<int>> combinations;
        
        getAllCombinations(1, n, k, combination, combinations);

        return combinations;
    }
};