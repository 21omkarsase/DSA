
// 735. Asteroid Collision
// Medium
// 5.5K
// 548
// Companies

// We are given an array asteroids of integers representing asteroids in a row.

// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

// Example 1:

// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

// Example 2:

// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.

// Example 3:

// Input: asteroids = [10,2,-5]
// Output: [10]
// Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

 

// Constraints:

//     2 <= asteroids.length <= 104
//     -1000 <= asteroids[i] <= 1000
//     asteroids[i] != 0

// Accepted
// 300K
// Submissions
// 676K
// Acceptance Rate
// 44.4%

// Time Complexity : O(N^2)


//eliminate every possible element for each -ve ele (by traversing to it's left)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        
        vector<int> ans;

        for (int idx1 = 0; idx1 < n; idx1++) {
           if (asteroids[idx1] < 0) {
               for (int idx2 = idx1 - 1; idx2 >= 0; idx2--) {
                   if (asteroids[idx2] == 0) {
                       continue;
                   }

                   if (abs(asteroids[idx2]) > -asteroids[idx1]) {
                       if (asteroids[idx2] > 0)
                            asteroids[idx1] = 0;
                       break;
                   }

                   if (asteroids[idx2] == -asteroids[idx1]) {
                       asteroids[idx2] = 0;
                       asteroids[idx1] = 0;
                       
                       break;
                   }

                   if (asteroids[idx2] > 0 && asteroids[idx2] < -asteroids[idx1]) {
                       asteroids[idx2] = 0;
                   }
               }
           }
        } 

        for (int idx1 = 0; idx1 < n; idx1++) {
            if (asteroids[idx1] != 0) {
                ans.push_back(asteroids[idx1]);
            }
        }

        return ans;
    }
};


// Time Complexity : O(N)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for (int idx = 0; idx < n; idx++) {
            if (!st.empty() && asteroids[st.top()] > 0 && asteroids[st.top()] == -asteroids[idx]) {
                st.pop();
                continue;
            }
            
            bool flag = true;

            while (!st.empty() && asteroids[st.top()] > 0 && -asteroids[idx] > asteroids[st.top()]) {
                st.pop();

                if (!st.empty() && asteroids[st.top()] > 0 && asteroids[st.top()] == -asteroids[idx]) {
                    st.pop();
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                continue;
            }

            if (st.empty() || !(asteroids[st.top()] > 0 && asteroids[idx] < 0 && -asteroids[idx] < asteroids[st.top()])) {
                st.push(idx);
            }
        } 

        int idx = st.size() - 1;
        vector<int> ans(st.size());

        while(!st.empty()) {
            ans[idx--] = asteroids[st.top()];
            st.pop();
        }

        return ans;
    }
};