// 297. Serialize and Deserialize Binary Tree
// Hard
// 8.8K
// 322
// Companies

// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

// Example 1:

// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]

// Example 2:

// Input: root = []
// Output: []

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 104].
//     -1000 <= Node.val <= 1000

// Accepted
// 745K
// Submissions
// 1.3M
// Acceptance Rate
// 55.5%


// *********************using level order and queue*******************
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        queue<TreeNode*> q;
        q.push(root);
        
        string s = "";
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();

            if(!node) {
                s += "#,";
                continue;
            }
            
            s += (to_string(node->val) + ",");
            q.push(node->left);
            q.push(node->right);
        }
        return s;
    }

    string getStringValue(string data, int &i, int n){
        string temp = "";
        while(data[i] != ',' && i < n){
            temp += data[i++];
        }
        i++;
        return temp;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        int i = 0;
        string temp = getStringValue(data, i, data.size());
        
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(stoi(temp));
        q.push(root);

        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();

            string left = getStringValue(data, i, data.size());

            if(left == "#"){
                node->left = nullptr;
            }else if(left != ""){
                node->left = new TreeNode(stoi(left));
                q.push(node->left);
            }
            string right = getStringValue(data, i, data.size());

            if(right == "#"){
                node->right = nullptr;
            }else if(right != ""){
                node->right = new TreeNode(stoi(right));
                q.push(node->right);
            }
        }
        return root;
    }
};

// ****************************using pre-order***************************
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void getSerializedString(TreeNode *root, string &data){
        if(!root){
            data += "#,";
            return;
        }

        getSerializedString(root->left, data);
        getSerializedString(root->right, data);
        data += (to_string(root->val) + ",");
    }
public:
    string serialize(TreeNode* root) {
        string data = "";
        getSerializedString(root, data);

        return data;
    }

    string getStringValue(string &data, int &i, int n){
        string temp = "";
        while(data[i] != ',' && i < n){
            temp += data[i++];
        }
        i++;
        return temp;
    }

    TreeNode* buildTree(queue<string> &q){
        string temp = q.front();
        if(temp == "#" || temp == "")
            return nullptr;
        
        TreeNode *node = new TreeNode(stoi(temp));
        node->left = buildTree(q);
        node->right = buildTree(q);
        q.pop();

        return node;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;

        queue<string> q;
        int i = 0;
        while(i < data.size() - 1){
            q.push(getStringValue(data, i, data.size()));
        }

        return buildTree(q);
    }
};







 