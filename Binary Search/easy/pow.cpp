// 50. Pow(x, n)
// Medium
// 7.3K
// 7.5K
// Companies

// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000

// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100

// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

 

// Constraints:

//     -100.0 < x < 100.0
//     -231 <= n <= 231-1
//     n is an integer.
//     Either x is not zero or n > 0.
//     -104 <= xn <= 104

// Accepted
// 1.2M
// Submissions
// 3.7M
// Acceptance Rate
// 33.2%
// Seen this question in a real interview before?
// 1/4


class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;

        if(n < 0){
            x = 1 / x;
            n = -(n + 1);
            ans *= x;
        }
        while(n > 0){
            if(n & 1){
                ans *= x;
            }

            x *= x;
            n /= 2;
        }

        return ans;
    }
};