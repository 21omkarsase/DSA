// 40. Combination Sum II
// Medium
// 9.6K
// 241
// Companies

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

 

// Constraints:

//     1 <= candidates.length <= 100
//     1 <= candidates[i] <= 50
//     1 <= target <= 30

// Accepted
// 816.9K
// Submissions
// 1.5M
// Acceptance Rate
// 53.7%

// Time Complexity : O(2^N * K) (k -> average length of combination array) (for generating all subsets in worst case)
// Space Complexity : O(K * X) (X -> NO. of combinations)


class Solution {
    void calculateTotalCombinations(int start, int target, vector<int> &combination, const vector<int> &candidates, vector<vector<int>> &combinations) {        
        if (target == 0) {
            combinations.push_back(combination);

            return;
        }
        
        if (start == candidates.size()) {
            return;
        }

        for (int idx = start; idx < candidates.size(); idx++) {
            while (idx != start && idx < candidates.size() && candidates[idx] == candidates[idx - 1]) {
                idx++;
            }

            if (idx < candidates.size() && target - candidates[idx] >= 0) {
                combination.push_back(candidates[idx]);

                calculateTotalCombinations(idx + 1, target - candidates[idx], combination, candidates, combinations);

                combination.pop_back();
            }
            else {
                break;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
                
        vector<vector<int>> combinations;
        vector<int> combination;

        calculateTotalCombinations(0, target, combination, candidates, combinations);
        
        return combinations;
    }
};