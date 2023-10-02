// 1457. Pseudo-Palindromic Paths in a Binary Tree
// Solved
// Medium
// Topics
// Companies
// Hint

// Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

// Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

 

// Example 1:

// Input: root = [2,3,1,3,1,null,1]
// Output: 2 
// Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).

// Example 2:

// Input: root = [2,1,1,1,3,null,null,null,null,null,1]
// Output: 1 
// Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).

// Example 3:

// Input: root = [9]
// Output: 1

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 105].
//     1 <= Node.val <= 9

// Accepted
// 117.1K
// Submissions
// 173.5K
// Acceptance Rate
// 67.5%

// Time Complexity : O(N  * 9)
// Space Complexity : O(9) + O(maxHeight(tree))
class Solution {
    bool isPalindrome(const unordered_map<int, int> &path) {
        int oddFreq = 0;

        for (auto p : path) {
            if (p.second & 1) {
                oddFreq++;
            }
        }
        
        return oddFreq <= 1;
    }
    void calculatePseudoPalindromicPaths(int &ans, unordered_map<int, int> &path, TreeNode *root) {
        path[root->val]++;
        
        if (root->left) {
            calculatePseudoPalindromicPaths(ans, path, root->left);
        }

        if (root->right) {
            calculatePseudoPalindromicPaths(ans, path, root->right);
        }

        if (!root->left && !root->right) {
            if (isPalindrome(path)) {
                ans++;
            }
        }
        
        path[root->val]--;
       
        if (path[root->val] == 0) {
            path.erase(root->val);
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        unordered_map<int, int> path;

        calculatePseudoPalindromicPaths(ans, path, root);

        return ans;
    }
};