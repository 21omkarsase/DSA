// AVL Tree Deletion
// HardAccuracy: 47.98%Submissions: 36K+Points: 8
// Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 

// Given an AVL tree and N values to be deleted from the tree. Write a function to delete a given value from the tree. All the N values which needs to be deleted are passed one by one as input data by driver code itself, you are asked to return the root of modified tree after deleting the value.

// Example 1:

// Tree = 
//         4
//       /   \
//      2     6
//     / \   / \  
//    1   3 5   7

// N = 4
// Values to be deleted = {4,1,3,6}

// Input: Value to be deleted = 4
// Output:
//         5    
//       /   \
//      2     6
//     / \     \  
//    1   3     7

// Input: Value to be deleted = 1
// Output:
//         5    
//       /   \
//      2     6
//       \     \  
//        3     7

// Input: Value to be deleted = 3
// Output:
//         5    
//       /   \
//      2     6
//             \  
//              7

// Input: Value to be deleted = 6
// Output:
//         5    
//       /   \
//      2     7

// Your Task:  
// You dont need to read input or print anything. Complete the function delelteNode() which takes the root of the tree and the value of the node to be deleted as input parameters and returns the root of the modified tree.

// Note: The tree will be checked after each deletion. 
// If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
// If instead all deletion are successful, inorder traversal of tree will be printed.
// If every single node is deleted from tree, 'null' will be printed.

// Expected Time Complexity: O(height of tree)
// Expected Auxiliary Space: O(height of tree)

// Constraints:
// 1 ≤ N ≤ 500


int height(Node* node) {
    if (node == nullptr)
        return 0;
    return max(height(node->left), height(node->right)) + 1;
}
    
Node *leftRotate(Node *node) {
    Node *child = node->right;
    
    node->right = child->left;
    child->left = node;

    node->height = height(node);
    child->height = height(child);

    return child;
}

Node *rightRotate(Node *node) {
    Node *child = node->left;
    
    node->left = child->right;
    child->right = node;

    node->height = height(node);
    child->height = height(child);

    return child;
}

Node *rotate(Node *node) {
    if (node == nullptr) {
        return node;
    }
    
    if (height(node->left) - height(node->right) > 1) {
        if (height(node->left->left) - height(node->left->right) >= 0) {
            return rightRotate(node);
        }
        else if(height(node->left->right) - height(node->left->left) > 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (height(node->right) - height(node->left) > 1) {
        if (height(node->right->right) - height(node->right->left) >= 0) {
            return leftRotate(node);
        }
        else if (height(node->right->left) - height(node->right->right) > 0){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

Node* deleteNode(Node* root, int data) {
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            if (root->left) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        } else {
            Node* temp = root->right;
            while (temp->left != nullptr)
                temp = temp->left;

            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return rotate(root);
}
