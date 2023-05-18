// https://leetcode.com/problems/symmetric-tree/description/

// 101. Symmetric Tree
// Easy
// 13.4K
// 301
// Companies

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

// Example 1:

// Input: root = [1,2,2,3,4,4,3]
// Output: true

// Example 2:

// Input: root = [1,2,2,null,3,null,3]
// Output: false

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 1000].
//     -100 <= Node.val <= 100

 
// Follow up: Could you solve it both recursively and iteratively?

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
    bool helper(TreeNode* left, TreeNode* right){
        if(!left && !right)
            return true;
        
        if(!left || !right || left->val != right->val)
            return false;
        
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return false;
        
        return helper(root->left, root->right);
    }
};

class Solution {
public:
    void helper1(TreeNode* root, vector<int> &v){
        if(!root){
            v.push_back(-1);
            return;
        } 
        
        v.push_back(root->val);
        helper1(root->left, v);
        helper1(root->right, v);
    }
    void helper2(TreeNode* root, vector<int> &v){
        if(!root){
            v.push_back(-1);
            return;
        } 
        
        v.push_back(root->val);
        helper2(root->right, v);
        helper2(root->left, v);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> v1, v2;
        helper1(root->left, v1);
        helper2(root->right, v2);

        if(v1.size() != v2.size())
            return false;
        
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] != v2[i])
                return false;
        }
        return true;
    }
};