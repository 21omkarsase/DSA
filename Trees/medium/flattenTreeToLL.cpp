// 114. Flatten Binary Tree to Linked List
// Medium
// 10.4K
// 511
// Companies

// Given the root of a binary tree, flatten the tree into a "linked list":

//     The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
//     The "linked list" should be in the same order as a pre-order traversal of the binary tree.

 

// Example 1:

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]

// Example 2:

// Input: root = []
// Output: []

// Example 3:

// Input: root = [0]
// Output: [0]

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 2000].
//     -100 <= Node.val <= 100

 
// Follow up: Can you flatten the tree in-place (with O(1) extra space)?
// Accepted
// 771.9K
// Submissions
// 1.2M
// Acceptance Rate
// 62.0%
// Seen this question in a real interview before?
// 1/4
// Yes
// No
// Discussion (16)
// Similar Questions
// Flatten a Multilevel Doubly Linked List
// Medium
// Correct a Binary Tree
// Medium
// Related Topics

class Solution {
public:
    void getLeftLeaf(TreeNode *root, TreeNode *&leftLeaf){
        if(root == nullptr) return;

        if(!root->left && !root->right) {
            leftLeaf = root;
        }

        getLeftLeaf(root->left, leftLeaf);
        getLeftLeaf(root->right, leftLeaf);
    }

    void getFlattenLL(TreeNode *&root) {
        if (root == nullptr)
            return;

        getFlattenLL(root->left);
        getFlattenLL(root->right);

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        if (left == nullptr && right == nullptr)
            return;

        if (right == nullptr) {
            root->right = left;
            root->left = nullptr;
            return;
        }

        if (left == nullptr) {
            return;
        }

        TreeNode *leftLeaf = nullptr;
        getLeftLeaf(left, leftLeaf);

        cout<<root->val<<" :<->: "<<leftLeaf->val;

        leftLeaf->right = root->right;

        root->right = root->left;
        root->left = nullptr;
    }

    void flatten(TreeNode* root) {
        getFlattenLL(root);
    }
};


































