// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

// 108. Convert Sorted Array to Binary Search Tree
// Easy
// 9.5K
// 475
// Companies

// Given an integer array nums where the elements are sorted in ascending order, convert it to a
// height-balanced
// binary search tree.

 

// Example 1:

// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:

// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

 

// Constraints:

//     1 <= nums.length <= 104
//     -104 <= nums[i] <= 104
//     nums is sorted in a strictly increasing order.


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
    TreeNode* helper(int start, int end, vector<int> &nums){
        if(start > end) return NULL;

        int mid = (start + end + 1) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = helper(start, mid - 1, nums);
        root->right = helper(mid + 1, end, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(0, n - 1, nums);
    }















};