// 968. Binary Tree Cameras
// Hard
// 4.8K
// 62
// Companies

// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

// Return the minimum number of cameras needed to monitor all nodes of the tree.

 

// Example 1:

// Input: root = [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.

// Example 2:

// Input: root = [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 1000].
//     Node.val == 0

// Accepted
// 121.2K
// Submissions
// 260.1K
// Acceptance Rate
// 46.6%

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

#define inf 1005


map<pair<TreeNode *, pair<bool, bool>>, int> dp; 

class Solution {
public:
    int solve(TreeNode *root, bool cam, bool parCam){
        if(!root){
            if(cam) return inf;
            else return 0;
        }

        if(!root->left && !root->right){
            if(cam) return 1;
            else {
                if(parCam) return 0;
                else return inf;
            }
        }

        if(dp.find({root, {cam, parCam}}) != dp.end()) return dp[{root, {cam, parCam}}];

        if(cam){
            return dp[{root, {cam, parCam}}] = 1 + 
            min(solve(root->left, 0, 1), solve(root->left, 1, 1)) + 
            min(solve(root->right, 0, 1), solve(root->right, 1, 1));
        }else{
            if(parCam){
                return dp[{root, {cam, parCam}}] = 
                min(solve(root->left, 0, 0), solve(root->left, 1, 0)) + 
                min(solve(root->right, 0, 0), solve(root->right, 1, 0));
            }else{
                int case1 = 
                solve(root->left, 1, 0) + min(solve(root->right, 1, 0), solve(root->right, 0, 0));
                int case2 = 
                solve(root->right, 1, 0) + min(solve(root->left, 1, 0), solve(root->left, 0, 0));
                return dp[{root, {cam, parCam}}] = min(case1, case2);
            }
        }
    }

    int minCameraCover(TreeNode* root) {
        return min(solve(root, 0, 0), solve(root, 1, 0));
    }
};













