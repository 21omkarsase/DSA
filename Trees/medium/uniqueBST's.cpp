// 96. Unique Binary Search Trees
// Medium
// 9.1K
// 359
// Companies

// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

// Example 1:

// Input: n = 3
// Output: 5

// Example 2:

// Input: n = 1
// Output: 1

 

// Constraints:

//     1 <= n <= 19

// Accepted
// 571.1K
// Submissions
// 955.3K
// Acceptance Rate
// 59.8%

class Solution {
public:
    int getNumTreesCount(int n, vector<int>& dp){
        if(n == 0 || n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        int count = 0;
        for(int i = 1; i <= n; i++){
            int left = getNumTreesCount(i - 1, dp);
            int right = getNumTreesCount(n - i, dp);

            cout<<n<<" --> "<<left<<" :: "<<right<<"\n";

            count += (left * right);
        }
        
        return dp[n] = count;
    }
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return getNumTreesCount(n, dp);
    }
};