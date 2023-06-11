// Common Divisors
// BasicAccuracy: 73.73%Submissions: 3170Points: 1
// Given two integer numbers a and b, the task is to find count of all common divisors of given numbers.

// Example 1:

// Input: a = 12, b = 24
// Output: 6 
// Explanation: all common divisors 
// are 1, 2, 3, 4, 6 and 12.

// Example 2:

// Input: a = 3, b = 17
// Output: 1
// Explanation: all common divisors are 1.

// Your Task:  
// You dont need to read input or print anything. Complete the function commDiv() which takes n as input parameter and returns the number of common divisors.

// Expected Time Complexity: O(sqrt(n))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<= a,b <=1000

// View Bookmarked Problems 
// Topic Tags
// Mathematicalnumber-theory

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

//*******************// higher time complexity**************************
//*******************// higher space complexity**************************

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int commDiv(long long int a,long long int b) {
        unordered_map<int,int>m1;
        unordered_map<int ,int>m2;
        
        for(int i=1;i<=sqrt(a);i++){
            if(a%i==0){
                m1[i]=m1[i];
                m1[a/i]=m1[a/i];
            }
        }
        
        for(int i=1;i<=sqrt(b);i++){
            if(b%i==0){
                m2[i]=m2[i];
                m2[b/i]=m2[b/i];
            }
        }
        
        long long cnt=0;
        for(auto i:m1){
            if(m2.find(i.first)!=m2.end()){
                cnt++;
            }
        }
        return cnt;
    }
};

//*******************optimal********************using gcd
// long long int commDiv(long long int a,long long int b) {
//     long long int cnt=0;
//     int gcd=__gcd(a,b);                         Time complexity for __gcd is log2n
//     for(int i=1;i<=gcd;i++){
//         if(a%i==0 and b%i==0)cnt++;
//     }
//     return cnt;
// }

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int a, b;
        cin >> a >> b;
        Solution ob;
        cout<<ob.commDiv(a, b)<<endl;
    }
    return 0;
}

// } Driver Code Ends