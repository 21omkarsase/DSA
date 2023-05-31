// 95. Unique Binary Search Trees II
// Medium
// 5.9K
// 384
// Companies

// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

// Example 1:

// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

// Example 2:

// Input: n = 1
// Output: [[1]]

 

// Constraints:

//     1 <= n <= 8

// Accepted
// 353.7K
// Submissions
// 672.2K
// Acceptance Rate
// 52.6%

class Solution {
    vector<TreeNode*> solve(int st, int en){
        if(st > en){
            vector<TreeNode*> root;
            root.push_back(nullptr);
            return root;
        }
        
        vector<TreeNode*>roots;
        for(int i = st; i <= en; i++){
            vector<TreeNode*>left = solve(st, i - 1);
            vector<TreeNode*>right = solve(i + 1, en);
            for(auto leftNode : left){
                for(auto rightNode : right){
                    TreeNode *root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    roots.push_back(root);
                }
            }
        }
        return roots;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};

