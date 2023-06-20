// 2193. Minimum Number of Moves to Make Palindrome
// Hard
// 808
// 65
// Companies

// You are given a string s consisting only of lowercase English letters.

// In one move, you can select any two adjacent characters of s and swap them.

// Return the minimum number of moves needed to make s a palindrome.

// Note that the input will be generated such that s can always be converted to a palindrome.

 

// Example 1:

// Input: s = "aabb"
// Output: 2
// Explanation:
// We can obtain two palindromes from s, "abba" and "baab". 
// - We can obtain "abba" from s in 2 moves: "aabb" -> "abab" -> "abba".
// - We can obtain "baab" from s in 2 moves: "aabb" -> "abab" -> "baab".
// Thus, the minimum number of moves needed to make s a palindrome is 2.

// Example 2:

// Input: s = "letelt"
// Output: 2
// Explanation:
// One of the palindromes we can obtain from s in 2 moves is "lettel".
// One of the ways we can obtain it is "letelt" -> "letetl" -> "lettel".
// Other palindromes such as "tleelt" can also be obtained in 2 moves.
// It can be shown that it is not possible to obtain a palindrome in less than 2 moves.

 

// Constraints:

//     1 <= s.length <= 2000
//     s consists only of lowercase English letters.
//     s can be converted to a palindrome using a finite number of moves.

// Accepted
// 18.4K
// Submissions
// 36K
// Acceptance Rate
// 51.1%

Time Complexity : O(n^2)
Space Complexity : O(1)

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();

        int start = 0, end = n - 1;
        int operations = 0;
        while(start < end){  //O(n / 2)
            if(s[start] != s[end]){
                int idx = s.find(s[end], start);  // O(n)
                int dist = idx - start;

                if(idx == end){
                    swap(s[end], s[end - 1]);
                    operations++;
                    continue;
                }

                while(dist--){                     // o(n - 1)
                    swap(s[idx], s[idx - 1]);
                    idx--;
                    operations++;
                }
            }

            start++, end--;
        }

        return operations;
    }
};