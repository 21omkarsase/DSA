// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

// 889. Construct Binary Tree from Preorder and Postorder Traversal
// Medium
// 2.5K
// 98
// Companies

// Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

// If there exist multiple answers, you can return any of them.

 

// Example 1:

// Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]

// Example 2:

// Input: preorder = [1], postorder = [1]
// Output: [1]

 

// Constraints:

//     1 <= preorder.length <= 30
//     1 <= preorder[i] <= preorder.length
//     All the values of preorder are unique.
//     postorder.length == preorder.length
//     1 <= postorder[i] <= postorder.length
//     All the values of postorder are unique.
//     It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.



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
    TreeNode* constructBinaryTree(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd){
        if(preStart > preEnd) return NULL;

        TreeNode* root = new TreeNode(pre[preStart]);

        if(preStart == preEnd) return root;

        int postIndex = postStart;
        while(post[postIndex] != pre[preStart + 1]){
            postIndex++;
        };

        int len = postIndex - postStart + 1;

        root->left = constructBinaryTree(pre, preStart + 1, preStart + len, post, postStart, postIndex);
        root->right = constructBinaryTree(pre, preStart + len + 1, preEnd, post, postIndex + 1, postEnd - 1);

        return root;
    } 

    TreeNode* constructFromPrePost(vector<int>& preOrder, vector<int>& postOrder) {
        int n = preOrder.size();
        return constructBinaryTree(preOrder, 0, n - 1, postOrder, 0, n - 1);
    };
};





