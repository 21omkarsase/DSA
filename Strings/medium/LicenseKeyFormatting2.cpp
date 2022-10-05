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