// Largest number possible
// EasyAccuracy: 20.26%Submissions: 91K+Points: 2
// 100+ Candidates recieved offers in the last 3 months through Job-A-Thon. Your call is just a click away

// Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'. Return -1 if it is not possible.

// Example 1:

// Input: N = 2, S = 9
// Output: 90
// Explaination: It is the biggest number 
// with sum of digits equals to 9.

// Example 2:

// Input: N = 3, S = 20
// Output: 992
// Explaination: It is the biggest number 
// with sum of digits equals to 20.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function findLargest() which takes N and S as input parameters and returns the largest possible number. Return -1 if no such number is possible.

// Expected Time Complexity: O(N)
// Exepcted Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 104
// 0 ≤ S ≤ 105

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution{
public:
    string findLargest(int n, int sum){
        int minDigitsRequired = sum / 9 + (sum % 9 != 0);
        string s = "";
        
        if ((sum == 0 && n > 1 ) || n < minDigitsRequired) {
            return "-1";
        }
        
        for (int idx = 1; idx <= n; idx++) {
            s += '0';
        }
        
        for (int idx = 0; sum > 0 && idx < s.size(); idx++) {
            if (sum > 9) {
                s[idx] = '9';
                sum -= 9;
            }
            else {
                s[idx] = '0' + sum;
                sum = 0;
            }
        }
        
        return s;
    }
};