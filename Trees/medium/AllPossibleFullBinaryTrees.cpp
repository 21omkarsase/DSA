// 894. All Possible Full Binary Trees
// Medium
// 3.7K
// 263
// Companies

// Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

// Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

 

// Example 1:

// Input: n = 7
// Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

// Example 2:

// Input: n = 3
// Output: [[0,0,0]]

 

// Constraints:

//     1 <= n <= 20

// Accepted
// 113.5K
// Submissions
// 141.7K
// Acceptance Rate
// 80.1%


class Solution {
    unordered_map<int, vector<TreeNode*>> dp;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n == 1) {
            return {new TreeNode(0)};
        }

        if (dp.find(n) != dp.end()) {
            return dp[n];
        }

        vector<TreeNode*> left, right, ans; 
                                                //    1   1     possible partitions
        for (int idx = 2; idx < n; idx += 2) {   // 0 0 0 0 0
            left = allPossibleFBT(idx - 1);
            right = allPossibleFBT(n - idx);

            for (auto leftNode : left) {
                for (auto rightNode : right) {
                    TreeNode * node = new TreeNode(0);   // for every partition taking all combinations 
                    node->left = leftNode;
                    node->right = rightNode;

                    ans.push_back(node);
                }
            }
        }

        return dp[n] = ans;
    }
};