// 2096. Step-By-Step Directions From a Binary Tree Node to Another
// Solved
// Medium
// Topics
// Companies
// Hint

// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

//     'L' means to go from a node to its left child node.
//     'R' means to go from a node to its right child node.
//     'U' means to go from a node to its parent node.

// Return the step-by-step directions of the shortest path from node s to node t.

 

// Example 1:

// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

// Example 2:

// Input: root = [2,1], startValue = 2, destValue = 1
// Output: "L"
// Explanation: The shortest path is: 2 → 1.

 

// Constraints:

//     The number of nodes in the tree is n.
//     2 <= n <= 105
//     1 <= Node.val <= n
//     All the values in the tree are unique.
//     1 <= startValue, destValue <= n
//     startValue != destValue

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 167.3K
// Submissions
// 306.7K
// Acceptance Rate
// 54.5%

class Solution {
    void getNodeFromVal(int &val, TreeNode *&cur, TreeNode *&node, unordered_map<int, TreeNode*> &parentMapping) {
        if (val == cur->val) {
            node = cur;
        }

        if (cur->left) {
            parentMapping[cur->left->val] = cur;
            getNodeFromVal(val, cur->left, node, parentMapping);
        }

        if (cur->right) {
            parentMapping[cur->right->val] = cur;
            getNodeFromVal(val, cur->right, node, parentMapping);
        }

    }

    void findShortestPathString(TreeNode *&node, int &destValue, unordered_map<int, TreeNode*> &parentMapping, int distance, string &ansString, string &curString, unordered_set<int> &visited) {
        if (!node) {
            return;
        }

        if (node->val == destValue) {
            if (ansString.size() - 1 > distance) {
                ansString = curString;
            }

            visited.insert(node->val);

            return;
        }

        if (visited.find(node->val) != visited.end()) {
            return;
        }

        visited.insert(node->val);

        curString += 'L';
        findShortestPathString(node->left, destValue, parentMapping, distance + 1, ansString, curString, visited);
        curString.pop_back();

        curString += 'R';
        findShortestPathString(node->right, destValue, parentMapping, distance + 1, ansString, curString, visited);
        curString.pop_back();
        
        curString += 'U';
        findShortestPathString(parentMapping[node->val], destValue, parentMapping, distance + 1, ansString, curString, visited);
        curString.pop_back();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *srcNode = nullptr;
        unordered_map<int, TreeNode*> parentMapping;
        parentMapping[root->val] = nullptr;

        getNodeFromVal(startValue, root, srcNode, parentMapping);

        unordered_set<int> visited;

        int distance = 0;
        string ansString = "", curString = "";

        findShortestPathString(srcNode, destValue, parentMapping, distance, ansString, curString, visited);

        return ansString;
    }
};