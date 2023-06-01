// 133. Clone Graph
// Medium
// 8.3K
// 3.3K
// Companies

// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

 

// Test case format:

// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

// Example 1:

// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

// Example 2:

// Input: adjList = [[]]
// Output: [[]]
// Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

// Example 3:

// Input: adjList = []
// Output: []
// Explanation: This an empty graph, it does not have any nodes.

 

// Constraints:

//     The number of nodes in the graph is in the range [0, 100].
//     1 <= Node.val <= 100
//     Node.val is unique for each node.
//     There are no repeated edges and no self-loops in the graph.
//     The Graph is connected and all nodes can be visited starting from the given node.

// Accepted
// 988.1K
// Submissions
// 1.8M
// Acceptance Rate
// 53.4%

// Between the two solutions provided, the second solution is more optimal in terms of both time and space complexity.

// The key difference between the two solutions lies in the data structure used to store the visited nodes during the graph cloning process.

// In the first solution, an unordered map with integer keys (unordered_map<int, Node*>) is used to track visited nodes. This map maps the integer value of the original nodes to their corresponding cloned nodes. This approach requires converting the node's value to an integer and performing map lookups based on the integer value. As a result, additional conversions and map lookups are required, leading to slightly higher time complexity.

// On the other hand, the second solution uses an unordered map with node pointers as keys (unordered_map<Node*, Node*>). This map directly maps the original nodes to their cloned counterparts, eliminating the need for value conversions and allowing for direct map lookups based on the node pointers. This approach results in faster map lookups and reduces the overall time complexity.

// In terms of space complexity, both solutions utilize additional memory to store the visited nodes. However, the second solution using node pointers as keys in the map saves some memory compared to the first solution. The first solution requires storing the integer values of the original nodes as keys, while the second solution directly uses the node pointers. This difference in key types leads to slightly lower space complexity in the second solution.

// Therefore, the second solution is more optimal in terms of both time and space complexity compared to the first solution.



// ***********************solution 1 : map<Node*, Node*>***************************
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* buildCloneGraph(Node* node, unordered_map<Node*, Node*> &vis){
        if(!node) return nullptr;
        if(node  && node->neighbors.size() == 0){
            if(vis.find(node) != vis.end()){
                return vis[node];
            }else{
                vector<Node*> neighbors;
                Node *currNode = new Node(node->val);
                currNode->neighbors = neighbors;
                vis[node] = currNode;
                return currNode;
            }
        }
        Node* currNode = new Node(node->val);
        vis[node] = currNode;

        vector<Node*>neighbors;
        for(int i = 0; i < node->neighbors.size(); i++){
            if(vis.find(node->neighbors[i]) != vis.end()){
                neighbors.push_back(vis[node->neighbors[i]]);
            }else neighbors.push_back(buildCloneGraph(node->neighbors[i], vis));
        }

        currNode->neighbors = neighbors;

        return currNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> vis;
        return buildCloneGraph(node, vis);
    }
};





// *******************************solution 2 map<int, Node*>***********************************************
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* buildCloneGraph(Node* node, unordered_map<int, Node*> &vis){
        if(!node) return nullptr;
        if(node  && node->neighbors.size() == 0){
            if(vis.find(node->val) != vis.end()){
                return vis[node->val];
            }else{
                vector<Node*> neighbors;
                Node *currNode = new Node(node->val);
                currNode->neighbors = neighbors;
                vis[node->val] = currNode;
                return currNode;
            }
        }
        Node* currNode = new Node(node->val);
        vis[node->val] = currNode;

        vector<Node*>neighbors;
        for(int i = 0; i < node->neighbors.size(); i++){
            if(vis.find(node->neighbors[i]->val) != vis.end()){
                neighbors.push_back(vis[node->neighbors[i]->val]);
            }else neighbors.push_back(buildCloneGraph(node->neighbors[i], vis));
        }

        currNode->neighbors = neighbors;

        return currNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> vis;
        return buildCloneGraph(node, vis);
    }
};







