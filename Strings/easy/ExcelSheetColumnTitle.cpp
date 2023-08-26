// 168. Excel Sheet Column Title
// Easy
// 4.7K
// 648
// Companies

// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...

 

// Example 1:

// Input: columnNumber = 1
// Output: "A"

// Example 2:

// Input: columnNumber = 28
// Output: "AB"

// Example 3:

// Input: columnNumber = 701
// Output: "ZY"

 

// Constraints:

//     1 <= columnNumber <= 231 - 1

// Accepted
// 432.6K
// Submissions
// 1.1M
// Acceptance Rate
// 37.9%

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        int num = columnNumber;

        while (num) {
            num--;
            
            ans += ('A' + num % 26);
            num /= 26;
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};


class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        int num = columnNumber;

        while (num) {
            int ld = num % 26;

            if (ld == 0) {
                ans += 'Z';
                num /= 26;
                num--;
            }
            else {
                ans += ('A' + ld - 1);
                num /= 26;
            }
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
