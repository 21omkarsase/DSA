// 662. Maximum Width of Binary Tree
// Medium
// 7.5K
// 1K
// Companies

// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

// It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

// Example 1:

// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

// Example 2:

// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

// Example 3:

// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width exists in the second level with length 2 (3,2).

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 3000].
//     -100 <= Node.val <= 100

// Accepted
// 298.2K
// Submissions
// 697.8K
// Acceptance Rate
// 42.7%
// Seen this question in a real interview before?
// 1/4
// Yes
// No
// Discussion (58)
// Related Topics
// Tree
// Depth-First Search
// Breadth-First Search
// Binary Tree
// Copyright ©️ 2023 LeetCode All rights reserved

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        if(!root->left && !root->right) return 1;
        
        queue<pair<int, TreeNode *>>q;
        q.push({0, root});
        
        int width = 0;
        while(!q.empty()){
            int size = q.size();
            int minIdx = q.front().first;
            
            long long first, last;
            for(int i = 0; i < size; i++){
                TreeNode *node = q.front().second;
                long long idx = q.front().first - minIdx;
                q.pop();

                if(i == 0) first = idx;
                if(i == size - 1) last = idx;

                if(node->left){
                    q.push({(2 * idx) + 1, node->left});
                }

                if(node->right){
                    q.push({(2 * idx) + 2, node->right});
                }
            }
            if(width < last - first + 1) width = last - first + 1;
        }

        return width;
    }
};























