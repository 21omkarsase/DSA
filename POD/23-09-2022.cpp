// Geek has a string Sof size Nconsisting of characters from '0'to '9'. He wants to minimise the length of the string. In each minimising operation, geek can remove any two consecutive characters if they are of the form {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"}.
// Find the minimum possible length of the string after applying minimising operations. 
 

// Example 1:

// Input: 
// N = 5 
// S = "12213"
// Output: 1
// Explanation: Geek can get the string of 
// length 1 in two minimising operation,
// In 1st operation Geek will remove "12" 
// from "12213" then Geek left with "213"
// In 2nd operation Geek will remove "21" 
// from "213" then Geek left with "3"
 

// Example 2:

// Input: 
// N = 4
// S = "1350"
// Output: 4
// Explanation: Can't remove any character.
 

// Your Task:  
// You don't need to read input or print anything. Complete the functionminLength() which takes N and S as input parameters and returns the the minimum possible length of the string.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space:O(N)
 

// Constraints:
// 1 ≤ N ≤ 105

//{ Driver Code Starts
//Initial template for C++
 
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int minLength(string s, int n) {
        stack<int>st;
        unordered_map<string,int>m;
        m["12"]=1 ; m["21"]=1 ; m["34"]=1 ; m["43"]=1 ; m["56"]=1 ; m["65"]=1 ; m["78"]=1 ; m["87"]=1 ; m["09"]=1 ; m["90"]=1;
        
        for(int i=0;i<n;i++){
            if(st.empty())
                st.push(s[i]);
            else{
                string temp="";
                temp+=(st.top());
                temp+=(s[i]);
                if(m.find(temp)!=m.end())
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        return st.size();
    } 
};


//{ Driver Code Starts.

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends