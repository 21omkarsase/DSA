// 852. Peak Index in a Mountain Array
// Medium
// 5.2K
// 1.8K
// Companies

// An array arr a mountain if the following properties hold:

//     arr.length >= 3
//     There exists some i with 0 < i < arr.length - 1 such that:
//         arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
//         arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]
// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]
// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]
// Output: 1

 

// Constraints:

//     3 <= arr.length <= 105
//     0 <= arr[i] <= 106
//     arr is guaranteed to be a mountain array.

// Accepted
// 561.1K
// Submissions
// 814.5K
// Acceptance Rate
// 68.9%
// Seen this question in a real interview before?
// 1/4

class Solution {
    int binarySearch(int st, int en, int &n, vector<int> &nums){
        if(st > en) return INT_MAX;
        
        int mid = (st + en) / 2;
        if(mid > 0 && mid < n - 1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;

        int left = binarySearch(st, mid - 1, n, nums);
        int right = binarySearch(mid + 1, en, n, nums);

        return min(left, right);
    }
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        return binarySearch(0, n - 1, n, nums);
    }
};


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int st = 0, en = n - 1;

        while(st <= en){
            int mid = (st + en) / 2;
            if(nums[mid] < nums[mid + 1])
                st = mid + 1;
            else if(nums[mid] < nums[mid - 1])
                en = mid - 1;
            else return mid;
        }

        return 0;
    }
};