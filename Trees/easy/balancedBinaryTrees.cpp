// 110. Balanced Binary Tree
// Easy
// 8.9K
// 499
// Companies

// Given a binary tree, determine if it is
// height-balanced
// .

 

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Example 2:

// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

// Example 3:

// Input: root = []
// Output: true

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 5000].
//     -104 <= Node.val <= 104


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
    int getHeight(TreeNode* root, bool &ans){
        if(!root) return 0;

        int left = getHeight(root->left, ans) + 1;
        int right = getHeight(root->right, ans) + 1;

        if(left > right + 1 | right > left + 1) ans = false;

        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        bool ans = true;

        getHeight(root, ans);
        
        return ans;
    }
};