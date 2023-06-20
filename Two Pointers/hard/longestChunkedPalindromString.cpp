// 1147. Longest Chunked Palindrome Decomposition
// Hard
// 591
// 27
// Companies

// You are given a string text. You should split it to k substrings (subtext1, subtext2, ..., subtextk) such that:

//     subtexti is a non-empty string.
//     The concatenation of all the substrings is equal to text (i.e., subtext1 + subtext2 + ... + subtextk == text).
//     subtexti == subtextk - i + 1 for all valid values of i (i.e., 1 <= i <= k).

// Return the largest possible value of k.

 

// Example 1:

// Input: text = "ghiabcdefhelloadamhelloabcdefghi"
// Output: 7
// Explanation: We can split the string on "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".

// Example 2:

// Input: text = "merchant"
// Output: 1
// Explanation: We can split the string on "(merchant)".

// Example 3:

// Input: text = "antaprezatepzapreanta"
// Output: 11
// Explanation: We can split the string on "(a)(nt)(a)(pre)(za)(tep)(za)(pre)(a)(nt)(a)".

 

// Constraints:

//     1 <= text.length <= 1000
//     text consists only of lowercase English characters.

// Accepted
// 20.7K
// Submissions
// 35.1K
// Acceptance Rate
// 59.1%

// Time Complexity : O(N^2) 
// Space Complexity : O(N)

class Solution {
    bool checkForSameStrings(string leftStr, string rightStr){
        int n = leftStr.size();
        int start = 0, end = n - 1;

        while(start < n && end >= 0){
            if(leftStr[start++] != rightStr[end--])
                return false;
        }
        
        return true;
    }
public:
    int longestDecomposition(string text) {
        int n = text.size();
        int leftIdx = 0, rightIdx = n - 1;
        
        string leftStr = "", rightStr = "";
        int totalPalindromes = 0;
        while(leftIdx < rightIdx) {
            leftStr += text[leftIdx++];
            rightStr += text[rightIdx--];

            if(checkForSameStrings(leftStr, rightStr)) {
                totalPalindromes += 2;
                leftStr = "", rightStr = "";
            }
        }

        if(leftStr != rightStr || rightIdx - leftIdx == 0)
            totalPalindromes += 1;

        return totalPalindromes;
    }
};

// Time Complexity : O(N(2N)) 
// Space Complexity : O(N)

class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        int leftIdx = 0, rightIdx = n - 1;
        
        string leftStr = "", rightStr = "";
        int totalPalindromes = 0;
        while(leftIdx < rightIdx) {
            leftStr += text[leftIdx++];
            rightStr = text[rightIdx--] + rightStr;

            if(leftStr == rightStr){
                totalPalindromes += 2;
                leftStr = "", rightStr = "";
            }
        }

        if(leftStr != rightStr || rightIdx - leftIdx == 0)
            totalPalindromes += 1;

        return totalPalindromes;
    }
};