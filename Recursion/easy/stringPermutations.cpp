// String Permutations
// EasyAccuracy: 49.87%Submissions: 13836Points: 2
// Given a string S. The task is to find all permutations of a given string.

// Example 1:

// Input:
// S = ABC
// Output: ABC ACB BAC BCA CAB CBA 
// Example 2:

// Input:
// S = ABSG
// Output: ABGS ABSG AGBS AGSB ASBG ASGB
// BAGS BASG BGAS BGSA BSAG BSGA GABS
// GASB GBAS GBSA GSAB GSBA SABG SAGB
// SBAG SBGA SGAB SGBA
 

// Your Task:
// This is a function problem. You only need to complete the function permutation that takes S as parameter and returns the list of permutations in lexicographically increasing order. The newline is automatically added by driver code.

// Constraints:
// 1 ≤ size of string ≤ 5

// Expected Time Complexity: O(N * N!), N = length of string.
// Expected Auxiliary Space: O(1)

// View Bookmarked Problems 
// Company Tags
// AccoliteAmazonCiscoCitrixMAQ SoftwareOYO RoomsSamsung
// Topic Tags
// RecursionStrings



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    	
    void permute(string s,int l,int r,vector<string>&ans)
    {
    	int i;
    	if(l==r)ans.push_back(s);
    	else{
    	    for(i=l;i<=r;i++){
    	        swap(s[l],s[i]);
    	        permute(s,l+1,r,ans);
    	        swap(s[l],s[i]);
    	    }
    	}
    }
    
    vector<string> permutation(string s)
    {
    	vector<string>ans;
    	
    	permute(s,0,s.size()-1,ans);
    	
        string temp;
        for (int i = 0; i < ans.size()-1; ++i) {
            for (int j = 0; j < ans.size()-1 - i; ++j) {
                if (ans[j] > ans[j + 1]) {
                    temp = ans[j];
                    ans[j] = ans[j + 1];
                    ans[j + 1] = temp;
                }
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends

// //{ Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution{
//     public:

// 	int getFactorial(int n)
// 	{
// 	    return (n==1 || n==0) ? 1: n * getFactorial(n - 1);
// 	}
    	
//     void generatePermutations(string s,int n,int st,int en,int size,vector<string>&ans)
//     {
//     	if(ans.size()==size){
//     		return;
//     	}
    	
//     	if(st==1 and en==2){
//     		st=n-2,en=n-1;
//     	}
    	
//     	ans.push_back(s);
//     	if(st==1)en--;
//     	else st--;
//     	swap(s[st],s[en]);
//     	generatePermutations(s,n,st,en,size,ans);
//     }
    
//     vector<string> permutation(string s)
//     {
//     	vector<string>ans;
    	
//     	if(s.size()==2){
//     		string s1="",s2="";
//     		ans.push_back(s1+s[0]);
//     		ans.push_back(s2+s[1]);
//     	}else{
//     		int size=getFactorial(s.size())/s.size(),len=size;
// 	    	for(int i=0;i<s.length();i++){
// 	    		swap(s[0],s[i]);
// 	    		generatePermutations(s,s.size(),s.size()-2,s.size()-1,size,ans);
// 	    		swap(s[0],s[i]);
// 	    		size+=len;
// 	    	}
//     	}
    	
    	
//         string temp;
//         for (int i = 0; i < ans.size()-1; ++i) {
//             for (int j = 0; j < ans.size()-1 - i; ++j) {
//                 if (ans[j] > ans[j + 1]) {
//                     temp = ans[j];
//                     ans[j] = ans[j + 1];
//                     ans[j + 1] = temp;
//                 }
//             }
//         }
//         return ans;
//     }

// };

// //{ Driver Code Starts.

// int main()
// {
// 	int T;
// 	cin>>T;
// 	while(T--)
// 	{
// 		string S;
// 		cin>>S;
// 		Solution ob;
// 		vector<string> vec = ob.permutation(S);
// 		for(string s : vec){
// 		    cout<<s<<" ";
// 		}
// 		cout<<endl;
	
// 	}
// 	return 0;
// }
// // } Driver Code Ends