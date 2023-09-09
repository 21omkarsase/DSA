// Binary Tree to BST
// EasyAccuracy: 60.75%Submissions: 59K+Points: 2

// Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
//  Example 1:

// Input:
//       1
//     /   \
//    2     3
// Output: 
// 1 2 3
// Explanation:
// The converted BST will be 
//       2
//     /   \
//    1     3


// Example 2:

// Input:
//           1
//        /    \
//      2       3
//    /        
//  4       
// Output: 
// 1 2 3 4
// Explanation:
// The converted BST will be

//         3
//       /   \
//     2     4
//   /
//  1

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.

// Expected Time Complexity: O(NLogN).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= Number of nodes <= 105

// Time Complexity : O(N*LogN)
// Space Complexity : O(N)

class Solution {
    Node* generateBST(int &idx, Node *node, const vector<int> &nodeValues) {
        if (!node) {
            return node;
        }
        
        Node* newNode = new Node(-1);
        
        newNode->left = generateBST(idx, node->left, nodeValues);

        newNode->data = nodeValues[idx];
        idx++;
        
        newNode->right = generateBST(idx, node->right, nodeValues);
        
        return newNode;
    }
    
    void storeNodeValues(Node *node, vector<int> &nodeValues) {
        if (!node) {
            return;
        }
        
        storeNodeValues(node->left, nodeValues);
        
        nodeValues.push_back(node->data);
        
        storeNodeValues(node->right, nodeValues);
    }
  public:
    Node *binaryTreeToBST (Node *root) {
        vector<int> nodeValues;
        
        storeNodeValues(root, nodeValues);
        
        int idx = 0;
        sort(nodeValues.begin(), nodeValues.end());
        
        return generateBST(idx, root, nodeValues);
    }
};