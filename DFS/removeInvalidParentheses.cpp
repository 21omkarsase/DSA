// 301. Remove Invalid Parentheses
// Hard
// 5.5K
// 263
// Companies

// Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

// Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

 

// Example 1:

// Input: s = "()())()"
// Output: ["(())()","()()()"]

// Example 2:

// Input: s = "(a)())()"
// Output: ["(a())()","(a)()()"]

// Example 3:

// Input: s = ")("
// Output: [""]

 

// Constraints:

//     1 <= s.length <= 25
//     s consists of lowercase English letters and parentheses '(' and ')'.
//     There will be at most 20 parentheses in s.

// Accepted
// 382.8K
// Submissions
// 811.1K
// Acceptance Rate
// 47.2%

class Solution {
    bool isMatch(char a, char b){
        if((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
            return true;
        return false;
    }

    bool checkForValidParentheses(string s) {
        int top = -1;
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                continue;
            if(top < 0 || !isMatch(s[top], s[i]))
                s[++top] = s[i];
            else top--;
        }

        return top == -1;
    }

    void validParenthesesCount(int n, int count, string s, map<int, unordered_set<string>> &umap){
        if(n < -1) return;
        
        if(checkForValidParentheses(s)){
            umap[count].insert(s);
            if(n <= -1) return;
        }

        validParenthesesCount(n - 1, count + 1, s.substr(0, n) + s.substr(n + 1), umap);
        validParenthesesCount(n - 1, count, s, umap);
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        map<int, unordered_set<string>> umap;
        validParenthesesCount(n - 1, 0, s, umap);

        vector<string> ans;
        if(umap.size() == 0) return ans;

        for(auto p : umap){
            for(auto str : p.second){
                ans.push_back(str);
            }
            break;
        }

        return ans;
    }
};


class Solution {
    int getMinRemoval(string s) 
    {
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == ')') {
                if(st.size() == 0 || st.top() == ')')
                    st.push(s[i]);
                else if(st.top() == '(') 
                    st.pop();
            }
        } 

        return st.size();
    }

    void validParenthesesCount(int mr, string s, unordered_map<string, bool> &validStrs){
        if(validStrs.find(s) != validStrs.end())
            return;
        
        validStrs[s] = true;
        if(mr == 0){
            if(getMinRemoval(s) == 0)
                validStrs[s] = false;
            return;
        }

        for(int i = 0; i < s.size(); i++){
            validParenthesesCount(mr - 1, s.substr(0, i) + s.substr(i + 1), validStrs);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        unordered_map<string, bool> validStrs;
        int mr = getMinRemoval(s);
        validParenthesesCount(mr, s, validStrs);

        vector<string> ans;
        for(auto p : validStrs)
            if(!p.second)
                ans.push_back(p.first);
        
        return ans;
    }
};

class Solution {
    void getValidStrs(int n, int le, int re, int pair, string &s, string path, unordered_set<string> & validStrs){
        if(n == s.size()){
            if(le == 0 && re == 0 && pair == 0){
                validStrs.insert(path);
            }
            return;
        }

        if(s[n] != '(' && s[n] != ')'){
            return getValidStrs(n + 1, le, re, pair, s, path + s[n], validStrs);
        }

        if(s[n] == '('){
            getValidStrs(n + 1, le, re, pair + 1, s, path + s[n], validStrs);
            if(le > 0)
                getValidStrs(n + 1, le - 1, re, pair, s, path, validStrs        }else if(s[n] == ')'){
            if(pair > 0));

                getValidStrs(n + 1, le, re, pair - 1, s, path + s[n], validStrs);
            if(re > 0)
                getValidStrs(n + 1, le, re - 1, pair, s, path, validStrs);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftExtras = 0, rightExtras = 0;

        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                leftExtras++;
            else if(s[i] == ')'){
                if(leftExtras > 0)
                    leftExtras--;
                else rightExtras++;
            }
        }
        
        unordered_set<string> validStrs;
        getValidStrs(0, leftExtras, rightExtras, 0, s, "", validStrs);

        vector<string> ans;
        for(auto ele : validStrs){
            cout<<ele<<" ==> ";
            ans.push_back(ele);
        }

        return ans;
    }
};






