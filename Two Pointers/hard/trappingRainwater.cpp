// 42. Trapping Rain Water
// Hard
// 27K
// 372
// Companies

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

 

// Constraints:

//     n == height.length
//     1 <= n <= 2 * 104
//     0 <= height[i] <= 105

// Accepted
// 1.6M
// Submissions
// 2.6M
// Acceptance Rate
// 59.4%

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int leftMax = height[0], rightMax = height[n - 1];
        int left = 1, right = n - 2;
        
        int waterAmount = 0;
        while(left <= right) {
            if(height[left] >= leftMax)
                leftMax = height[left++];
            else if(height[right] >= rightMax)
                rightMax = height[right--];
            else if(leftMax <= rightMax)
                waterAmount += (leftMax - height[left++]);
            else waterAmount += (rightMax - height[right--]);
        }

        return waterAmount;
    }
};



// Time Complexity : O(N)
// Space Complexity : O(N)


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxRightHeight(n, height[n - 1]);

        for(int i = n - 2; i >= 0; i--)
            maxRightHeight[i] = max(maxRightHeight[i + 1], height[i]);
        
        int waterAmount = 0, currLeftMax = height[0];
        for(int i = 0; i < n; i++){
            currLeftMax = max(currLeftMax, height[i]);
            waterAmount += (min(maxRightHeight[i], currLeftMax) - height[i]);
        }

        return waterAmount;
    }
};