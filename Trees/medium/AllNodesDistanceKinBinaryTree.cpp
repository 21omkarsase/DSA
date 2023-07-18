// 863. All Nodes Distance K in Binary Tree
// Medium
// 8.8K
// 172
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
// 315.5K
// Submissions
// 504.5K
// Acceptance Rate
// 62.5%

// Time Complexity : O(N)
// Space Complexity : O(N)



class Solution {
    void getParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parents) {
        if (root->left != nullptr) {
            parents[root->left] = root;
            getParents(root->left, parents);
        }

        if (root->right != nullptr) {
            parents[root->right] = root;
            getParents(root->right, parents);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] = nullptr;

        if(root != nullptr)
            getParents(root, parents);
        else
            return {};

        vector<int> nodesAtDistK;
        
        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});


        while (!q.empty()) {
            int queueSize = q.size();

            while (queueSize--) {
                TreeNode *node = q.front().first;
                int level = q.front().second;

                q.pop();

                visited.insert(node);

                if (level == k) {
                    nodesAtDistK.push_back(node->val);
                } else {
                    if (visited.find(node->left) == visited.end() && node->left != nullptr) {
                        q.push({node->left, level + 1});
                    }

                    if (visited.find(node->right) == visited.end() && node->right != nullptr) {
                        q.push({node->right, level + 1});
                    }

                    if (visited.find(parents[node]) == visited.end() && parents[node] != nullptr) {
                        q.push({parents[node], level + 1});
                    }
                }
            }
        }

        return nodesAtDistK;
    }
};
