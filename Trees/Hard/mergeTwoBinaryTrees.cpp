// Merge two BST 's
// HardAccuracy: 64.95%Submissions: 37K+Points: 8
// Lamp
// Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

// Given two BSTs, return elements of both BSTs in sorted form.


// Example 1:

// Input:
// BST1:
//        5
//      /   \
//     3     6
//    / \
//   2   4  
// BST2:
//         2
//       /   \
//      1     3
//             \
//              7
//             /
//            6
// Output: 1 2 2 3 3 4 5 6 6 7
// Explanation: 
// After merging and sorting the
// two BST we get 1 2 2 3 3 4 5 6 6 7.

// Example 2:

// Input:
// BST1:
//        12
//      /   
//     9
//    / \    
//   6   11
// BST2:
//       8
//     /  \
//    5    10
//   /
//  2
// Output: 2 5 6 8 9 10 11 12
// Explanation: 
// After merging and sorting the
// two BST we get 2 5 6 8 9 10 11 12.


// Your Task:
// You don't need to read input or print anything. Your task is to complete the function merge() which takes roots of both the BSTs as its input and returns an array of integers denoting the node values of both the BSTs in a sorted order.


// Expected Time Complexity: O(M+N) where M and N are the sizes if the two BSTs.
// Expected Auxiliary Space: O(Height of BST1 + Height of BST2).


// Constraints:
// 1 ≤ Number of Nodes ≤ 105


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
   Node* root = new Node(stoi(ip[0]));

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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    void getNodes(Node* root,vector<int>&v){
        if(!root)return;
        getNodes(root->left,v);
        v.push_back(root->data);
        getNodes(root->right,v);
    }
    // vector<int> merge(Node *root1, Node *root2)
    // {
    //     vector<int>v;
    //     getNodes(root1,v);
    //     getNodes(root2,v);
    //     sort(v.begin(),v.end());
    //     return v;
    // }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int>v1,v2;
        getNodes(root1,v1);
        getNodes(root2,v2);
        vector<int>v;
        int i=0,j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<v2[j])v.push_back(v1[i]),i++;
            else v.push_back(v2[j]),j++;
        }
        while(i<v1.size())v.push_back(v1[i]),i++;
        while(j<v2.size())v.push_back(v2[j]),j++;
        return v;
    }
    
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends