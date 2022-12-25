//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define COUNT 10

class Node{
public:
	int data;
	Node* left,*right;

	Node(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};

class Solution{
public:
	Node* buildTree(string str)
	{
		if (str.length() == 0 || str[0] == 'N')
			return NULL;
		vector<string> ip;
		istringstream iss(str);
		for (string str; iss >> str; )
			ip.push_back(str);
		Node* root = new Node(stoi(ip[0]));
		queue<Node*> queue;
		queue.push(root);
		int i = 1;
		while (!queue.empty() && i < ip.size()) {
			Node* currNode = queue.front();
			queue.pop();
			string currVal = ip[i];
			if (currVal != "N") {
				currNode->left = new Node(stoi(currVal));
				queue.push(currNode->left);
			}
			i++;
			if (i >= ip.size())
				break;
			currVal = ip[i];
			if (currVal != "N") {
				currNode->right = new Node(stoi(currVal));
				queue.push(currNode->right);
			}
			i++;
		}
		return root;
	}

	void print2DUtil(Node* root, int space)
	{
	    if (root == NULL)
	        return;
	    space += COUNT;
	    print2DUtil(root->right, space);
	    cout << endl;
	    for (int i = COUNT; i < space; i++)
	        cout << " ";
	    cout << root->data << "\n";
	 	    print2DUtil(root->left, space);
	}
};



int main()
{
		string s;
		getline(cin >> ws, s);
		Solution os;
		Node* root = os.buildTree(s);
		os.print2DUtil(root,0);
	return 1;
}