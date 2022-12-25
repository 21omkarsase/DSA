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
// Diagonal Traversal of Binary Tree
// MediumAccuracy: 60.63%Submissions: 57K+Points: 4
// Lamp
// Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

// Given a Binary Tree, print the diagonal traversal of the binary tree.

// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

// Example 1:

// Input :
//             8
//          /     \
//         3      10
//       /   \      \
//      1     6     14
//          /   \   /
//         4     7 13
// Output : 8 10 14 3 6 7 13 1 4
// Explanation:
// unnamed
// Diagonal Traversal of binary tree : 
//  8 10 14 3 6 7 13 1 4

// Your Task:
// You don't need to read input or print anything. The task is to complete the function diagonal() that takes the root node as input argumets and returns the diagonal traversal of the given tree.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
// Here N is number of nodes.

// Constraints:
// 1 <= Number of nodes<= 105
// 1 <= Data of a node<= 105
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


vector<int> diagonal(Node *root);

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
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
    
    // ********************Wasted*************************
    // vector<int>v;
    // queue<pair<Node*,int>>q;
    // q.push({root,0});
    // map<int,vector<int>>m;
    // vector<int>vm={root->data};
    // m[0]=vm;
    // bool flag=false;
    // int target=0;
    // while(!q.empty()){
    //     Node* node=q.front().first;
    //     int line=q.front().second;
    //     if(line==target){
    //         int s=m[target].size();
    //         if(flag)v.push_back(m[target][0]);
    //         else v.push_back(m[target][s-1]);
    //         vm=m[target];
    //         if(flag)vm.erase(vm.begin()+0);
    //         else vm.pop_back();
    //         flag=!flag;
    //         m[target]=vm;
    //         if(node->left){
    //             m[line-1].push_back(node->left->data);
    //             q.push({node->left,line-1});
    //         }
    //         if(node->right){
    //             m[line+1].push_back(node->right->data);
    //             q.push({node->right,line+1});
    //         }
    //         q.pop();
    //         target++;
    //     }else{
    //         if(m.find(target)!=m.end() && m[target].size()>0){
    //             q.pop();
    //             q.push({node,line});   
    //         }else{
    //             target=q.front().second;
    //         }
    //     }
    // }
    // return v;
    
    // ****************Answer**********************
    
    vector<int>v;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        while(curr){
            if(curr->left)q.push(curr->left);
            v.push_back(curr->data);
            curr=curr->right;
        }
    }
    
    return v;
    
}