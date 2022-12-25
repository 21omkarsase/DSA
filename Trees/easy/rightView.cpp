// Back to Explore Page

// Check for BST

// Left View of Binary Tree

// Check for Balanced Tree

// Determine if Two Trees are Identical

// Level order traversal in spiral form

// Mirror Tree

// Level order traversal

// Print all nodes that don't have sibling

// Right View of Binary Tree

// Lowest Common Ancestor in a BST

// ZigZag Tree Traversal

// Reverse Level Order Traversal

// Symmetric Tree

// Kth largest element in BST

// Root to leaf path sum

// K distance from root

// Level order traversal Line by Line

// Leaf at same level

// Children Sum Parent

// Transform to Sum Tree
// Right View of Binary Tree
// EasyAccuracy: 65.18%Submissions: 107K+Points: 2

// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

// Right view of following tree is 1 3 7 8.

//           1
//        /     \
//      2        3
//    /   \      /    \
//   4     5   6    7
//     \
//      8

// Example 1:

// Input:
//        1
//     /    \
//    3      2
// Output: 1 2

// Example 2:

// Input:
//      10
//     /   \
//   20     30
//  /   \
// 40  60 
// Output: 10 30 60

// Your Task:
// Just complete the function rightView() that takes node as parameter and returns the right view as a list. 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 105
// View Bookmarked Problems 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    void getRightView(Node* node,vector<int>&ans,int level){
        if(!node)return;
        
        if(level==ans.size())ans.push_back(node->data);
        getRightView(node->right,ans,level+1);
        getRightView(node->left,ans,level+1);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
    //   vector<int>ans;
    //   queue<Node*>temp;
    //   temp.push(root);
    //   while(!temp.empty()){
    //       int size=temp.size();
    //       ans.push_back(temp.back()->data);
    //       for(int i=0;i<size;i++){
    //           Node* curr=temp.front();
    //           temp.pop();
    //           if(curr->left)temp.push(curr->left);
    //           if(curr->right)temp.push(curr->right);
    //       }
    //   }
    //   return ans;
    
         vector<int>ans;
         int level=0;
         getRightView(root,ans,level);
         return ans;
    }
};



//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> vec = ob.rightView(root);
        for(int x : vec){
            cout<<x<<" ";
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends