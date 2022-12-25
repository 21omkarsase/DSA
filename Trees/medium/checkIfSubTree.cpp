// Back to Explore Page

// Boundary Traversal of binary tree

// Diameter of a Binary Tree

// Top View of Binary Tree

// Height of Binary Tree

// Sum Tree

// Bottom View of Binary Tree

// Vertical Traversal of Binary Tree

// Lowest Common Ancestor in a Binary Tree

// Check if subtree

// Construct Tree from Inorder & Preorder

// Connect Nodes at Same Level

// Largest BST

// Min distance between two given nodes of a Binary Tree

// Count BST nodes that lie in a given range

// Diagonal Traversal of Binary Tree

// Predecessor and Successor

// Maximum difference between node and its ancestor

// Preorder to BST

// Serialize and Deserialize a Binary Tree

// Find the Closest Element in BST
// Check if subtree
// MediumAccuracy: 24.34%Submissions: 113K+Points: 4
// Lamp
// Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

// Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
// A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

// Example 1:

// Input:
// T:      1          S:   3
//       /   \            /
//      2     3          4
//    /  \    /
//   N    N  4
// Output: 1 
// Explanation: S is present in T

// Example 2:

// Input:
// T:      26         S:   26
//        /   \           /  \
//      10     N        10    N
//    /    \           /  \
//    20    30        20  30
//   /  \            /  \
//  40   60         40  60
// Output: 1 
// Explanation: 
// S and T are both same. Hence, 
// it can be said that S is a subtree 
// of T.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isSubtree() that takes root node of S and T as parameters and returns 1 if S is a subtree of T else 0.

// Note: The nodes can have the duplicate values.


// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= Number of nodes <= 105
// 1 <= Value of nodes <= 104


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
  public:
    // void isNodePresent(Node* parent,Node* child,vector<pair<Node*,Node*>>&v){
    //     if(!parent)return;
    //     if(parent->data==child->data){
    //         v.push_back({parent,child});
    //     }
    //     isNodePresent(parent->left,child,v);
    //     isNodePresent(parent->right,child,v);
    // }
    bool isItSubtree(Node* parent,Node* child){
        if(!parent and !child)return true;
        if(!parent || !child || parent->data!=child->data)return false;
        bool flag1=isItSubtree(parent->left,child->left);
        bool flag2=isItSubtree(parent->right,child->right);
        return (flag1 && flag2);
    }
    // bool isSubTree(Node* T, Node* S) 
    // {
    //   vector<pair<Node*,Node*>>v;
    //   isNodePresent(T,S,v);
    //   for(int i=0;i<v.size();i++){
    //       Node* test=v[i].first;
    //       for(int j=0;j<v.size();j++)
    //           if(isItSubtree(test,v[j].second))return true;
    //   }
    //   return false; 
    // }
    bool isSubTree(Node* T, Node* S) 
    {
        if(!S)return true;
        if(!T)return false;
        if(isItSubtree(T,S))return true;
        
        return isSubTree(T->left,S) || isSubTree(T->right,S);
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";

    }
    return 0;
}
// } Driver Code Ends