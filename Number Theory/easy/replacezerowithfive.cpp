Replace all 0's with 5
SchoolAccuracy: 50.61%Submissions: 30362Points: 0
Given a number N. The task is to complete the function convertFive() which replace all zeros in the number with 5 and returns the number.

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T testcases follow. Each testcase contains a single integer N denoting the number.

Output:
The function will return integer where all zero's are converted to 5.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function convertFive().

Constraints:
1 <= T <= 103
1 <= N <= 104

Example:
Input
2
1004
121

Output
1554
121

Explanation:
Testcase 1:  At index 1 and 2 there is 0 so we replace it with 5.
Testcase 2: There is no ,0 so output will remain same.

View Bookmarked Problems 
Company Tags
Amazon
Topic Tags
Mathematicalnumber-theory

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Driver program to test above function

// } Driver Code Ends
class Solution{
  public:
    /*you are required to complete this method*/
    int convertFive(int n)
    {
        // string s=to_string(n);
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='0')s[i]='5';
        // }
        
        // return stoi(s);
        
        int temp=0;
        while(n){
            int ld=n%10;
            if(ld==0)ld=5;
            
            temp=temp*10+ld;
            n/=10;
        }
        
        int rn=0;
        while(temp){
            int ld=temp%10;
            rn=rn*10+ld;
            temp/=10;
        }
        
        return rn;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Solution obj;
    	cout<<obj.convertFive(n)<<endl;
    }
}
// } Driver Code Ends