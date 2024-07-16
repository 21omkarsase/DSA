// 726. Number of Atoms
// Solved
// Hard
// Topics
// Companies
// Hint

// Given a string formula representing a chemical formula, return the count of each atom.

// The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

// One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

//     For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.

// Two formulas are concatenated together to produce another formula.

//     For example, "H2O2He3Mg4" is also a formula.

// A formula placed in parentheses, and a count (optionally added) is also a formula.

//     For example, "(H2O2)" and "(H2O2)3" are formulas.

// Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

// The test cases are generated so that all the values in the output fit in a 32-bit integer.

 

// Example 1:

// Input: formula = "H2O"
// Output: "H2O"
// Explanation: The count of elements are {'H': 2, 'O': 1}.

// Example 2:

// Input: formula = "Mg(OH)2"
// Output: "H2MgO2"
// Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

// Example 3:

// Input: formula = "K4(ON(SO3)2)2"
// Output: "K4N2O14S4"
// Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.

 

// Constraints:

//     1 <= formula.length <= 1000
//     formula consists of English letters, digits, '(', and ')'.
//     formula is always valid.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 144.2K
// Submissions
// 221.2K
// Acceptance Rate
// 65.2%


class Solution {
    static bool sortFormulaByAtom(const string& a, const string& b) {
        return a < b;
    }

public:
    string countOfAtoms(string formula) {
        int n = formula.size();

        string op = "", cl = "";
        op += '(';
        cl += ')';

        stack<string> st;

        for (int idx = 0; idx < n; idx++) {
            if (formula[idx] == ')') {
                vector<string> temp;

                while (!st.empty() && st.top() != op) {
                    temp.push_back(st.top());
                    st.pop();
                }
                
                st.pop();
                
                reverse(temp.begin(), temp.end());
                string num = "";

                idx++;

                while (idx < n && formula[idx] >= '0' && formula[idx] <= '9') {
                    num += formula[idx];
                    idx++;
                }

                if (idx < n) {
                    idx--;
                }

                int cnt = 0;

                if (num == "") {
                    cnt = 1;
                }
                else {
                    cnt = stoi(num);
                }

                for (int it = 0; it < temp.size(); it += 2) {
                    string str = temp[it];
                    int times = stoi(temp[it + 1]);

                    st.push(str);
                    st.push(to_string(cnt * times));
                }
            }
            else if (formula[idx] == '(') {
                st.push("(");
            }
            else {
                idx++;

                string temp = "";
                temp += formula[idx - 1];

                while (idx < n && formula[idx] >= 'a' && formula[idx] <= 'z') {
                    temp += formula[idx];
                    idx++;
                }

                st.push(temp);

                if (idx >= n || !(formula[idx] >= '0' && formula[idx] <= '9')) {
                    string ones = "";
                    ones += '1';
                   
                    st.push(ones);

                    if (idx < n) {
                        idx--;
                    }
                }
                else if(idx < n && formula[idx] >= '0' && formula[idx] <= '9') {
                    string num = "";

                    while (idx < n && formula[idx] >= '0' && formula[idx] <= '9') {
                        num += formula[idx];
                        idx++;
                    }

                    if (idx < n) {
                        idx--;
                    }

                    int cnt = stoi(num);

                    st.push(to_string(cnt));
                }
            }
        }

        unordered_map<string, int> counter;
        vector<string> temp_str;

        while (!st.empty()) {
            string cnt = st.top();
            st.pop();
            
            string str = st.top();
            st.pop();

            counter[str] += (stoi(cnt));
        }

        for (auto m : counter) {
            temp_str.push_back(m.first);
        }

        reverse(temp_str.begin(), temp_str.end());

        sort(temp_str.begin(), temp_str.end(), sortFormulaByAtom);
       
        string ans = "";

        for (auto temp : temp_str) {
            ans += temp;

            if (counter[temp] > 1) {
                ans += to_string(counter[temp]);
            }
        }

        return ans;
    }
};