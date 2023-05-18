// 103. Binary Tree Zigzag Level Order Traversal
// Medium
// 9.2K
// 241
// Companies

// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]

// Example 2:

// Input: root = [1]
// Output: [[1]]

// Example 3:

// Input: root = []
// Output: []

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 2000].
//     -100 <= Node.val <= 100

// Accepted
// 955.2K
// Submissions
// 1.7M
// Ac



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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigZagNodes;

        if(!root) return zigZagNodes;

        queue<TreeNode *> queNodes;
        queNodes.push(root);
        
        bool flag = true;
        while(!queNodes.empty()){
            int size = queNodes.size();

            vector<int> v(size, 0);
            for(int i = 0; i < size; i++){
                TreeNode * node = queNodes.front();
                queNodes.pop();

                int idx = flag ? i : size - 1 - i;
                v[idx] = node->val;

                if(node && node->left){
                    queNodes.push(node->left);
                }

                if(node && node->right){
                    queNodes.push(node->right);
                }
            }
            flag = !flag;
            zigZagNodes.push_back(v);
        }

        return zigZagNodes;
    }
};
















