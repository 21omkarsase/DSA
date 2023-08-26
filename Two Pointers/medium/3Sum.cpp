// 15. 3Sum
// Medium
// 26.2K
// 2.4K
// Companies

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.

// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

 

// Constraints:

//     3 <= nums.length <= 3000
//     -105 <= nums[i] <= 105

// Accepted
// 2.7M
// Submissions
// 8.2M
// Acceptance Rate
// 32.8%

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        set<vector<int>> uniqueThreeSums;

        for (int idx = 0; idx < n; idx++) {
            int left = idx + 1, right = n - 1;
            int sum = nums[idx];

            while (left < right) {
                int totalSum = sum + nums[left] + nums[right];

                if (totalSum == 0) {
                    uniqueThreeSums.insert({nums[idx], nums[left], nums[right]});
                    
                    left++, right--;

                    if (nums[idx] + nums[left] + nums[right] > 0) {
                        right--;
                    }
                    else if (nums[idx] + nums[left] + nums[right] < 0){
                        left++;
                    }
                }
                else if (totalSum > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }
        } 

        vector<vector<int>> threeSumResult(uniqueThreeSums.begin(), uniqueThreeSums.end());

        return threeSumResult;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> triplets;
        for(int idx1 = 0; idx1 < n; idx1++){
            if(idx1 > 0 && nums[idx1] == nums[idx1 - 1])
                continue;

            int start = idx1 + 1, end = n - 1;

            while(start < end){
                int sum = nums[idx1] + nums[start] + nums[end];

                if(sum == 0){
                    triplets.push_back({nums[idx1], nums[start++], nums[end--]});
                    while(start < n && nums[start] == nums[start - 1])
                        start++;
                    while(end >= 0 && nums[end] == nums[end + 1])
                        end--;
                }else if(sum > 0)
                    end--;
                else start++;
            }
        }
        
        return triplets;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        set<vector<int>> triplets;
        for(int idx1 = 0; idx1 < n; idx1++){
            unordered_set<int> sumTracker;

            for(int idx2 = idx1 + 1; idx2 < n; idx2++){
                int complement = nums[idx1] + nums[idx2];

                if(sumTracker.find(-complement) != sumTracker.end()){
                    vector<int> triplet = {nums[idx1], nums[idx2], -complement};
                    sort(triplet.begin(), triplet.end());
                    triplets.insert(triplet);
                }
                
                sumTracker.insert(nums[idx2]);
            }
        }
        
        vector<vector<int>> sums(triplets.begin(), triplets.end());
        return sums;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> sums;
        unordered_set<string> countTracker;
        for(int idx1 = 0; idx1 < n; idx1++){
            unordered_map<int, int> sumTracker;

            for(int idx2 = idx1 + 1; idx2 < n; idx2++){
                int complement = nums[idx1] + nums[idx2];
                
                int first = nums[idx1], second = nums[idx2], third = -complement;
                if(second > first)
                    swap(first, second);
                if(second > third)
                    swap(second, third);

                if(sumTracker.find(-complement) != sumTracker.end() && countTracker.count(to_string(first) + to_string(second) + to_string(third)) != 1){
                    sums.push_back({nums[idx1], nums[idx2], -complement});
                    first = nums[idx1], second = nums[idx2], third = -complement;
                    if(second > first)
                        swap(first, second);
                    if(second > third)
                        swap(second, third);
                    countTracker.insert(to_string(first) + to_string(second) + to_string(third));
                }
                
                sumTracker[nums[idx2]] = idx2;
            }
        }
        
        return sums;
    }
};