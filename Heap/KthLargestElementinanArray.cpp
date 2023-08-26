// 215. Kth Largest Element in an Array
// Medium
// 15.2K
// 723
// Companies

// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

 

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

 

// Constraints:

//     1 <= k <= nums.length <= 105
//     -104 <= nums[i] <= 104


// Time Complexity : O(N)
// Space Complexity : O(1e4 + 1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> arr((1e4 * 2) + 1, 0);

        for (auto num : nums) {
            arr[num + 1e4]++;
        }

        for (int idx = arr.size() - 1; idx >= 0; idx--) {
            if (arr[idx] != 0) {
                k -= arr[idx];

                if (k <= 0) {
                    return idx - 1e4;
                }
            }
        }

        return 0;
    }
};


// Time Complexity : O(N*LogN)
// Space Complexity : O(N)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int> pq;

        for (auto num : nums) {
            pq.push(num);
        }

        while (k-- > 1) {
            pq.pop();
        }

        return pq.top();
    }
};

// Time Complexity : average case -> (2N) : worst case -> (N^2)
// Space Complexity : O(1)

class Solution {
    int findPivot(int low, int high, vector<int> &nums) {
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
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while (low < high) {
            int pivot = findPivot(low, high, nums);
        
            if (pivot == n - k) {
                return nums[pivot];
            }
            else {
                if (pivot < n - k) {
                    low = pivot + 1;
                }
                else {
                    high = pivot - 1;
                }
            }
        }

        return nums[n - k];
    }
};