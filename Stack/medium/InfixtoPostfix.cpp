// Infix to Postfix
// MediumAccuracy: 52.94%Submissions: 62K+Points: 4
// Register for Mega Job-A-Thon For Experienced Professionals on 21st July | Apply to 15+ Companies

// Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

//     Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
//     Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
//     Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 

// Example 1:

// Input: str = "a+b*(c^d-e)^(f+g*h)-i"
// Output: abcd^e-fgh*+^*+i-
// Explanation:
// After converting the infix expression 
// into postfix expression, the resultant 
// expression will be abcd^e-fgh*+^*+i-

// Example 2:

// Input: str = "A*(B+C)/D"
// Output: ABC+*D/
// Explanation:
// After converting the infix expression 
// into postfix expression, the resultant 
// expression will be ABC+*D/
 

// Your Task:
// This is a function problem. You only need to complete the function infixToPostfix() that takes a string(Infix Expression) as a parameter and returns a string(postfix expression). The printing is done automatically by the driver code.

// Expected Time Complexity: O(|str|).
// Expected Auxiliary Space: O(|str|).

// Constraints:
// 1 ≤ |str| ≤ 105

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
    unordered_map<char, int> precedence = {{'(', 0}, {'-', 1}, {'+', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
public:
    string infixToPostfix(string s) {
        int n = s.size();
        
        stack<char> st;
        string postfix = "";
    
        for (int idx = 0; idx < n; idx++) {
            if ((s[idx] >= 'A' && s[idx] <= 'Z') || (s[idx] >= 'a' && s[idx] <= 'z') || (s[idx] >= '0' && s[idx] <= '9')) {
                postfix += s[idx];
            }
            else {
                if (s[idx] == '(')
                    st.push(s[idx]);
                else if (s[idx] == ')') {
                    while (!st.empty() && st.top() !='(') {
                        postfix += st.top();
                        st.pop();
                    }
                    
                    st.pop();
                }
                else {
                    while (!st.empty() && (precedence[s[idx]] <= precedence[st.top()])) {
                        postfix += st.top();
                        st.pop();
                    }
                    
                    st.push(s[idx]);
                }
            }
        }
        
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }
        
        return postfix;
    }
};