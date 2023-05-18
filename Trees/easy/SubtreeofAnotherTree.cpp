// https://leetcode.com/problems/subtree-of-another-tree/description/

// 572. Subtree of Another Tree
// Easy
// 7.1K
// 408
// Companies

// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 

// Example 1:

// Input: root = [3,4,5,1,2], subRoot = [4,1,2]
// Output: true

// Example 2:

// Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
// Output: false

 

// Constraints:

//     The number of nodes in the root tree is in the range [1, 2000].
//     The number of nodes in the subRoot tree is in the range [1, 1000].
//     -104 <= root.val <= 104
//     -104 <= subRoot.val <= 104

// Accepted
// 651.7K
// Submissions
// 1.4M
// Acceptance Rate
// 46.5%

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
    bool checkForExactMatch(TreeNode* root, TreeNode* subRoot){
        if(!subRoot && !root) 
            return true;

        if((!root && subRoot || !subRoot && root) || (root->val != subRoot->val))
            return false;

        cout<<root->val<<" : "<<subRoot->val<<"\n";

        bool left = checkForExactMatch(root->left, subRoot->left);
        bool right = checkForExactMatch(root->right, subRoot->right);

        return left && right;
    }

    void checkForMatch(TreeNode* root, TreeNode* subRoot, bool &ans){
        if(!root) return;

        if(root->val == subRoot->val){
            if(checkForExactMatch(root, subRoot)){
                cout<<root->val<<" --> "<<subRoot->val<<"\n";
                ans = true;
                return;
            }
        }

        checkForMatch(root->left, subRoot, ans);
        checkForMatch(root->right, subRoot, ans);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot && !root) 
            return true;

        bool ans = false;
        checkForMatch(root, subRoot, ans);
        return ans;
    }
};