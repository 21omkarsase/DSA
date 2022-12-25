// Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

// Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
//        10                       10 ------> NULL
//       / \                       /      \
//      3   5       =>     3 ------> 5 --------> NULL
//     / \     \               /  \           \
//    4   1   2          4 --> 1 -----> 2 -------> NULL

//  

// Example 1:

// Input:
//      3
//    /  \
//   1    2
// Output:
// 3 1 2
// 1 3 2
// Explanation:The connected tree is
//         3 ------> NULL
//      /    \
//     1-----> 2 ------ NULL

// Example 2:

// Input:
//       10
//     /   \
//    20   30
//   /  \
//  40  60
// Output:
// 10 20 30 40 60
// 40 20 60 10 30
// Explanation:The connected tree is
//          10 ----------> NULL
//        /     \
//      20 ------> 30 -------> NULL
//   /    \
//  40 ----> 60 ----------> NULL

// Your Task:
// You don't have to take input. Complete the function connect() that takes root as parameter and connects the nodes at same level. The printing is done by the driver code. First line of the output will be level order traversal and second line will be inorder travsersal

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 0 ≤ Data of a node ≤ 105

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;
    
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

void connect(struct Node *p);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */


void printSpecial(Node *root)
{
   if (root == NULL)
     return;

   Node* next_root=NULL;

   while (root != NULL)
   {
      cout<< root->data<<" ";

      if( root->left && (!next_root) )
        next_root = root->left;
      else if( root->right && (!next_root)  )
        next_root = root->right;

      root = root->nextRight;
   }
   
   printSpecial(next_root);
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// } Driver Code Ends
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        queue<pair<Node*,int>>q;
        map<Node*,int>m;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            Node*node=q.front().first;
            int line=q.front().second;
            if(node->left)q.push({node->left,line-1});
            if(node->right)q.push({node->right,line-1});
            q.pop();
            for(int i=0;i<size-1;i++){
                node->nextRight=q.front().first;
                line=q.front().second;
                node=q.front().first;
                if(node->left)q.push({node->left,line-1});
                if(node->right)q.push({node->right,line-1});
                q.pop();
            }
            node->nextRight=NULL;
        }   
    }    
      
};




//{ Driver Code Starts.


/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     string s;
     getline(cin, s);
     Node* root = buildTree(s);
        
    Solution obj;
     obj.connect(root);
     printSpecial(root);
     cout<<endl;
     inorder(root);
     cout<<endl;
  }
  return 0;
}

// } Driver Code Ends