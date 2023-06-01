// 17. Letter Combinations of a Phone Number
// Medium
// 15.1K
// 843
// Companies

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:

// Input: digits = ""
// Output: []

// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]

 

// Constraints:

//     0 <= digits.length <= 4
//     digits[i] is a digit in the range ['2', '9'].

// Accepted
// 1.6M
// Submissions
// 2.7M
// Acceptance Rate
// 56.9%

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) {
            vector<string>ev;
            return ev;
        }
        vector<char> pad[10];
        pad[2] = {'a', 'b', 'c'};
        pad[3] = {'d', 'e', 'f'};
        pad[4] = {'g', 'h', 'i'};
        pad[5] = {'j', 'k', 'l'};
        pad[6] = {'m', 'n', 'o'};
        pad[7] = {'p', 'q', 'r', 's'};
        pad[8] = {'t', 'u', 'v'};
        pad[9] = {'w', 'x', 'y', 'z'};

        vector<string> ans;
        string temp = "";
        
        for(auto ele : pad[digits[0] - 48]){
            temp += ele;
            if(n >= 2){
                for(auto ele : pad[digits[1] - 48]){
                    temp += ele;
                    if(n >= 3){
                        for(auto ele : pad[digits[2] - 48]){
                            temp += ele;
                            if(n >= 4){
                                for(auto ele : pad[digits[3] - 48]){
                                    temp += ele;
                                    ans.push_back(temp);
                                    temp.pop_back();
                                }
                            }else ans.push_back(temp);
                            temp.pop_back();
                        }
                    }
                    else ans.push_back(temp);
                    temp.pop_back();
                }
            }else ans.push_back(temp);
            temp.pop_back();
        }

        return ans;
    }
};

// *********************************************OR***********************************************afterclass Solution {
public:
    void getAllCombinations(int i, int n, string temp, string digits, vector<char> pad[], vector<string> &ans){
        if(i == n){
            ans.push_back(temp);
            return;
        }

        for(auto ch : pad[digits[i] - 48]){
            getAllCombinations(i + 1, n, temp + ch, digits, pad, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) {
            vector<string>ev;
            return ev;
        }
        vector<char> pad[10];
        pad[2] = {'a', 'b', 'c'};
        pad[3] = {'d', 'e', 'f'};
        pad[4] = {'g', 'h', 'i'};
        pad[5] = {'j', 'k', 'l'};
        pad[6] = {'m', 'n', 'o'};
        pad[7] = {'p', 'q', 'r', 's'};
        pad[8] = {'t', 'u', 'v'};
        pad[9] = {'w', 'x', 'y', 'z'};

        vector<string> ans;
        getAllCombinations(0, n, "", digits, pad, ans);

        return ans;
    }
};