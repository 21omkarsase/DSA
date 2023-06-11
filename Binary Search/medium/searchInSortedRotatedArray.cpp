// 33. Search in Rotated Sorted Array
// Medium
// 21.5K
// 1.3K
// Companies

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:

// Input: nums = [1], target = 0
// Output: -1

 

// Constraints:

//     1 <= nums.length <= 5000
//     -104 <= nums[i] <= 104
//     All values of nums are unique.
//     nums is an ascending array that is possibly rotated.
//     -104 <= target <= 104

// Accepted
// 2.1M
// Submissions
// 5.3M
// Acceptance Rate
// 39.1%

// *********************************1********************************
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, en = n - 1;

        while(st <= en){
            int mid = st + (en - st) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] >= nums[st]){
                if(nums[mid] == target)
                    return mid;
                if(nums[mid] >= target && target >= nums[st])
                    en = mid - 1;
                else st = mid + 1;
            }else{
                if(nums[mid] == target)
                    return mid;
                if(nums[mid] <= target && target <= nums[en])
                    st = mid + 1;
                else en = mid - 1;
            }
        }

        return -1;
    }
};



// *************************************2**************************************

class Solution {
    int binarySearch(int st, int en, vector<int> nums, int target){
        while(st <= en){
            int mid = st + (en - st) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                en = mid - 1;
            else st = mid + 1;
        }

        return -1;
    }
    int findPivot(int st, int &n, vector<int> &nums){
        int en = n - 1;
        while(st <= en){
            int mid = st + (en - st) / 2;

            if(mid > 0 && mid < n - 1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if ((mid == 0 && n >= 2 && nums[mid] > nums[mid + 1] && nums[mid] > nums[n - 1]) || (mid == n - 1 && nums[mid] > nums[0] && nums[mid] > nums[mid - 1]))
                return mid;
            else if(nums[mid] < nums[st])
                en = mid - 1;
            else st = mid + 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(0, n, nums);
        int st, en;
        if(pivot == -1 || pivot == n - 1)
            st = 0, en = n - 1;
        else if(nums[pivot] >= target && nums[st] <= target)
            st = 0, en = pivot;
        else st = pivot + 1, en = n - 1;

        cout<<pivot<<" : "<<st<<" : "<<en<<"\n";

        return binarySearch(st, en, nums, target);
        return 0;
    }
};

