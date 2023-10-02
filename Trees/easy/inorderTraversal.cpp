// 94. Binary Tree Inorder Traversal
// Solved
// Easy
// Topics
// Companies

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

// Example 1:

// Input: root = [1,null,2,3]
// Output: [1,3,2]

// Example 2:

// Input: root = []
// Output: []

// Example 3:

// Input: root = [1]
// Output: [1]

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 100].
//     -100 <= Node.val <= 100

 
// Follow up: Recursive solution is trivial, could you do it iteratively?
// Accepted
// 2.2M
// Submissions
// 2.9M
// Acceptance Rate
// 74.7%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while (curr || !st.empty()) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            }
            else if (!st.empty()){
                ans.push_back(st.top()->val);
                curr = st.top()->right;

                st.pop();
            }
        }

        return ans;
    }
};