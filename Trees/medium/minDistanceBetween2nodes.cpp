// Min distance between two given nodes of a Binary Tree
// MediumAccuracy: 39.13%Submissions: 75K+Points: 4
// Lamp
// Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

// Given a binary tree and two node values your task is to find the minimum distance between them.
// The given two nodes are guaranteed to be in the binary tree and nodes are numbered from 1 to N.
// Please Note that a and b are not always leaf node.

// Example 1:

// Input:
//         1
//       /  \
//      2    3
// a = 2, b = 3
// Output: 2
// Explanation: The tree formed is:
//        1
//      /   \ 
//     2     3
// We need the distance between 2 and 3.
// Being at node 2, we need to take two
// steps ahead in order to reach node 3.
// The path followed will be:
// 2 -> 1 -> 3. Hence, the result is 2. 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the Tree and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 <= Number of nodes <= 104
// 1 <= Data of a node <= 105

//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int distance(Node* node,int a,int b,int& xdist,int& ydist,int &ans){
        if(!node)return -1;
        
        if(node->data==a || node->data==b)return node->data;
        
        int data1=distance(node->left,a,b,xdist,ydist,ans);
        int data2=distance(node->right,a,b,xdist,ydist,ans);
        
        if(data1!=-1 && data2!=-1){
            ans=xdist+ydist+1;  
            return -1;
        }
        else if(data1!=-1){
            xdist++;
            return a;
        }
        else if(data2!=-1){
            ydist++;
            return b;
        }
        else return -1;
    }
    void rootDistance(Node* node,int x,int &n,int dist){

        if(node->data==x){
            n=dist;
        }
        
        if(node->left)rootDistance(node->left,x,n,dist+1);
        if(node->right)rootDistance(node->right,x,n,dist+1);
        
    }
    int findDist(Node* root, int a, int b) {
        int ans=0,xdist=0,ydist=0;
        distance(root,a,b,xdist,ydist,ans);
        if(ans!=0)return ans+1;
        int x1=0,x2=0;
        rootDistance(root,a,x1,0);
        rootDistance(root,b,x2,0);
        return x1>x2?(x1-x2):(x2-x1);
    }
    
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends