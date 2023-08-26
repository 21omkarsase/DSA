// Lowest Common Ancestor in a BST
// EasyAccuracy: 65.2%Submissions: 119K+Points: 2
// POTD July Placement Special : All POTD in the month of July are based on popular interview questions. Solve every day to ace the upcoming Placement Season !

// Given a Binary Search Tree (with all values unique) and two node values n1 and n2 (n1!=n2). Find the Lowest Common Ancestors of the two nodes in the BST.

// Example 1:

// Input:
//               5
//             /   \
//           4      6
//          /        \
//         3          7
//                     \
//                      8
// n1 = 7, n2 = 8
// Output: 7

// Example 2:

// Input:
//      2
//    /   \
//   1     3
// n1 = 1, n2 = 3
// Output: 2

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function LCA() which takes the root Node of the BST and two integer values n1 and n2 as inputs and returns the Lowest Common Ancestor of the Nodes with values n1 and n2 in the given BST. 

// Expected Time Complexity: O(Height of the BST).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 <= N <= 104


// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution{
    Node* getAncestor(Node *root, int n1, int n2) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (root->data == n1 || root->data == n2) {
            return root;
        }
        
        Node *left = getAncestor(root->left, n1, n2);
        Node *right = getAncestor(root->right, n1, n2);
        
        if (left != nullptr && right != nullptr &&
            ((left->data == n1 && right->data == n2) || 
             (left->data == n2 && right->data == n1))) {
            return root;
        }
        
        if (left) {
            return left;
        }
        else if (right) {
            return right;
        }
        
        return nullptr;
    }
public:
    Node* LCA(Node *root, int n1, int n2) {
        return getAncestor(root, n1, n2);
    }
};