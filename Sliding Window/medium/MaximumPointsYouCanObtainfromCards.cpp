// 1423. Maximum Points You Can Obtain from Cards
// Medium
// 5.4K
// 194
// Companies

// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

// Example 1:

// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12
// Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

// Example 2:

// Input: cardPoints = [2,2,2], k = 2
// Output: 4
// Explanation: Regardless of which two cards you take, your score will always be 4.

// Example 3:

// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
// Output: 55
// Explanation: You have to take all the cards. Your score is the sum of points of all cards.

 

// Constraints:

//     1 <= cardPoints.length <= 105
//     1 <= cardPoints[i] <= 104
//     1 <= k <= cardPoints.length

// Accepted
// 224.1K
// Submissions
// 428.7K
// Acceptance Rate
// 52.3

// Time Complexity : O(2^k)
// Space Complexity : O(k) recursive call stack

class Solution {
    int calculateTotalPoints(int left, int right, int k, vector<int> &nums) {
        if (k == 0 || left > right)
            return 0;

        int leftPoints = calculateTotalPoints(left + 1, right, k - 1, nums) + nums[left];
        int rightPoints = calculateTotalPoints(left, right - 1, k - 1, nums) + nums[right];

        return max(leftPoints, rightPoints);
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        return calculateTotalPoints(0, n - 1, k, cardPoints);
    }
};



// Time Complexity : O(N)
// Space Complexity : O(1) 
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;

        int left = 0, sum = 0, minWindowPoints = INT_MAX;
        int totalPoints = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if (n - k == 0)
            return totalPoints;

        for (int right = 0; right < n; right++) {
            sum += cardPoints[right];

            if (right - left + 1 == windowSize) {
                minWindowPoints = min(minWindowPoints, sum);

                sum -= cardPoints[left++];
            }
        }
        
        return  totalPoints - minWindowPoints;
    }
};