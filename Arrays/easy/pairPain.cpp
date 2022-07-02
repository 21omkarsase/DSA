#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    int ones=0;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]==1)
	        {
	            ones++;
	            cout<<ones<<endl;
	        }
	    }
	    cout<<n-ones<<endl;
	}
	return 0;
}
