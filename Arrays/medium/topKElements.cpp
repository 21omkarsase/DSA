// 347. Top K Frequent Elements
// Medium
// 14.7K
// 519
// Companies

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

 

// Constraints:

//     1 <= nums.length <= 105
//     -104 <= nums[i] <= 104
//     k is in the range [1, the number of unique elements in the array].
//     It is guaranteed that the answer is unique.

 

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
// Accepted
// 1.5M
// Submissions
// 2.4M
// Acceptance Rate
// 64.0%

class Solution {

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)
            return {nums[0]};
        
        unordered_map<int, int> m;
        for(auto ele : nums)
            m[ele]++;

        map<int, vector<int>, greater<int>> umap;
        for(auto [p1, p2] : m){
            umap[p2].push_back(p1);
        }

        vector<int> freq;
        for(int i = 0; i < k; i++){
            for(auto p : umap){
                for(auto ele : p.second){
                    if(i < k)
                        freq.push_back(ele); 
                    else {
                        break;
                    }
                    i++;
                }
            }
        }

        return freq;
    }
};