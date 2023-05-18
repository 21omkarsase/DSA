// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

// 235. Lowest Common Ancestor of a Binary Search Tree
// Medium
// 9.3K
// 265
// Companies

// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

// Example 1:

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.

// Example 2:

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
// Output: 2
// Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

// Example 3:

// Input: root = [2,1], p = 2, q = 1
// Output: 2

 

// Constraints:

//     The number of nodes in the tree is in the range [2, 105].
//     -109 <= Node.val <= 109
//     All Node.val are unique.

    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        if(!root) return NULL;

        TreeNode *left = helper(root->left, p, q, ans);
        TreeNode *right = helper(root->right, p, q, ans);

        cout<<root->val<<" --> "<<(left != NULL ? left->val : NULL)<<" :: "<<(right != NULL ? right->val : NULL)<<"\n";

        if((left == p && right == q) || (left == q && right == p)){
            ans = root;
            cout<<"here\n";
            return root;
        }

        if(root == p || root == q)
            return root;
        if(root == p || root == q)
            return root;

        if(left == p || left == q)
            return left;
        if(right == p || right == q)
            return right;

        return new TreeNode(-1);
    }
    void helper2(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        if(!root) return;

        if(root == p || root == q){
            ans = root;
            return;
        }

        helper2(root->left, p, q, ans);
        helper2(root->right, p, q, ans);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = new TreeNode(-1);
        helper(root, p, q, ans);
        if(ans->val == -1){
            helper2(root, p, q, ans);
        }
        
        return ans;
    }
};