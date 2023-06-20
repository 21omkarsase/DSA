// st
// Premium
// 0
// DCC Badge
// 493. Reverse Pairs
// Hard
// 5K
// 228
// Companies

// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

//     0 <= i < j < nums.length and
//     nums[i] > 2 * nums[j].

 

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

// Example 2:

// Input: nums = [2,4,3,5,1]
// Output: 3
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
// (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

 

// Constraints:

//     1 <= nums.length <= 5 * 104
//     -231 <= nums[i] <= 231 - 1

// Accepted
// 127.9K
// Submissions
// 415.3K
// Acceptance Rate
// 30.8%


class Solution {
    long long countReversePairs(long long start, long long mid, long long end, long long n, vector<int> &nums){
        long long left = start, right = mid + 1, pairCount = 0;

        while(left <= mid){
            while(right <= end && nums[left] > (long long)nums[right] * 2)
                right++;
            pairCount += (right - (mid + 1));

            left++;
        }

        return pairCount;
    }

    void merge(long long start, long long end, long long mid, long long n, vector<int> &nums){
        long long idx1 = start, idx2 = mid + 1, idx = 0;

        vector<int> sorted(n, 0);

        while(idx1 <= mid && idx2 <= end){
            if(nums[idx1] >= nums[idx2])
                sorted[idx++] = nums[idx2++];
            else{
                sorted[idx++] = nums[idx1++];
            }
        }

        while(idx1 <= mid){
            sorted[idx++] = nums[idx1++];
        }

        while(idx2 <= end){
            sorted[idx++] = nums[idx2++];
        }

        for(int idx = 0; idx < n; idx++){
            nums[idx + start] = sorted[idx];
        }
    }

    long long mergeSort(long long start, long long end, long long n, vector<int> &nums){
        if(start >= end)
            return 0;
        
        long long mid = start + (end - start) / 2;
        n = end - start + 1;
    
        long long pairCount = 0;
        pairCount += mergeSort(start, mid, n, nums);
        pairCount += mergeSort(mid + 1, end, n, nums);
        pairCount += countReversePairs(start, mid, end, n, nums);
        
        merge(start, end, mid, n, nums);

        return pairCount;
    }
public:
    int reversePairs(vector<int>& nums) {
        long long n = nums.size();

        return mergeSort(0, n - 1, n, nums);
    }
};


class Solution {
    long long merge(long long start, long long end, long long mid, long long n, vector<int> &nums){
        long long idx1 = start, idx2 = mid + 1, idx = 0;

        vector<int> sorted(n, 0);
        
        long long pairCount = 0, totalCount = 0;
        while(idx1 <= mid && idx2 <= end){
            if(nums[idx1] > (long long)nums[idx2] * 2){
                pairCount++;
                sorted[idx++] = nums[idx2++];
            }
            else{
                sorted[idx++] = nums[idx1++];
                totalCount += pairCount;
            }
        }

        while(idx1 <= mid){
            totalCount += pairCount;
            sorted[idx++] = nums[idx1++];
        }

        idx1 = start, idx2 = mid + 1, idx = 0;

        while(idx1 <= mid && idx2 <= end){
            if(nums[idx1] >= nums[idx2])
                sorted[idx++] = nums[idx2++];
            else{
                sorted[idx++] = nums[idx1++];
            }
        }

        while(idx1 <= mid){
            sorted[idx++] = nums[idx1++];
        }

        while(idx2 <= end){
            sorted[idx++] = nums[idx2++];
        }

        for(int idx = 0; idx < n; idx++){
            nums[idx + start] = sorted[idx];
        }

        return totalCount;
    }

    long long mergeSort(long long start, long long end, long long n, vector<int> &nums){
        if(start >= end)
            return 0;
        
        long long mid = start + (end - start) / 2;
        n = end - start + 1;
    
        long long pairCount = 0;
        pairCount += mergeSort(start, mid, n, nums);
        pairCount += mergeSort(mid + 1, end, n, nums);
        
        pairCount += merge(start, end, mid, n, nums);

        return pairCount;
    }
public:
    int reversePairs(vector<int>& nums) {
        long long n = nums.size();

        return mergeSort(0, n - 1, n, nums);
    }
};