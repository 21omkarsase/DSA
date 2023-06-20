// 658. Find K Closest Elements
// Medium
// 7.1K
// 577
// Companies

// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

//     |a - x| < |b - x|, or
//     |a - x| == |b - x| and a < b

 

// Example 1:

// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

// Example 2:

// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]

 

// Constraints:

//     1 <= k <= arr.length
//     1 <= arr.length <= 104
//     arr is sorted in ascending order.
//     -104 <= arr[i], x <= 104

// Accepted
// 439.8K
// Submissions
// 938.5K
// Acceptance Rate
// 46.9%

time complexity : O(k)
space complexity : O(1)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
       int n = nums.size();

       int start = 0, end = n - 1;

       while((end - start + 1) > k){
           int startIdxDiff = abs(nums[start] - x), endIdxDiff = abs(nums[end] - x);

           if(startIdxDiff > endIdxDiff)
                start++;
           else end--;
       }

       vector<int> sorted;
       for(; start <= end; start++)
            sorted.push_back(nums[start]);

        return sorted;
    }
};

time complexity : O(nLogn)
space complexity : O(1)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int idx = lower_bound(nums.begin(), nums.end(), x) - nums.begin();

        if(idx == n){
            vector<int> closest(nums.end() - k, nums.end());
            return closest;
        }

        if(idx == 0){
            vector<int> closest(nums.begin(), nums.begin() + k);
            return closest;
        }

        if(nums[idx] != x && abs(x - nums[idx - 1]) <= abs(x - nums[idx]))
            idx -= 1;
        
        vector<int> sorted;
        sorted.push_back(nums[idx]);
        k--;
        int left = idx - 1, right = idx + 1;

        while(k--){
            if(left < 0){
                sorted.push_back(nums[right++]);
            }else if(right >= n){
                sorted.push_back(nums[left--]);
            }else{
                int leftDiff = abs(x - nums[left]), rightDiff = abs(x - nums[right]);

                if(leftDiff <= rightDiff)
                    sorted.push_back(nums[left--]);
                else sorted.push_back(nums[right++]);
            }
        }

        sort(sorted.begin(), sorted.end()); 
        
        return sorted;
    }
};


time complexity : O(kLogk)
space complexity : O(n);

class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        for(auto num : nums)
            pq.push({abs(num - x), num});
        
        vector<int> sorted;
        while(k--){
            sorted.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(sorted.begin(), sorted.end());
        return sorted;
    }
};










