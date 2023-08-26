// Fraction pairs with sum 1
// MediumAccuracy: 54.94%Submissions: 4K+Points: 4

// Given a list of N fractions, represented as two lists numerator and denominator, the task is to determine the count of pairs of fractions whose sum equals 1.

// Example 1:

// Input:
// N = 4
// numerator = [1, 2, 2, 8]
// denominator = [2, 4, 6, 12]
// Output:
// 2
// Explanation:
// Fractions 1/2 and 2/4 sum to 1. Similarly fractions 2/6 and 8/12 sum to 1. So there are 2 pairs of fractions which sum to 1.

// Example 2:

// Input:
// N = 5
// numerator = [3, 1, 12, 81, 2]
// denominator = [9, 10, 18, 90, 5]
// Output:
// 2
// Explanation:
// Fractions 3/9 and 12/18 sum to 1. Similarly fractions 1/10 and 81/90 sum to 1. So there are 2 pairs of fractions which sum to 1.

// Your task:
// You don't need to read input or print anything. Your task is to complete the function countFractions() which take integer N and arrays numerator and denominator of size N as arguments, and returns an integer.

// Expected Time Complexity: O(N*log(N))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <=105
// 1 <= numerator[i] <= denominator[i] <= 109

// Time Complexity : O(N)
// Space Complexity : O(2N)

class Solution
{
    public:
     int countFractions(int n, int numerator[], int denominator[]) {
        vector<double> fractions;
        
        for (int idx = 0; idx < n; idx++) {
            fractions.push_back(((double) numerator[idx] / (double) denominator[idx]));
        }
        
        unordered_map<string, int> tracker;
        int cnt = 0;

        for (auto fraction : fractions) {
            if (tracker.find(to_string(fraction)) != tracker.end()) {
                cnt += tracker[to_string(fraction)];
            }

            tracker[to_string(1.0 - fraction)]++;
        }

        return cnt;
    }
};


// Time Complexity : O(N*LogN)
// Space Complexity : O(N)

class Solution
{
    public:
     int countFractions(int n, int numerator[], int denominator[]) {
        map<pair<int, int>, int> tracker;

        int cnt = 0;

        for (int idx = 0; idx < n; idx++) {
            int gcd = __gcd(numerator[idx], denominator[idx]);
            int x = numerator[idx] / gcd, y = denominator[idx] / gcd;
            
            if (tracker.find({y - x, y}) != tracker.end()) {  // 1 - x / y => y - x / y
            	                                              // num : y - x, denom : y
                cnt += tracker[{y - x, y}];
            }

            tracker[{x, y}]++;   // storing num and denom 
                                 // such that they don't have any common divisor
        }

        return cnt;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution
{
    public:
     int countFractions(int n, int numerator[], int denominator[]) {
        unordered_map<double, int> tracker;
        int cnt = 0;

        for (int idx = 0; idx < n; idx++) {
            double t1 = (double) numerator[idx] / (double) denominator[idx];
            double t2 = ((double) denominator[idx] - (double) numerator[idx]) / (double) denominator[idx];
            
            if (tracker.find(t2) != tracker.end()) {
                cnt += tracker[t2];
            }

            tracker[t1]++;
        }

        return cnt;
    }
};