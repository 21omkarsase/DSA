// 1359. Count All Valid Pickup and Delivery Options
// Hard
// 1.9K
// 160
// Companies

// Given n orders, each order consist in pickup and delivery services. 

// Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

// Since the answer may be too large, return it modulo 10^9 + 7.

 

// Example 1:

// Input: n = 1
// Output: 1
// Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.

// Example 2:

// Input: n = 2
// Output: 6
// Explanation: All possible orders: 
// (P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
// This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.

// Example 3:

// Input: n = 3
// Output: 90

 

// Constraints:

//     1 <= n <= 500

// Accepted
// 67K
// Submissions
// 105.6K
// Acceptance Rate
// 63.4%

// Time Complexity : O(2 ^ (N * N))
// Space Complexity : O(3N)

class Solution {
    const int MOD = 1e9 + 7;

    int calculateTotalOrdersCount(const int &n, int deliverCount, vector<int> &pick, vector<int> &deliver) {
        if (deliverCount == n) {
            return 1;
        }

        int totalSequences = 0;

        for (int idx = 1; idx <= n; idx++) {
            if (pick[idx] == 0) {
                pick[idx] = 1;
                totalSequences = (totalSequences % MOD + calculateTotalOrdersCount(n, deliverCount, pick, deliver) % MOD) % MOD;
                pick[idx] = 0; 
            }

            if (pick[idx] == 1 && deliver[idx] == 0) {
                deliver[idx] = 1;
                totalSequences =  (totalSequences % MOD + calculateTotalOrdersCount(n, deliverCount + 1, pick, deliver) % MOD) % MOD;
                deliver[idx] = 0;
            }
        }

        return totalSequences % MOD;
    }
public:
    int countOrders(int n) {
        vector<int> pick(n + 1, 0), deliver(n + 1, 0);
        return calculateTotalOrdersCount(n, 0, pick, deliver);
    }
};


// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
    const int MOD = 1e9 + 7;

    int calculateTotalOrderCount(int n) {
        if (n == 1) {
            return 1;
        }
        
        int totalSubsequences = ((long long) calculateTotalOrderCount(n - 1)) % MOD;
        totalSubsequences = ((long long) totalSubsequences * (2 * n - 1)) % MOD;
        totalSubsequences = ((long long) totalSubsequences * n) % MOD;

        return totalSubsequences;
    }
public:
    int countOrders(int n) {
        return calculateTotalOrderCount(n);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int countOrders(int n) {
        int prev = 1;

        for (int idx = 2; idx <= n; idx++) {
            int curr = ((long long) prev) % MOD;
            curr = ((long long) curr * (2 * idx - 1)) % MOD;
            curr = ((long long) curr * idx) % MOD;

            prev = curr;
        }
        return prev;
    }
};