class Solution {
    void heapify(int idx, int n, vector<int> &nums) {
        while (idx < n) {
            int largest = idx;
            int leftChild = 2 * idx + 1;
            int rightChild = 2 * idx + 2;

            if (leftChild < n && nums[leftChild] > nums[largest]) {
                largest = leftChild;
            }

            if (rightChild < n && nums[rightChild] > nums[largest]) {
                largest = rightChild;
            }

            if (largest != idx) {
                swap(nums[idx], nums[largest]);
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

    void heapSort(vector<int> &nums) {
        buildHeap(nums);
        
        int size = nums.size();

        while (size > 1) {
            swap(nums[0], nums[size - 1]);
            size--;

            heapify(0, size, nums);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);

        return nums;
    }
};