// Back to Explore Page

// Tilt of Binary Tree

// Maximum GCD of siblings of a binary tree

// Height of Spiral Tree

// K-Ary Tree

// Exchange the Leaf Nodes

// XOR of a given range

// Postorder traversal from given Inorder and Preorder traversals

// Leaf under budget

// Depth of node

// Shortest distance in infinite tree

// pth common ancestor in BST

// Maximum Depth Of Binary Tree
// Exchange the Leaf Nodes
// EasyAccuracy: 31.19%Submissions: 8K+Points: 2

// Given a binary tree of size N, your task is to complete the function pairwiseSwap(), that swap leaf nodes in the given binary tree pairwise starting from from left to right.
// Example 1:

// Input: 


// Output: 7 2 1 4 5 9 3 8 6 10 

// Explanation:
// The sequence of leaf nodes in original binary tree
// from left to right is (4, 7, 8, 9, 10). Now if we 
// try to form pairs from this sequence, we will have 
// two pairs as (4, 7), (8, 9). The last node (10) is 
// unable to form pair with any node and thus left unswapped

//  

// Example 2:

// Input: 
//           1
//        /     \
//       2       3
//        \    /    \
//         5  6      7
// Output: 2 6 1 5 3 7
//         1
//      /     \
//     2       3
//      \    /   \
//       6  5     7

//  

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function pairwiseSwap() which takes root node of the tree as input parameter.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=N<=103
// 1<=Data of a node <=103


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
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
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
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
        if (currVal != "N")
        {

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
//User function Template for C++
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    void getLeafValues(Node* root,vector<int>&v){
        if(!root->left and !root->right)v.push_back(root->data);
        
        if(root->left)getLeafValues(root->left,v);
        if(root->right)getLeafValues(root->right,v);
    }
    void swapLeafValues(Node* root,vector<int>&v){
        if(!root)return;
        if(!root->left and !root->right){
            root->data=v[0];
            v.erase(v.begin());
        }
        
        if(root->left)swapLeafValues(root->left,v);
        if(root->right)swapLeafValues(root->right,v);
    }
    void pairwiseSwap(Node *root)
    {
        vector<int>leafValues;
        getLeafValues(root,leafValues);
        
        for(int i=0;i<leafValues.size();i+=2){
            if(i+1<leafValues.size()){
                swap(leafValues[i],leafValues[i+1]);
            }
        }
        
        swapLeafValues(root,leafValues);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        obj.pairwiseSwap(root);
        printInorder(root);
        if (treeString.size() != 0)
            cout << "\n";
    }
    return 0;
}
// } Driver Code Ends