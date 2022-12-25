// Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.


//  
//  

// Example 1:

// Input:
//       1
//     /   \
//    3     2
// Output:1 3 2

// Example 2:

// Input:
//            10
//          /     \
//         20     30
//       /    \
//     40     60
// Output: 10 20 30 60 40 

// Your Task:
// The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 0 <= Number of nodes <= 105
// 0 <= Data of a node <= 105


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

vector<int> findSpiral(Node *root);

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

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends

int getHeight(Node* node){
if(!node)return 0;
    return max(getHeight(node->left),getHeight(node->right))+1;
}

void getSpiralOrderTraversal(Node* node, vector<vector<int>>&ans,int level){
    if(!node)return;
    ans[level].push_back(node->data);
    if(node->left)getSpiralOrderTraversal(node->left,ans,level+1);
    if(node->right)getSpiralOrderTraversal(node->right,ans,level+1);
}

//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *node)
{
    int height=getHeight(node);
    vector<int>final;
    vector<vector<int>>ans(height);
    getSpiralOrderTraversal(node,ans,0);
    
    
    int flag=false;
    for(int j=0;j<ans.size();j++){
        if(flag){
            for(int i=0;i<ans[j].size();i++){
               final.push_back(ans[j][i]);
            }
            flag=false;
        }else{
             for(int i=ans[j].size()-1;i>=0;i--){
               final.push_back(ans[j][i]);
            }
            flag=true;
        }
    }
    
    return final;
}

// ******************or****************

// vector<int> findSpiral(Node *root)
// {
//     vector<int>ans;
//     if(!root)return ans;
//     queue<Node*>temp;
//     temp.push(root);
//     bool rToL=false;
//     while(!temp.empty()){
//         int size=temp.size();
//         vector<int>v(size);
//         for(int i=0;i<size;i++){
//             Node *curr=temp.front();
//             temp.pop();
//             int idx=rToL?i:size-i-1;
//             v[idx]=curr->data;
//             if(curr->left)temp.push(curr->left);
//             if(curr->right)temp.push(curr->right);
//         }
//         for(int i=0;i<size;i++){
//             ans.push_back(v[i]);
//         }
        
//         rToL=!rToL;
//     }
    
//     return ans;  
    
// }
