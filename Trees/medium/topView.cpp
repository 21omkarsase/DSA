// Top View of Binary Tree
// MediumAccuracy: 38.43%Submissions: 182K+Points: 4

// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the extreme ones only(i.e. leftmost and rightmost). 
// For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

// Example 1:

// Input:
//       1
//    /    \
//   2      3
// Output: 2 1 3

// Example 2:

// Input:
//        10
//     /      \
//   20        30
//  /   \    /    \
// 40   60  90    100
// Output: 40 20 10 30 100

// Your Task:
// Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Node Data ≤ 105
//  

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define COUNT 10
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

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.

    // void getTopLeftView(Node* root,vector<int>&ans,int maxLeft,int left){
    //     if(!root)return;
        
    //     if(root->left){
    //         getTopLeftView(root->left,ans,maxLeft,left+1);
    //     }
    //     if(!root->left and root->right){
    //         getTopLeftView(root->right,ans,max(left,maxLeft),left-1);
    //     }
    //     if(left>maxLeft)ans.push_back(root->data);
    // }
    // void getTopRightView(Node* root,vector<int>&ans,int maxRight,int right){
    //     if(!root)return;
        
    //     if(right>maxRight)ans.push_back(root->data);
    //     if(root->right){
    //         getTopRightView(root->right,ans,maxRight,right+1);
    //     }
    //     if(!root->right and root->left){
    //         getTopRightView(root->left,ans,max(right,maxRight),right-1);
    //     }
    // }
    // vector<int> topView(Node *root)
    // {
    //     vector<int>ans;
    //     getTopLeftView(root->left,ans,0,1);
    //     ans.push_back(root->data);
    //     getTopRightView(root->right,ans,0,1);
    //     print2DUtil(root, 0);
    //     return ans;
    // }


    // **************************correct ans********************
    vector<int> topView(Node *root)
    {
        
        vector<int>final;
        queue<pair<Node*,int>>q;
        map<int,Node*>m;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* curr=q.front().first;
                int line=q.front().second;
                if(m.find(line)==m.end())m[line]=curr;
                if(curr->left)q.push({curr->left,line-1});
                if(curr->right)q.push({curr->right,line+1});
                q.pop();
            }
        }
        for(auto e:m){
            final.push_back(e.second->data);
        }
        return final;
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends