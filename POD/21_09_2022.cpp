// License Key Formatting
// MediumAccuracy: 32.68%Submissions: 2232Points: 4
// Given a string S that consists of only alphanumeric characters and dashes. The string is separated into N + 1 groups by N dashes. Also given an integer K. 

// We want to reformat the string S, such that each group contains exactly K characters, except for the first group, which could be shorter than K but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.

// Return the reformatted string.


// Example 1:

// Input: 
// S = "5F3Z-2e-9-w", K = 4
// Output: "5F3Z-2E9W"
// Explanation: The string S has been split into two
// parts, each part has 4 characters. Note that two
// extra dashes are not needed and can be removed.
// Example 2:

// Input:
// S = "2-5g-3-J", K = 2
// Output: "2-5G-3J"
// Explanation: The string s has been split 
// into three parts, each part has 2 characters 
// except the first part as it could
// be shorter as mentioned above.

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function ReFormatString() which takes a string S and an integer K as input and returns the reformatted string.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)


// Constraints:
// 1 ≤ S.length() ≤ 105
// 1 ≤ K ≤ 104

// View Bookmarked Problems 
// Company Tags
// Google

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
    string ReFormatString(string S, int k){
        string s="";
        for(int i=0;i<S.length();i++){
            if(S[i]!='-'){
                s+=S[i];
            }
        }

        cout<<s.size()<<" : size\n";
        
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' and s[i]<='z')
               s[i]-=32;
        }
        
        int l=s.length();
        if(l==0)
            return s;
        int rem=l%k;
        
        reverse(s.begin(),s.end());

        string ans="";
        int x=1;
        for(int i=0;i<s.size()-rem;i++){
            ans+=s[i];
            if(x==k){
                ans+='-';
                x=0;
            }
            x++;
        }

        for(int i=s.size()-rem;i<s.size();i++){
            ans+=s[i];
        }

        reverse(ans.begin(),ans.end());

        if(rem!=0)
            return ans;
        else
            return ans.substr(1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        int K;
        cin >> K;
        Solution ob;  
        string ans=ob.ReFormatString(S, K);
        cout<<ans;
        cout<<"\n";
    }
    return 0;
}

// } Driver Code Ends