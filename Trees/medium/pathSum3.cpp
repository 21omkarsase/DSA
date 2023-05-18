// https://leetcode.com/problems/path-sum-iii/description/

// 437. Path Sum III
// Medium
// 9.5K
// 463
// Companies

// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

// Example 1:

// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.

// Example 2:

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: 3

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 1000].
//     -109 <= Node.val <= 109
//     -1000 <= targetSum <= 1000

// Accepted
// 453K
// Submissions
// 947.1K
// Acceptance Rate
// 47.8%


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
        void getEachNodeCount(TreeNode *root, int targetSum, int &ans, long long currSum){
            if(!root) return;

            if(currSum + root->val == targetSum) ans++;

            getEachNodeCount(root->left, targetSum, ans, currSum + root->val);
            getEachNodeCount(root->right, targetSum, ans, currSum + root->val);
        }

        void calculatePathCount(TreeNode *root, int targetSum, int &ans){
            if(!root) return;

            getEachNodeCount(root, targetSum, ans, 0);

            calculatePathCount(root->left, targetSum, ans);
            calculatePathCount(root->right, targetSum, ans);
        }

        int pathSum(TreeNode* root, int targetSum) {
            int ans = 0;
            calculatePathCount(root, targetSum, ans);

            return ans;
        }
    };










