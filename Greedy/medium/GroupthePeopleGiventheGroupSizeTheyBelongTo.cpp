// 1282. Group the People Given the Group Size They Belong To
// Medium
// 2.4K
// 620
// Companies

// There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.

// You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

// Return a list of groups such that each person i is in a group of size groupSizes[i].

// Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.

 

// Example 1:

// Input: groupSizes = [3,3,3,3,3,1,3]
// Output: [[5],[0,1,2],[3,4,6]]
// Explanation: 
// The first group is [5]. The size is 1, and groupSizes[5] = 1.
// The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
// The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
// Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].

// Example 2:

// Input: groupSizes = [2,1,3,3,3,2]
// Output: [[1],[0,5],[2,3,4]]

 

// Constraints:

//     groupSizes.length == n
//     1 <= n <= 500
//     1 <= groupSizes[i] <= n

// Accepted
// 153.4K
// Submissions
// 175.6K
// Acceptance Rate
// 87.3%

// Time Complexity : O(N + O(k*N)) -> (k -> total groups)
// Space Complexity : O(N)

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        
        unordered_map<int, vector<int>> tracker;

        for (int idx = 0; idx < n; idx++) {
            tracker[groupSizes[idx]].push_back(idx);
        }

        vector<vector<int>> ans;

        for (auto p : tracker) {
            vector<int> indices = p.second;
            
            int grpSize = p.first;
            int m = indices.size();

            for (int idx1 = 0; idx1 < m; idx1++) {
                vector<int> temp;

                for(int idx2 = idx1; idx2 < idx1 + grpSize; idx2++) {
                    temp.push_back(indices[idx2]);
                }

                ans.push_back(temp);

                idx1 = idx1 + grpSize - 1;
            }
        }

        return ans;
    }
};


// Time Complexity : O(2N)
// Space Complexity : O(N)


class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> tracker;

        for (int idx = 0; idx < n; idx++) {
            tracker[groupSizes[idx]].push_back(idx);

            if (tracker[groupSizes[idx]].size() == groupSizes[idx]) {
                ans.push_back(tracker[groupSizes[idx]]);
                tracker[groupSizes[idx]].clear();
            }
        }

        return ans;
    }
};