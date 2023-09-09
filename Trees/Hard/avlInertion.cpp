// AVL Tree Insertion
// HardAccuracy: 37.01%Submissions: 14K+Points: 8
// Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 

// Given a AVL tree and N values to be inserted in the tree. Write a function to insert a given value into the tree.

// Example 1:

// N = 3
// Values to be inserted = {5,1,4}

// Input:      
// Value to be inserted = 5
// Output:
//     5

// Input :      
// Value to be inserted = 1
// Output:
//     5
//    /
//   1

// Input :      
// Value to be inserted = 4
// Output:
//   5                     4
//  /   LR rotation       / \
// 1   ----------->      1   5
//  \
//  4


// Your Task:  
// You dont need to read input or print anything. Complete the function insertToAVL() which takes the root of the tree and the value of the node to be inserted as input parameters and returns the root of the modified tree.

// Note:
// The tree will be checked after each insertion. 
// If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
// If instead all insertions are successful, inorder traversal of tree will be printed.


// Expected Time Complexity: O(log N)
// Expected Auxiliary Space: O(height of tree)


// Constraints:
// 1 ≤ N ≤ 500



class Solution{
    int height(Node* node) {
        if (!node) {
            return 0;
        }
        
        return max(height(node->left), height(node->right)) + 1;
    }
    
    Node* leftRotate(Node* node) {
        Node* child = node->right;
        
        node->right = child->left;
        child->left = node;
        
        node->height = height(node);
        child->height = height(child);
        
        return child;
    }
    
    Node* rightRotate(Node* node) {
        Node* child = node->left;
        
        node->left = child->right;
        child->right = node;
        
        node->height = height(node);
        child->height = height(child);
        
        return child;
    }
          
    Node* rotate(Node* node) {
        if (height(node->left) - height(node->right) > 1) {
            if (height(node->left->left) - height(node->left->right) > 0) {
                return rightRotate(node);
            }
            else if (height(node->left->right) - height(node->left->left) > 0) {
                node->left = leftRotate(node->left);
                
                return rightRotate(node);
            }
        }
        else if (height(node->right) - height(node->left) > 1) {
            if (height(node->right->right) - height(node->right->left) > 0) {
                return leftRotate(node);
            }
            else if (height(node->right->left) - height(node->right->right) > 0) {
                node->right = rightRotate(node->right);
                
                return leftRotate(node);
            }
        }
        
        return node;
    }
  public:
    Node* insertToAVL(Node* node, int data) {
        if (!node) {
            node = new Node(data);
            
            return node;
        }
        
        if (node->data < data) {
            node->right = insertToAVL(node->right, data);
        }
        else if (node->data > data) {
            node->left = insertToAVL(node->left, data);
        }
        
        return rotate(node);
    }
};