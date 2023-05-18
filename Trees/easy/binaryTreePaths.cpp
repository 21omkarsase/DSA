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
    void helper(TreeNode* root, vector<string> &ans, string s){
        if(!root) return;

        if(!root->left && !root->right){
            s += to_string(root->val);
            ans.push_back(s);
            return;
        }


        helper(root->left, ans, s + to_string(root->val) + "->");
        helper(root->right, ans, s + to_string(root->val) + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, ans, "");
        return ans;
    }
};