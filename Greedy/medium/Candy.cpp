// 135. Candy
// Solved
// Hard
// Topics
// Companies

// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

//     Each child must have at least one candy.
//     Children with a higher rating get more candies than their neighbors.

// Return the minimum number of candies you need to have to distribute the candies to the children.

 

// Example 1:

// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

// Example 2:

// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.

 

// Constraints:

//     n == ratings.length
//     1 <= n <= 2 * 104
//     0 <= ratings[i] <= 2 * 104

// Accepted
// 362.1K
// Submissions
// 866.7K
// Acceptance Rate
// 41.8%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> ans(n);
        ans[0] = 1;

        for (int idx = 1; idx < n; idx++) {
            ans[idx] = 1;

            if (ratings[idx] > ratings[idx - 1] && ans[idx] <= ans[idx - 1]) {
                ans[idx] = max(ans[idx - 1] + 1, ans[idx] + 1);
            }
        }

        int candies = ans[n - 1];

        for (int idx = n - 2; idx >= 0; idx--) {
            if (ratings[idx] > ratings[idx + 1] && ans[idx] <= ans[idx + 1]) {
                ans[idx] = max(ans[idx + 1] + 1, ans[idx] + 1);
            }

            candies += ans[idx];
        }

        return candies;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
    int sum (int n) {
        return (n * (n + 1)) / 2;
    }
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int up = 0, down = 0;
        int prevSlope = 0;
        
        int candies = 0;

        for (int idx = 1; idx < n; idx++) {
            int currSlope = 0;

            if (ratings[idx - 1] > ratings[idx]) {
                currSlope = -1;
            }
            else if (ratings[idx - 1] < ratings[idx]) {
                currSlope = 1;
            }

            if ((prevSlope == -1 && currSlope >= 0) || (prevSlope == 1 && currSlope == 0)) {  
                candies += (sum(up) + sum(down) + max(up, down));

                up = 0;
                down = 0;
            }

            if (currSlope == 1) {
                up++;
            }
            else if (currSlope == -1) {
                down++;
            }
            else {
                candies++;
            }

            prevSlope = currSlope;
        }
        
        candies += (sum(up) + sum(down) + max(up, down) + 1); // extra 1 for last mountain

        return candies;
    }
};