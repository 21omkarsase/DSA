// Premium
// 0
// DCC Badge
// 546. Remove Boxes
// Hard
// 1.9K
// 111
// Companies

// You are given several boxes with different colors represented by different positive numbers.

// You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.

// Return the maximum points you can get.

 

// Example 1:

// Input: boxes = [1,3,2,2,2,3,4,3,1]
// Output: 23
// Explanation:
// [1, 3, 2, 2, 2, 3, 4, 3, 1] 
// ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
// ----> [1, 3, 3, 3, 1] (1*1=1 points) 
// ----> [1, 1] (3*3=9 points) 
// ----> [] (2*2=4 points)

// Example 2:

// Input: boxes = [1,1,1]
// Output: 9

// Example 3:

// Input: boxes = [1]
// Output: 1

 

// Constraints:

//     1 <= boxes.length <= 100
//     1 <= boxes[i] <= 100

// Accepted
// 39.9K
// Submissions
// 83.9K
// Acceptance Rate
// 47.6%


// The time complexity of the code is O(n^4), where n is the length of the input vector boxes. This is because the code uses dynamic programming with three nested loops: one loop to iterate over the streak, one loop to iterate over the left index l, and another loop to iterate over the right index r. Each loop can potentially iterate up to n times, resulting in a total time complexity of O(n^4).

// The space complexity of the code is O(n^3). This is because the code uses a 3D vector dp of size n x n x n to store the computed results. The space required is proportional to the number of possible subproblems, which is n x n x n. Therefore, the space complexity is O(n^3).


class Solution {
    int totalPoints(int streak, int l, int r, vector<int>& boxes, vector<vector<vector<int>>> &dp){
        if(l > r)
            return 0;
        
        if(dp[streak][l][r] != -1)
            return dp[streak][l][r];

        if(l == r)
            return dp[streak][l][r] = (streak + 1) * (streak + 1);
        
        int points = (streak + 1) * (streak + 1) + totalPoints(0, l + 1, r, boxes, dp);

        for(int i = l + 1; i <= r; i++){
            if(boxes[l] == boxes[i])
                points = max(points, totalPoints(0, l + 1, i - 1, boxes, dp) + totalPoints(streak + 1, i, r, boxes, dp));
        }

        return dp[streak][l][r] = points;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return totalPoints(0, 0, n - 1, boxes, dp);
    }
};