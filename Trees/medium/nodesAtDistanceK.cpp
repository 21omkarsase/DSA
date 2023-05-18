// /https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
// / 863. All Nodes Distance K in Binary Tree
// Medium
// 8.4K
// 170
// Companies

// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

 

// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

// Example 2:

// Input: root = [1], target = 1, k = 3
// Output: []

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 500].
//     0 <= Node.val <= 500
//     All the values Node.val are unique.
//     target is the value of one of the nodes in the tree.
//     0 <= k <= 1000

// Accepted
// 303.9K
// Submissions
// 487.6K
// Acceptance Rate
// 62.3%
// Seen this question in a real interview before?
// 1/4
// Yes
// No


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void storeParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*>  &parents){
        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()){
            TreeNode *node = nodes.front();
            nodes.pop();

            if(node && node->left)
            {
                nodes.push(node->left);
                parents[node->left] = node;
            } 
            if(node && node->right)
            {
                nodes.push(node->right);
                parents[node->right] = node;
            } 
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
        unordered_map<TreeNode*, TreeNode*> parents;
        storeParents(root, parents);

        for(auto p : parents){
            cout<<p.first->val<<" --> "<<p.second->val<<"\n";
        }

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*>nodes;
        nodes.push(target);
        visited[target] = true;

        int distance = 0;

        while(!nodes.empty()){
            if(distance++ == k)
                break;

            int size = nodes.size();

            for(int i = 0; i < size; i++){
                TreeNode *node = nodes.front();
                nodes.pop();

                if(node && node->left && !visited[node->left]){
                    nodes.push(node->left);
                    visited[node->left] = true;
                }
                if(node && node->right && !visited[node->right]){
                    nodes.push(node->right);
                    visited[node->right] = true;
                }
                if(node && parents[node] && !visited[parents[node]]){
                    nodes.push(parents[node]);
                    visited[parents[node]] = true;
                }
            }
        }

        vector<int> kDistanceNodes;
        while(!nodes.empty()){
            TreeNode *node = nodes.front();
            nodes.pop();

            kDistanceNodes.push_back(node->val);
        }

        return kDistanceNodes;
    }
};