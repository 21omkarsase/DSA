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
    TreeNode* merge(TreeNode* root1, TreeNode* root2){
        TreeNode * root;
        if(!root1 && !root2)
            return NULL;
        
        if(root1 && root2)
            root = new TreeNode(root1->val + root2->val);
        
        if(root1 && !root2)
           root = new TreeNode(root1->val);
        
        if(!root1 && root2)
            root = new TreeNode(root2->val);

        root->left = merge(root1 != NULL ? root1->left : NULL, root2 != NULL ? root2->left : NULL);
        root->right = merge(root1 != NULL ? root1->right : NULL, root2 != NULL ? root2->right : NULL);

        return root;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        else if(!root2) return root1;
        
        return merge(root1, root2);
    }
};


























