// Median of BST
// EasyAccuracy: 27.43%Submissions: 49K+Points: 2
// POTD July Placement Special : All POTD in the month of July are based on popular interview questions. Solve every day to ace the upcoming Placement Season !

// Given a Binary Search Tree of size N, find the Median of its Node values.

// Example 1:

// Input:
//        6
//      /   \
//    3      8   
//  /  \    /  \
// 1    4  7    9
// Output: 6
// Explanation: Inorder of Given BST will be:
// 1, 3, 4, 6, 7, 8, 9. So, here median will 6.


// Example 2:

// Input:
//        6
//      /   \
//    3      8   
//  /   \    /   
// 1    4   7   
// Output: 5
// Explanation:Inorder of Given BST will be:
// 1, 3, 4, 6, 7, 8. So, here median will
// (4 + 6)/2 = 10/2 = 5.

 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findMedian() which takes the root of the Binary Search Tree as input and returns the Median of Node values in the given BST.
// Median of the BST is:

//     If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2
//     If number of nodes are odd : then median = (N+1)/2th node.


// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).


// Constraints:
// 1<=N<=10000


// Time Complexity : O(N)
// Space Complexity : O(H)

void getMedianNumbers(int &curr, int &medNum1, int &medNum2, int &nodesCount, struct Node *root) {
    if (!root) {
        return;
    }

    getMedianNumbers(curr, medNum1, medNum2, nodesCount, root->left);

    curr++;

    if (curr == nodesCount / 2) {
        medNum1 = root->data;
    }

    if (curr == nodesCount / 2 + 1) {
        medNum2 = root->data;
    }

    getMedianNumbers(curr, medNum1, medNum2, nodesCount, root->right);
}

int getNodesCount(struct Node *root) {
    if (!root) {
        return 0;
    }

    return getNodesCount(root->left) + getNodesCount(root->right) + 1;
}

float findMedian(struct Node *root) {
    int nodesCount = getNodesCount(root);

    int medNum1 = 0, medNum2 = 0;
    int curr = 0;

    getMedianNumbers(curr, medNum1, medNum2, nodesCount, root);

    if (nodesCount & 1) {
        return medNum2;
    }

    return ((float) medNum1  + (float) medNum2) / 2.0;
}

// Time Complexity : O(N)
// Space Complexity : O(H) (call stack space)

void inOrderTraversal(struct Node *root, vector<int> &nodes) {
    if (!root) {
        return;
    }
    
    inOrderTraversal(root->left, nodes);
    nodes.push_back(root->data);
    inOrderTraversal(root->right, nodes);
}

float findMedian(struct Node *root) {
    vector<int> nodes;
    inOrderTraversal(root, nodes);

    if (nodes.size() & 1) {
        return (float) nodes[nodes.size() / 2];
    }

    return (float(nodes[nodes.size() / 2 - 1]) + float(nodes[nodes.size() / 2])) / 2.0;
}