// 144. Binary Tree Preorder Traversal
// Solved
// Easy
// Topics
// Companies

// Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

// Example 1:

// Input: root = [1,null,2,3]
// Output: [1,2,3]

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
// 1.4M
// Submissions
// 2.1M
// Acceptance Rate
// 68.2%


// Time Complexity : O(N)
// Space Complexity : O(N)

void getPreOrder(Node*head,vector<int>&v){
    if(head==NULL)return;
    
    v.push_back(head->data);
    getPreOrder(head->left,v);
    getPreOrder(head->right,v);
}

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
    vector<int>ans;
    getPreOrder(root,ans);
    return ans;
}

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;   
        
        if (root == nullptr) {
            return ans;
        }

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            if (node->right) {
                st.push(node->right);
            }

            if (node->left) {
                st.push(node->left);
            }
        }

        return ans;
    }
};


















