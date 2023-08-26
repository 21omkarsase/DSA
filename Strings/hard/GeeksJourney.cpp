// Geek's Journey
// Accuracy: 30.7%Submissions: 9K+Points: 40

// You're provided with two arrays:

//     "geeksTown" of length n - representing the heights of buildings in Geek's town
//     "journey" of length m      - representing the heights of buildings he sees during his train journey.

// Geek finds happiness when he encounters a series of buildings during his journey that completely match with geeksTown.

// You have 'q' queries of the form [l, r], where you need to determine how many times Geek will feel happy during the journey  from [l, r].

// Example 1:

// Input:
// n = 4,
// geeksTown[] = {3, 0, 1, 9},
// m = 11,
// journey[] = {1, 3, 0, 1, 9, 1, 7, 3, 0, 1, 9},
// q = 4,
// queries[] = [
//  [0, 3],
//  [1, 5],
//  [1, 10],
//  [7, 9]
// ]
// Output:
// 0 1 2 0
// Explanation:


// The pattern of GeekTown is repeated 0 times in query 1 i.e. [0, 3]
// The pattern of GeekTown is repeated 1 times in query 2 i.e. [1, 5]
// The pattern of GeekTown is repeated 2 times in query 3 i.e. [1, 10]
// The pattern of GeekTown is repeated 0 times in query 4 i.e. [7, 9]

 

// Example 2:

// Input:
// n = 2,
// geeksTown[] = {2, 2},
// m = 6,
// journey[] = {2, 2, 2, 2, 2, 2},
// q = 3,
// queries[] = [
// [0, 2],
// [1, 4],
// [0, 5]
// ]
// Output:
// 2 3 5
// Explanation:


// The pattern of GeekTown is repeated 2 times in query 1 i.e. [0, 2]
// The pattern of GeekTown is repeated 3 times in query 2 i.e. [1, 4]
// The pattern of GeekTown is repeated 5 times in query 3 i.e. [0, 5]

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function geeksJourney() which takes an integer array geeksTown[], an integer n , an integer array journey[], an integer m, a 2D integer array queries[][] and an integer q representing length of queries as input parameters and returns an array of length q where each element is respresenting the answer for each query.

 

// Constraints:
// 1 <= |geeksTown|, |journey| <= 2 * 105
// 0<= geeksTown[i], journey[i] <= 109
// 1 <= |queries| <= 5 *104
// 0 <= queries[i][0], queries[i][1] < |journey|

// Time Complexity : O(N + M + Q)
// Space Complexity : O(N + M)

class Solution
{
    vector<int> calculateZTable(const int &n, const int &m, const vector<int> &geeksTown, const vector<int> &journey) {
        vector<int> temp (geeksTown.begin(), geeksTown.end());
        
        temp.push_back(-1);
        
        for (auto ele : journey) {
            temp.push_back(ele);
        }
        
        int len = temp.size();
        
        vector<int> z(len, 0);
        int left = 0, right = 0;
        
        for (int idx = 1; idx < len; idx++) {
            if (idx <= right) {
                z[idx] = min(right - idx + 1, z[idx - left]);
            }
            
            while (idx + z[idx] < len && temp[z[idx] + idx] == temp[z[idx]]) {
                z[idx]++;
            }
            
            if (idx + z[idx] - 1 > right) {
                left = idx;
                right = idx + z[idx] - 1;
            }
        }
        
        return z;
    }
    public:
    vector<int> geeksJourney(vector<int>& geeksTown, int n, 
                             vector<int>& journey, int m, 
                             vector<vector<int>>& queries, int q)
    {
        vector<int> z = calculateZTable(n, m, geeksTown, journey);
        
        int len = z.size();
        
        vector<int> prefix(m, 0);
        
        for (int idx = n + 1; idx < len; idx++) {
            if (z[idx] == n) {
                prefix[idx - (n + 1)]++;
            }
        }
        
        for (int idx = 1; idx < m; idx++) {
            prefix[idx] += prefix[idx - 1]; 
        }
        
        vector<int> ans(q, 0);
        
        for (int idx = 0; idx < q; idx++) {
            int left = queries[idx][0], right = queries[idx][1] - n + 1;
            
            if (right >= left) {
                ans[idx] = prefix[right] - prefix[left - 1];
            }
        }
        
        return ans;
    }
};
