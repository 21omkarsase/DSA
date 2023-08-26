class Solution {
    int findPartitionIdx(int low, int high, vector<int> &nums) {
        int pivot = nums[low];

        int idx1 = low;
        int idx2 = high;

        while (idx1 < idx2) {
            while (idx1 < high && nums[idx1] <= pivot) {
                idx1++;
            }

            while (idx2 > low && nums[idx2] > pivot) {
                idx2--;
            }

            if (idx1 < idx2) {
                swap(nums[idx1], nums[idx2]);
            }
        }

        swap(nums[low], nums[idx2]);

        return idx2;
    }
    void quickSort(int low, int high, vector<int> &nums) {
        if (low >= high) {
            return;
        }

        int partitionIdx = findPartitionIdx(low, high, nums);

        quickSort(low, partitionIdx - 1, nums);
        quickSort(partitionIdx + 1, high, nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        
        quickSort(0, n - 1, nums);

        return nums;
    }
};