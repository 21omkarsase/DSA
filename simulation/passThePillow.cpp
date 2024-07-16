// 2582. Pass the Pillow
// Solved
// Easy
// Topics
// Companies
// Hint

// There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

//     For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.

// Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

 

// Example 1:

// Input: n = 4, time = 5
// Output: 2
// Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
// After five seconds, the 2nd person is holding the pillow.

// Example 2:

// Input: n = 3, time = 2
// Output: 3
// Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
// After two seconds, the 3rd person is holding the pillow.

 

// Constraints:

//     2 <= n <= 1000
//     1 <= time <= 1000

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 135.4K
// Submissions
// 242.3K
// Acceptance Rate
// 55.9%

class Solution {
public:
    int passThePillow(int n, int time) {
        int idx = 1;
        bool flag = 1;

        while (time) {
            idx = flag ? idx += 1 : idx -= 1;

            if (idx == n) {
                flag = 0;
            }
            else if (idx == 1) {
                flag = 1;
            }

            time -= 1;
        }

        return idx;
    }
};

// class Solution:
//     def passThePillow(self, n: int, time: int) -> int:
//         flag = 1
//         idx = 1

//         while time:
//             idx = idx + 1 if flag else idx - 1

//             if idx == n:
//                 flag = 0
//             elif idx == 1:
//                 flag = 1

//             time -= 1
        
//         return idx


// class Solution:
//     def passThePillow(self, n: int, time: int) -> int:
//         n -= 1
//         rem, quot = time % n, time // n
        
//         if quot % 2 == 0:
//             return rem + 1
//         else:
//             return n - rem + 1