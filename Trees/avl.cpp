#include<bits/stdc++.h>
using namespace std;

class AVL;

class Node {
private :
    int val;
    int height;

    Node *left;
    Node *right;

public :
    Node(int val) {
    	this->val = val;
    	height = 0;

    	left = nullptr;
    	right = nullptr;
    };

    friend class AVL;
};

class AVL {
private : 
    Node *root;

    void populatedSorted(vector<int> &nums, int start, int end) {
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;

        this->insert(nums[mid]);

        populatedSorted(nums, start, mid);
        populatedSorted(nums, mid + 1, end);
    }

    void display(Node *node, string details, int val) {
        if (!node) {
            return;
        }

        cout<<details<<val<<" : "<<node->val<<"\n";

        display(node->left, "Left child of ", node->val);
        display(node->right, "Right child of ", node->val);
    }


    bool balanced(Node *node) {
        if (node == nullptr) {
            return true;
        }

        return abs(height(node->left) - height(node->right) <= 1 && balanced(node->left) && balanced(node->right));
    }

    Node *leftRotate(Node *node) {
        Node *child = node->right;
        
        node->right = child->left;
        child->left = node;

        node->height = height(node);
        child->height = height(child);

        return child;
    }

    Node *rightRotate(Node *node) {
        Node *child = node->left;
        
        node->left = child->right;
        child->right = node;

        node->height = height(node);
        child->height = height(child);

        return child;
    }

    Node *rotate(Node *node) {
        if (height(node->left) - height(node->right) > 1) {
            if (height(node->left->left) - height(node->left->right) > 0) {
                return rightRotate(node);
            }
            else if (height(node->left->right) - height(node->left->left) > 0) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        if (height(node->right) - height(node->left) > 1) {
            if (height(node->right->right) - height(node->right->left) > 0) {
                return leftRotate(node);
            }
            else if (height(node->right->left) - height(node->right->right) > 0) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

public :
    AVL() {
    	root = nullptr;
    }

    int height(Node *node) {
    	if (!node) {
    		return 0;
    	} 

    	return max(height(node->left), height(node->right)) + 1;
    }

    void populate(vector<int> &nums) {
    	for (int idx = 0; idx < nums.size(); idx++) {
    		this->insert(nums[idx]);
    	}
    }


    void populatedSorted(vector<int> &nums) {
    	populatedSorted(nums, 0, nums.size());
    }

    void display() {
    	if (root) {
	    	display(root, "Root Node :", root->val);
	    }
    }

    bool isEmpty() {
    	return root == nullptr;
    }

    bool balanced() {
    	return balanced(root);
    }

    Node* insert(int val, Node *node) {
    	if (node == nullptr) {
	    	node = new Node(val);
	    	return node;
    	}

    	if (val < node->val) {
    		node->left = insert(val, node->left);
    	}

    	if (val > node->val) {
    		node->right = insert(val, node->right);
    	}


    	node->height = height(node);

        return rotate(node);
    }

    void insert(int val) {
    	root = insert(val, root);
    }
};

int main(){

	AVL avl;

	cout<<avl.isEmpty()<<"\n";

    avl.insert(20);
    avl.insert(15);
    avl.insert(25);
    avl.insert(10);
    avl.insert(18);

	avl.display();

    avl.insert(16);
    cout<<"\n";
    avl.display();

	return 0;
}