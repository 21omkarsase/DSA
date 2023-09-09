// 39. Combination Sum
// Medium
// 17.4K
// 351
// Companies

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
// frequency
// of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// Example 3:

// Input: candidates = [2], target = 1
// Output: []

 

// Constraints:

//     1 <= candidates.length <= 30
//     2 <= candidates[i] <= 40
//     All elements of candidates are distinct.
//     1 <= target <= 40

// Accepted
// 1.6M
// Submissions
// 2.3M
// Acceptance Rate
// 69.8%

// Time Complexity : O(2^T * K) (k -> average length of combination array) (T not N (bcz an ele can be picked multple times. T >= N))
// Space Complexity : O(K * X) (X -> no. of combinations) 


class Solution {
    void calculateTotalCombinations(int idx, int target, vector<int> &combination, const vector<int> &candidates, vector<vector<int>> &combinations) {
        if (idx == candidates.size()) {
            if (target == 0) {
                combinations.push_back(combination);
            }

            return;
        }

        if (candidates[idx] <= target) {
            combination.push_back(candidates[idx]);
            
            calculateTotalCombinations(idx, target - candidates[idx], combination, candidates, combinations);
            
            combination.pop_back();
        }

        calculateTotalCombinations(idx + 1, target, combination, candidates, combinations);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> combinations;

        calculateTotalCombinations(0, target, combination, candidates, combinations);
        
        return combinations;
    }
};