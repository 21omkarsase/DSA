// 20. Valid Parentheses
// Easy
// 20.1K
// 1.2K
// Companies

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

//     Open brackets must be closed by the same type of brackets.
//     Open brackets must be closed in the correct order.
//     Every close bracket has a corresponding open bracket of the same type.

 

// Example 1:

// Input: s = "()"
// Output: true

// Example 2:

// Input: s = "()[]{}"
// Output: true

// Example 3:

// Input: s = "(]"
// Output: false

 

// Constraints:

//     1 <= s.length <= 104
//     s consists of parentheses only '()[]{}'.

// Accepted
// 3.4M
// Submissions
// 8.4M
// Acceptance Rate
// 40.4%

class Solution {
public:
    bool isMatch(char a, char b){
        if((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
            return true;
        return false;
    }
    bool isValid(string s) {
        int top = -1;
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            if(top < 0 || !isMatch(s[top], s[i]))
                s[++top] = s[i];
            else top--;
        }

        return top == -1;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else{
                if(s[i] == ')'){
                    if(st.empty() || st.top() != '(')
                        return false;
                    else st.pop();
                }
                else if(s[i] == ']'){
                    if(st.empty() || st.top() != '[')
                        return false;
                    else st.pop();
                }
                else if(s[i] == '}'){
                    if(st.empty() || st.top() != '{')
                        return false;
                    else st.pop();
                }
            }
        }

        if(!st.empty())
            return false;

        return true;
    }
};