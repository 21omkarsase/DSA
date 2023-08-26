// 50. Pow(x, n)
// Medium
// 7.8K
// 7.9K
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
// 1.3M
// Submissions
// 3.8M
// Acceptance Rate
// 33.3%

// Time Complexity : O(Log(N))
// space complexity : O(Log(N)) + O(LogN)

class Solution {
    double calculatePower(double &x, long long n, unordered_map<int, double> &dp) {
        if (n == 0) {
            return 1.0;
        }

        if (n == 1) {
            return x;
        }

        if (dp.find(n) != dp.end()) {
            return dp[n];
        }

        double left = calculatePower(x, n / 2, dp);
        double right = calculatePower(x, n - (n / 2), dp);

        return dp[n] = left * right;
    }

public:
    double myPow(double x, int n) {
        unordered_map<int, double> dp;
        double ans = calculatePower(x, abs((long long) n), dp);

        if (n < 0) {
            return 1.0 / ans;
        }

        return ans;
    }
};

// Time Complexity : O(Log(N))
// space complexity : O(Log(N)) 

class Solution {
    double calculatePower(double &x, int n) {
        if (n == 0) {
            return 1.0;
        }

        double ans = calculatePower(x, n / 2);

        if (n & 1) {
            return ans * ans * x;
        } 

        return ans * ans;
    }

public:
    double myPow(double x, int n) {
        double ans = calculatePower(x, abs(n));

        if (n < 0) {
            return 1.0 / ans;
        }

        return ans;
    }
};


// Time Complexity : O(Log(N))
// space complexity : O(1)

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        
        int power = abs(n);
        while (power) {
            if (power & 1) {
                ans = ans * x;
            }

            x = x * x;
            power /= 2;
        }

        if (n < 0) {
            return 1.0 / ans;
        }

        return ans;
    }
};
