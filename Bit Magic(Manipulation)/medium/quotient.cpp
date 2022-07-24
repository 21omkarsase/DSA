

// Division without using multiplication, division and mod operator
// MediumAccuracy: 59.78%Submissions: 8050Points: 4
// Given two integers dividend and divisor. Find the quotient after dividing dividend by divisor without using multiplication, division and mod operator.

// Example 1:

// Input:
// a = 10, b= 3
// Output: 3
// Exaplanation:
// 10/3 gives quotient as 3
// and remainder as 1.
// Example 2:

// Input:
// a = 43, b = -8
// Output: -5
// Explanation:
// 43/-8 gives quotient as -5 and
// remainder as 3.
// Your task:
// You don't have to read input or print anything. Your task is to complete the function divide() which takes two integers a and b as input and returns the quotient after dividing a by b.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints :
// -10^9 <= a,b <= 10^9
// View Bookmarked Problems
// Company Tags
// Microsoft

// ***********************TC = O(a / b);******************
// //{ Driver Code Starts
// //Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// //User function Template for C++

// class Solution
// {
//     public:
//     long long divide(long long dividend, long long divisor)
//     {
//         long long ans=0;
//         bool sign=true;
//         if((dividend<0 and divisor>0) or (dividend>0 and divisor<0))sign=false;
//         dividend=abs(dividend);
//         divisor=abs(divisor);
//         while(dividend>=divisor){
//             dividend-=divisor;
//             ans++;
//         }
//         if(sign)return ans;
//         else return ((-1)*ans);
//         return ans;
//     }
// };

// //{ Driver Code Starts.
// int main() {
// 	int t;
// 	cin >> t;

// 	while (t--)
// 	{

// 		long long a, b;
// 		cin >> a >> b;

// 		Solution ob;
// 		cout << ob.divide(a, b) << "\n";
// 	}

// 	return 0;
// }

// // } Driver Code Ends

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long divide(long long dividend, long long divisor)
    {
        long long result = 0;
        bool sign = true;
        if ((dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0))
            sign = false;
        dividend = abs(dividend);
        divisor = abs(divisor);

        while (dividend - divisor >= 0)
        {
            long long count = 0;
            while (dividend - (divisor << 1 << count) >= 0)
            {
                count++;
            }
            dividend = dividend - (divisor << count);
            result += 1 << count;
        }
        if (sign)
            return result;
        else
            return ((-1) * result);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        long long a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.divide(a, b) << "\n";
    }

    return 0;
}

// } Driver Code Ends