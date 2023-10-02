// 145. Binary Tree Postorder Traversal
// Easy
// Topics
// Companies

// Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

// Example 1:

// Input: root = [1,null,2,3]
// Output: [3,2,1]

// Example 2:

// Input: root = []
// Output: []

// Example 3:

// Input: root = [1]
// Output: [1]

 

// Constraints:

//     The number of the nodes in the tree is in the range [0, 100].
//     -100 <= Node.val <= 100

 
// Follow up: Recursive solution is trivial, could you do it iteratively?
// Accepted
// 1M
// Submissions
// 1.5M
// Acceptance Rate
// 69.4%


// Time Complexity : O(N)
// Space Complexity : O(N) + O(N)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }

        stack<TreeNode*> st;   
        st.push(root);        

        set<TreeNode*> seen;

        vector<int> ans;

        while (!st.empty()) {
            TreeNode* node = st.top(); 

            if (node->left && seen.find(node->left) == seen.end()) {
                seen.insert(node->left);
                st.push(node->left);
            } else if (node->right && seen.find(node->right) == seen.end()) {
                seen.insert(node->right); 
                st.push(node->right);   
            } else {
                ans.push_back(node->val);
                st.pop();
            }
        }

        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*> st;

        vector<int> ans;

        while (curr != nullptr || !st.empty()) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* temp = st.top()->right;

                if (temp == nullptr) {
                    temp = st.top();
                    st.pop();

                    ans.push_back(temp->val);

                    while (!st.empty() && st.top()->right == temp) {
                        temp = st.top();
                        st.pop();

                        ans.push_back(temp->val);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }

        return ans;
    }
};