// Sum of divisors
// BasicAccuracy: 66.77%Submissions: 1190Points: 1
// Given a natural number n, calculate sum of all its proper divisors. A proper divisor of a natural number is the divisor that is strictly less than the number.

// Example 1:

// Input: n = 10
// Output: 8 
// Explanation: Proper divisors 1 + 2 + 5 = 8. 

// Example 2:

// Input: n = 6
// Output: 6
// Explanation: Proper divisors 1 + 2 + 3 = 6. 

// Your Task:  
// You dont need to read input or print anything. Complete the function divSum() which takes n as input parameter and returns sum of proper divisors of n.

// Expected Time Complexity: O(sqrt(n))
// Expected Auxiliary Space: O(1)

// Constraints:
// 2<= n <=106

// View Bookmarked Problems 
// Topic Tags
// Mathematicalnumber-theory

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int divSum(long long int n){    //o(N)
        long long sum=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(i*i==n){
                    sum+=i;
                }else{
                    sum+=(n/i);
                    sum+=i;   
                }
            }
        }
        return sum-n;
        
        // long long sum=0;set<long long>s;
        // for(int i=1;i*i<=n;i++){
        //     if(n%i==0){
        //       s.insert(i);
        //       s.insert(n/i);                     time complexity o(lon2n)
        //     }
        // }
        // for(auto i:s){
        //     sum+=i;
        // }
        // return sum-n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout<<ob.divSum(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends