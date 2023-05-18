// https://leetcode.com/problems/validate-binary-search-tree/description/

// 98. Validate Binary Search Tree
// Medium
// 14.6K
// 1.2K
// Companies

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

//     The left
//     subtree
//     of a node contains only nodes with keys less than the node's key.
//     The right subtree of a node contains only nodes with keys greater than the node's key.
//     Both the left and right subtrees must also be binary search trees.

 

// Example 1:

// Input: root = [2,1,3]
// Output: true

// Example 2:

// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 104].
//     -231 <= Node.val <= 231 - 1
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
long long MAX = 2147483649, MIN = -2147483648;
class BSTNodeInfo{
public:
    long long mx;
    long long mn;

    BSTNodeInfo(){
        this->mx = MIN - 1;
        this->mn = MAX + 1;
    }
        
    BSTNodeInfo(int mx, int mn){
        this->mx = mx;
        this->mn = mn;
    }
};

class Solution {
public:
    BSTNodeInfo checkForValidBST(TreeNode *root, bool &ans){
        if(!root){
            return BSTNodeInfo();
        }

        BSTNodeInfo left = checkForValidBST(root->left, ans);
        BSTNodeInfo right = checkForValidBST(root->right, ans);

        if(left.mx >= root->val) ans = false;
        if(right.mn <= root->val) ans = false;

        cout<<left.mx<<" :: "<<right.mn<<" :::: "<<root->val<<"\n";
        
        // int newMax = max(right.mx, root->val);
        // int newMin = min(left.mn, root->val);

        long long newMax, newMin;

        if(right.mx > root->val) newMax = right.mx;
        else newMax = root->val;

        if(left.mn < root->val) newMin = left.mn;
        else newMin = root->val;

        return BSTNodeInfo(newMax, newMin);

    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        if(root && !root->left && !root->right)
            return true;

        bool ans = true;

        checkForValidBST(root, ans);


        return ans;
    }
};










