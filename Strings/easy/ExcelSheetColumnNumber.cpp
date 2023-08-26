// 171. Excel Sheet Column Number
// Easy
// 4.4K
// 345
// Companies

// Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

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

// Input: columnTitle = "A"
// Output: 1

// Example 2:

// Input: columnTitle = "AB"
// Output: 28

// Example 3:

// Input: columnTitle = "ZY"
// Output: 701

 

// Constraints:

//     1 <= columnTitle.length <= 7
//     columnTitle consists only of uppercase English letters.
//     columnTitle is in the range ["A", "FXSHRXW"].

// Accepted
// 622K
// Submissions
// 992.7K
// Acceptance Rate
// 62.7%

// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size(), ans = 0;

        for (int idx = 0; idx < n; idx++) {
            ans = ans * 26 + (columnTitle[idx] - 'A' + 1);
        }

        return ans;
    }
};

