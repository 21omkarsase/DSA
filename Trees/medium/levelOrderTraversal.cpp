// 102. Binary Tree Level Order Traversal
// Medium
// 13.1K
// 261
// Companies

// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

// Example 2:

// Input: root = [1]
// Output: [[1]]

// Example 3:

// Input: root = []
// Output: []

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 2000].
//     -1000 <= Node.val <= 1000

// Accepted
// 1.8M
// Su

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelNodes;

        if(!root) return levelNodes;

        queue<TreeNode *>qNodes;
        qNodes.push(root);

        while(!qNodes.empty()){
            int size = qNodes.size();
            vector<int>v;

            for(int i = 0; i < size; i++){
                TreeNode *node = qNodes.front();
                qNodes.pop();
                if(!node) break;
                v.push_back(node->val);

                if(node->left) qNodes.push(node->left);
                if(node->right) qNodes.push(node->right);
            }

            levelNodes.push_back(v);
        }

        return levelNodes;
    }
};
















