// 315. Count of Smaller Numbers After Self
// Hard
// 8.2K
// 222
// Companies

// Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

// Example 1:

// Input: nums = [5,2,6,1]
// Output: [2,1,1,0]
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.

// Example 2:

// Input: nums = [-1]
// Output: [0]

// Example 3:

// Input: nums = [-1,-1]
// Output: [0,0]

 

// Constraints:

//     1 <= nums.length <= 105
//     -104 <= nums[i] <= 104

// Accepted
// 293.8K
// Submissions
// 691.3K
// Acceptance Rate
// 42.5%



class Solution {
    void merge(int start, int mid, int end, int n, vector<pair<int, int>> &nums, vector<int> &smallerNums){
        int idx1 = start, idx2 = mid + 1, idx = 0;
        
        int cnt = 0;
        vector<pair<int, int>> sorted(n, {0, 0});
        while(idx1 <= mid && idx2 <= end){
            if(nums[idx1].first > nums[idx2].first){
                cnt++;
                sorted[idx++] = {nums[idx2].first, nums[idx2++].second};
            }else{
                smallerNums[nums[idx1].second] += cnt;
                sorted[idx++] = {nums[idx1].first, nums[idx1++].second};
            }
        }

        while(idx1 <= mid){
            smallerNums[nums[idx1].second] += cnt;
            sorted[idx++] = {nums[idx1].first, nums[idx1++].second};
        }

        while(idx2 <= end){
            sorted[idx++] = {nums[idx2].first, nums[idx2++].second};
        }

        for(int i = 0; i < n; i++)
            nums[i + start] = {sorted[i].first, sorted[i].second};

    }

    void mergeSort(int start, int end, int n, vector<pair<int, int>> &nums, vector<int> &smallerNums){
        if(start >= end)
            return;

        int mid = start + (end - start) / 2;
        n = end - start + 1;

        mergeSort(start, mid, n, nums, smallerNums);
        mergeSort(mid + 1, end, n, nums, smallerNums);
        
        merge(start, mid, end, n, nums, smallerNums);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>> numsCopy(n, {0, 0});
        vector<int> smallerNums(n, 0);

        for(int i = 0; i < n; i++){
            numsCopy[i] = {nums[i], i};
        }

        mergeSort(0, n - 1, n, numsCopy, smallerNums);

        return smallerNums;
    }
};










