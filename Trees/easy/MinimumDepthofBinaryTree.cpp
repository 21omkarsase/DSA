// 111. Minimum Depth of Binary Tree
// Easy
// 5.9K
// 1.1K
// Companies

// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

 

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 2

// Example 2:

// Input: root = [2,null,3,null,4,null,5,null,6]
// Output: 5

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 105].
//     -1000 <= Node.val <= 1000

// Accepted
// 960.8K
// Submissions
// 2.1M
// Acceptance Rate
// 45.0%

// Time Complexity : O(N) N -> Total nodes
// Space Complexity : O(2^h) when tree is fully balanced tree

// at any level max no. of nodes : 2 ^ (depth)

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int width = q.size();
            
            level++;

            while (width--) {
                TreeNode * node = q.front();
                q.pop();

                if (node->left != nullptr)
                    q.push(node->left);
                
                if (node->right != nullptr)
                    q.push(node->right);
                
                if (node->right == nullptr && node->left == nullptr)
                    return level;
            }
        }

        return level;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        if (!root->left && !root->right)
            return 1;
        
        if (root->left && root->right)
            return min(minDepth(root->right), minDepth(root->left)) + 1;

        if (root->left) 
            return minDepth(root->left) + 1;

        return minDepth(root->right) + 1;
    }
};