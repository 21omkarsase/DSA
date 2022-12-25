// Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

// Example 1:

// Input:
// N = 4
// inorder[] = {1 6 8 7}
// preorder[] = {1 6 7 8}
// Output: 8 7 6 1

// Example 2:

// Input:
// N = 6
// inorder[] = {3 1 4 0 5 2}
// preorder[] = {0 1 3 4 2 5}
// Output: 3 4 1 5 2 0
// Explanation: The tree will look like
//        0
//     /     \
//    1       2
//  /   \    /
// 3    4   5

// Your Task:
// Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

// Expected Time Complexity: O(N*N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1<=Number of Nodes<=1000


//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
       int data;
       struct Node *left;
       struct Node *right;
       
       Node(int x){
           data = x;
           left = NULL;
           right = NULL;
       }
};


void printPostOrder(Node *root)
{
       if(root==NULL)
              return;
       printPostOrder(root->left);
       printPostOrder(root->right);
       cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildNewTree(int in[],int inStart,int inEnd,int pre[],int preStart,int preEnd,unordered_map<int,int>&m){
        if(inStart>inEnd || preStart>preEnd)return NULL;
        
        Node* root=new Node(pre[preStart]);
        
        int inRoot=m[root->data];
        int leftCnt=inRoot-inStart;
        
        root->left=buildNewTree(in,inStart,inRoot-1,pre,preStart+1,preStart+leftCnt,m);
        root->right=buildNewTree(in,inRoot+1,inEnd,pre,preStart+leftCnt+1,preEnd,m);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)m[in[i]]=i;
        return buildNewTree(in,0,n-1,pre,0,n-1,m);
    }
};

//{ Driver Code Starts.
int main()
{
       int t;
       cin>>t;
       while(t--)
       {
              int n;
              cin>>n;
              
              int inorder[n], preorder[n];
              for(int i=0; i<n; i++)
                     cin>> inorder[i];
              for(int i=0; i<n; i++)
                     cin>> preorder[i];
              Solution obj;
              Node *root = obj.buildTree(inorder, preorder, n);
              printPostOrder(root);
              cout<< endl;
       }
}

// } Driver Code Ends