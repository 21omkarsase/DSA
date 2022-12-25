// Maximum Path Sum between 2 Leaf Nodes
// HardAccuracy: 18.39%Submissions: 157K+Points: 8
// Lamp
// Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

// Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node to another leaf node.

// Note: Here Leaf node is a node which is connected to exactly one different node.


// Example 1:

// Input:      
//            3                               
//          /    \                          
//        4       5                     
//       /  \      
//     -10   4                          
// Output: 16
// Explanation:
// Maximum Sum lies between leaf node 4 and 5.
// 4 + 4 + 3 + 5 = 16.

// Example 2:

// Input:    
//             -15                               
//          /      \                          
//         5         6                      
//       /  \       / \
//     -8    1     3   9
//    /  \              \
//   2   -3              0
//                      / \
//                     4  -1
//                        /
//                      10  
// Output:  27
// Explanation:
// The maximum possible sum from one leaf node 
// to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)


// Your Task:  
// You dont need to read input or print anything. Complete the function maxPathSum() which takes root node as input parameter and returns the maximum sum between 2 leaf nodes.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(Height of Tree)


// Constraints:
// 2  ≤  Number of nodes  ≤  104
// -103  ≤ Value of each node ≤ 103
// View Bookmarked Problems 

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
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
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

class Solution {
public:
    int findMaxSum(Node* node,int &maxSum){
        if(!node)return INT_MIN;
        
        int left=findMaxSum(node->left,maxSum);
        int right=findMaxSum(node->right,maxSum);
        
        if(left!=INT_MIN && right!=INT_MIN)
            maxSum=max(maxSum,left+right+node->data);

        if(left==INT_MIN && right==INT_MIN)
            return node->data;
        else if(left==INT_MIN && right!=INT_MIN)
            return node->data+right;
        else if(left!=INT_MIN && right==INT_MIN)
            return node->data+left;
        else return node->data+max(left,right);
            
    }
    int maxPathSum(Node* root)
    {
        int maxSum=INT_MIN;
        int sum=findMaxSum(root,maxSum);
        if(!root->left || !root->right)
            return max(sum,maxSum);
        return maxSum;
    }
    
    
    
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends