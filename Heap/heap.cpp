// min heap -> complete binary tree
            // -> parent node->val >= children node->val

// max heap    -> complete binary tree
            // -> parent node->val <= children node->val

#include<iostream>
#include<vector>

using namespace std;

void printArr(vector<int> &arr) {
	for (int num : arr) {
		cout<<num<<" : ";
	}
	cout<<"\n";
}


void balanceHeap(vector<int> &arr) {
	int idx = arr.size() - 1;
	int parent;

	while (idx >= 0) {
		if (idx & 1) {
			parent = (idx - 1) / 2;
		}
		else {
			parent = (idx - 2) / 2;
		}

		if (parent < 0 || arr[parent] >= arr[idx]) {
			return;
		}
	
		swap(arr[parent], arr[idx]);
		idx = parent;
	}
}

void heapify(int idx, int n, vector<int> &arr) {
	while (idx < n) {
        int largest = idx;
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;

        if (leftChild < n && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }

        if (rightChild < n && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }

        if (largest != idx) {
            swap(arr[idx], arr[largest]);
            idx = largest;
        }
        else {
            return;
        }
    }
}

void buildHeap(vector<int> &nums) {
	for (int idx = nums.size() / 2 - 1; idx >= 0; idx--) {
		heapify(idx, nums.size(), nums);
	}
}


void insertNode(int num, vector<int> &arr) {
	arr.push_back(num);
	balanceHeap(arr);
}

void deleteNode(vector<int> &arr) {
	if (arr.size() <= 1) {
		return;
	}

	int n = arr.size();

	arr[0] = arr[n - 1];
	arr.pop_back();

	n--;

	heapify(0, arr.size(), arr);
}

void heapSort(vector<int> &nums) {
	int n = nums.size();

    while (n > 1) {
    	swap(nums[0], nums[n - 1]);
    	n--;

    	heapify(0, n, nums);
    }
}


int main() {
	vector<int> arr;

	insertNode(30, arr);
	insertNode(15, arr);
	insertNode(34, arr);
	insertNode(23, arr);
	insertNode(322, arr);
	insertNode(2, arr);
	insertNode(1, arr);

	printArr(arr);

	deleteNode(arr);
	deleteNode(arr);

	printArr(arr);
    
    vector<int> nums = {30, 15, 34, 23, 322, 2, 1};
	
	buildHeap(nums);
	printArr(nums);

	heapSort(nums);
	printArr(nums);

	vector<int> nums2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


	buildHeap(nums2);
	printArr(nums2);

	heapSort(nums2);
	printArr(nums2);

	return 0;
}