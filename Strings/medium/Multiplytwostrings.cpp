// Multiply two strings
// MediumAccuracy: 20.06%Submissions: 189K+Points: 4
// 15K students have upskilled themselves with our courses over the summer. Don't get left behind! Save extra 30% by enrolling today

// Given two numbers as strings s1 and s2. Calculate their Product.

// Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers.

// Example 1:

// Input:
// s1 = "0033"
// s2 = "2"
// Output:
// 66

// Example 2:

// Input:
// s1 = "11"
// s2 = "23"
// Output:
// 253

// Your Task: You don't need to read input or print anything. Your task is to complete the function multiplyStrings() which takes two strings s1 and s2 as input and returns their product as a string.

// Expected Time Complexity: O(n1* n2)
// Expected Auxiliary Space: O(n1 + n2); where n1 and n2 are sizes of strings s1 and s2 respectively.

// Constraints:
// 1 ≤ length of s1 and s2 ≤ 103

// Time Complexity : O(N*M)
// Space Complexity : O(N + M)

class Solution{
    string addition(const string &s1, const string &s2) {
        int n = s1.size(), m = s2.size();
        
        int carry = 0;
        string ans = "";
        
        int idx1 = n - 1, idx2 = m - 1;
        
        while (idx1 >= 0 || idx2 >= 0) {
            int sum = carry;
            
            if (idx1 >= 0) {
                sum += (s1[idx1] - '0');
                idx1--;
            }
            
            if (idx2 >= 0) {
                sum += (s2[idx2] - '0');
                idx2--;
            }
            
            ans += (sum % 10 + '0');
            carry = sum / 10;
        }
        
        while (carry) {
            ans += (carry % 10 + '0');
            carry /= 10;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    string multiplication(int zeros, const int &num, const string &s) {
        int n = s.size();
        
        int carry = 0;
        string ans = "";
        
        for (int idx = n - 1; idx >= 0; idx--) {
            int mul = carry + (num * (s[idx] - '0'));
            
            ans += (mul % 10 + '0');
            carry = mul / 10;
        }
        
        while (carry) {
            ans += (carry % 10 + '0');
            carry /= 10;
        }
        
        reverse(ans.begin(), ans.end());
        
        
        while (zeros--) {
            ans += '0';
        }
        
        return ans;
    }
  public:
    string multiplyStrings(string s1, string s2) {
        string ans = "";
        bool flag1 = false, flag2 = false;
        
        if (s1[0] == '-') {
            flag1 = true;
            s1 = s1.substr(1);
        }
        
        if (s2[0] == '-') {
            flag2 = true;
            s2 = s2.substr(1);
        }
        
        int n = s1.size(), m = s2.size();
        
        for (int idx = m - 1; idx >= 0; idx--) {
            string mul = multiplication(m - 1 - idx, s2[idx] - '0', s1);

            ans = addition(ans, mul);
        }
        
        int idx = 0;
        
        while (ans[idx] - '0' < 1) {
            idx++;
        }
        
        if((flag1 && !flag2) || (!flag1 && flag2)) {
            return '-' + ans.substr(idx);
        }
        
        return ans.substr(idx);
    }

};
