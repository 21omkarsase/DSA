// Lowest Common Ancestor in a Binary Tree
// MediumAccuracy: 52.85%Submissions: 126K+Points: 4

// Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

// LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

// Example 1:

// Input:
// n1 = 2 , n2 = 3  
//        1 
//       / \ 
//      2   3
// Output: 1
// Explanation:
// LCA of 2 and 3 is 1.

// Example 2:

// Input:
// n1 = 3 , n2 = 4
//            5    
//           /    
//          2  
//         / \  
//        3   4
// Output: 2
// Explanation:
// LCA of 3 and 4 is 2. 

// Your Task:
// You don't have to read, input, or print anything. Your task is to complete the function lca() that takes nodes, n1, and n2 as parameters and returns the LCA node as output. 

// Expected Time Complexity:O(N).
// Expected Auxiliary Space:O(Height of Tree).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 105

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

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
    // int getLowestComman(Node* node,int n1,int n2,int&ans,Node* &firstNode){
    //     if(!node)return -1;
        
    //     if(node->data==n1 or node->data==n2){
    //         if(firstNode==NULL)firstNode=node;
    //         return node->data;
    //     }
        
    //     int a=getLowestComman(node->left,n1,n2,ans,firstNode);
    //     int b=getLowestComman(node->right,n1,n2,ans,firstNode);
        
    //     if((a==n1 and b==n2) or (a==n2 and b==n1))ans=node->data;
    //     if(a==n1 or a==n2)return a;
    //     else if(b==n2 or b==n1)return b;
    //     else return -1; 
    // }
    // void findNode(Node* root,int num,Node* &ans){
    //     if(!root)return;
    //     if(root->data==num)ans=root;
        
    //     findNode(root->left,num,ans);
    //     findNode(root->right,num,ans);
    // }
    // void bothPresentOrNot(Node* node,int n1,int n2,bool &flag){
    //     if(!node)return;
    //     if(node->data==n1 or node->data==n2)flag=true;
        
    //     bothPresentOrNot(node->left,n1,n2,flag);
    //     bothPresentOrNot(node->right,n1,n2,flag);
    // }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        // Node * node,* fact=NULL;
        // int ans=-1;
        // getLowestComman(root,n1,n2,ans,fact);
        // if(ans==-1 and fact!=NULL){
        //     bool flag=false; 
        //     bothPresentOrNot(fact->left,n1,n2,flag);
        //     bothPresentOrNot(fact->right,n1,n2,flag);
        //     if(flag) return fact;
        // }
        // findNode(root,ans,node);
        // return node;
        
        // **************************or****************************
        if(!root || root->data==n1 || root->data==n2)return root;
        
        Node* left=lca(root->left,n1,n2);
        Node* right=lca(root->right,n1,n2);
        
        if(left && right)return root;
        
        if(left)return left;
        else return right;
    }
};

//{ Driver Code Starts.

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
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}

// } Driver Code Ends