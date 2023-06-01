// 394. Decode String
// Medium
// 10.9K
// 498
// Companies

// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

 

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"

// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"

// Example 3:

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"

 

// Constraints:

//     1 <= s.length <= 30
//     s consists of lowercase English letters, digits, and square brackets '[]'.
//     s is guaranteed to be a valid input.
//     All the integers in s are in the range [1, 300].

// Accepted
// 646.1K
// Submissions
// 1.1M
// Acceptance Rate
// 58.0%

// *******************USING STACK*****************
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();

        stack<char> st;
        for(int i = 0; i < n; i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }else{
                string subStr = "";
                while(!st.empty() && st.top() != '['){
                    subStr = st.top() + subStr;
                    st.pop();
                }
                st.pop();

                string numStr = "";
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    numStr = st.top() + numStr;
                    st.pop();
                }
                for(int i = 0; i < stoi(numStr); i++){
                    for(auto ch : subStr){
                        st.push(ch);
                    }
                }
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
// The updated code uses a stack to simulate the decoding process. Let's analyze the time and space complexity of this code:

// Time Complexity:

//     The code uses a loop that iterates over each character in the input string s. Therefore, the time complexity of this loop is O(n), where n is the length of the input string.
//     Within the loop, there are two nested while loops that traverse the stack until certain conditions are met. The time complexity of these while loops depends on the size of the stack at any given point, which can vary.
//         The first while loop searches for the opening bracket '[' in the stack and retrieves the substring between the opening bracket and the current position. The number of iterations in this loop depends on the size of the stack, but it is important to note that the size of the stack decreases with each iteration.
//         The second while loop searches for the digits (0-9) in the stack and retrieves the number that precedes the substring. Similarly, the number of iterations in this loop depends on the size of the stack but decreases with each iteration.
//     Considering the worst-case scenario, where the stack contains all the characters of the input string, the maximum number of iterations in the nested while loops would be O(n), resulting in a total time complexity of O(n).

// Space Complexity:

//     The code uses a stack to store the characters during the decoding process. The space used by the stack can vary depending on the input string. In the worst-case scenario, where the stack contains all the characters of the input string, the space complexity would be O(n).
//     Additionally, the code uses a few additional variables (subStr, numStr, and ans) to store intermediate results and the final decoded string. These variables require additional space proportional to the length of the input string s, resulting in O(n) space complexity.
//     Therefore, the overall space complexity of the code is O(n).


// ******************************USING RECURSION****************************

class Solution {
public:
    string decodeString(string s) {
        int first = s.rfind('[');
        if(first == string::npos){
            return s;
        }

        int second = s.find(']', first + 1);

        int numIt = first - 1;
        string numStr = "";
        while(numIt >= 0 && isdigit(s[numIt])){
            numStr = s[numIt] + numStr;
            numIt--;
        }

        string before = s.substr(0, first - numStr.size());
        string after = s.substr(second + 1);

        string temp = s.substr(first + 1, second - first - 1);
        string middle = "";
        for(int i = 0 ; i < stoi(numStr); i++){
            middle += temp;
        }

        return decodeString(before + middle + after);
    }
};

// The total time complexity of the code, taking into account the .find and .rfind operations, remains O(n), where n is the length of the input string s. This is because the time complexity of the .find and .rfind operations is proportional to the length of the string.

// The recursive nature of the code does not change the overall time complexity since the recursive calls operate on substrings of the original input string, and the length of these substrings decreases by a constant factor in each recursive call.

// Therefore, the time complexity of the code remains O(n), considering both the recursive calls and the .find and .rfind operations.

// Space Complexity:

    // The space complexity of the code mainly depends on the recursive calls and the additional space used during the recursion.
    // In each recursive call, the code creates new strings (before, middle, after) by using the substr function. These strings have lengths proportional to the length of the input string s. Hence, in each recursive call, O(n) additional space is used.
    // The maximum depth of the recursion is determined by the number of nested brackets in the input string s. Therefore, the space complexity of the recursion is O(d), where d is the maximum depth of recursion.
    // Overall, the space complexity can be approximated as O(n + d), where n is the length of the input string s and d is the maximum depth of recursion.