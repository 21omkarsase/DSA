// Inorder Successor in BST
// EasyAccuracy: 34.97%Submissions: 100K+Points: 2
// Share your Interview, Campus or Work Experience to win GFG Swag Kits and much more!

// Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.
 

// Example 1:

// Input:
//       2
//     /   \
//    1     3
// K(data of x) = 2
// Output: 3 
// Explanation: 
// Inorder traversal : 1 2 3 
// Hence, inorder successor of 2 is 3.


// Example 2:

// Input:
//              20
//             /   \
//            8     22
//           / \
//          4   12
//             /  \
//            10   14
// K(data of x) = 8
// Output: 10
// Explanation:
// Inorder traversal: 4 8 10 12 14 20 22
// Hence, successor of 8 is 10.

 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function inOrderSuccessor(). This function takes the root node and the reference node as argument and returns the node that is inOrder successor of the reference node. If there is no successor, return null value.


// Expected Time Complexity: O(Height of the BST).
// Expected Auxiliary Space: O(1).


// Time Complexity : O(H)
// Space Complexity : O(N) + O(N)

class Solution{
    void dfs(Node *root, vector<Node *> &nodes) {
        if (!root) {
            return;
        }
        
        dfs(root->left, nodes);
        
        nodes.push_back(root);
        
        dfs(root->right, nodes);
    }
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        vector<Node *> nodes;
        
        dfs(root, nodes);
        
        for (int idx = 0; idx < nodes.size(); idx++) {
            if (nodes[idx]->data == x->data) {
                if (idx + 1 < nodes.size()) {
                    return nodes[idx + 1];
                }
                
                return nullptr;
            }
        }
    }
};

// Time Complexity : O(N)
// Space Complexity : O(H) (stack call space)

class Solution{
  void inorderTraversal(Node *root, Node *&ans, Node *&x) {
      if (!root) {
          return;
      }
      
      if (root->data > x->data) {
          ans = root;
          inorderTraversal(root->left, ans, x);
      }
      else {
          inorderTraversal(root->right, ans, x);
      }
  }
  public:

    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node *ans = nullptr;
        
        inorderTraversal(root, ans, x);
        
        return ans;
    }
};

// Time Complexity : O(H)
// Space Complexity : O(1)

class Solution{
  public:

    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node *ans = nullptr;
        
        while (root) {
            if (x->data < root->data) {
                ans = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        
        return ans;
    }
};