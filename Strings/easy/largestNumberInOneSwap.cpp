// Given a non-negative number N in the form of a string.Find the largest number that can be formed by swapping two characters at most once.

// Example 1:

// Input:
// N=768
// Output:
// 867
// Explanation:
// Swapping the 1st and 3rd
// characters(7 and 8 respectively),
// gives the largest possible number.
// Example 2:

// Input:
// N=333
// Output:
// 333
// Explanation:
// Performing any swaps gives the
// same result i.e 333.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function LargestSwap() which takes the string N as input parameter and returns the maximum possible string possible with at most one swap.

// Expected Time Complexity:O(|N|)
// Expected Auxillary Space:O(1)

// Constraints:
// 1<=|N|<=105

// { Driver Code Starts
// initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User functiom template for C++

class Solution
{
public:
    string LargestSwap(string S)
    {
        int k = 0;
        while (k < S.length())
        {
            int j = k;
            char ch = S[k];
            for (int i = S.length() - 1; i > k; i--)
            {
                if (ch < S[i])
                {
                    ch = S[i];
                    j = i;
                }
            }
            if (k != j)
            {
                swap(S[k], S[j]);
                return S;
            }
            else
            {
                k++;
            }
        }
        return S;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string N;
        cin >> N;
        Solution ob;
        cout << ob.LargestSwap(N) << endl;
    }
    return 0;
} // } Driver Code Ends

// **********************TLI***********************
// string LargestSwap(string S) {
//         string sor=S;
//         int len=S.length();
//         sort(sor.begin(),sor.end(),greater<int>());
//         for(int i=0;i<len;i++){
//             if(S[i]!=sor[i]){
//                 string next=S.substr(i+1);
//                 int idx=S.find_last_of(sor[i]);
//                 char ch=S[i];
//                 S[i]=sor[i];
//                 S[idx]=ch;
//                 return S;
//             }
//         }
//     }