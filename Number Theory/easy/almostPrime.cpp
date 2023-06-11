// A. Almost Prime
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// A number is called almost prime if it has exactly two distinct prime divisors. For example, numbers 6, 18, 24 are almost prime, while 4, 8, 9, 42 are not. Find the amount of almost prime numbers which are between 1 and n, inclusive.

// Input
// Input contains one integer number n (1 ≤ n ≤ 3000).

// Output
// Output the amount of almost prime numbers between 1 and n, inclusive.

// Examples
// inputCopy
// 10
// outputCopy
// 2
// inputCopy
// 21
// outputCopy
// 8


#include<bits/stdc++.h>
using namespace std;
#define N 10000

int main(){
	int n;cin>>n;

    vector<bool>isPrime(N,1);

    isPrime[0]=isPrime[1]=0;
    for(int i=2;i*i<=n;i++){
    	if(isPrime[i]){
    		for(int j=i*i;j<=n;j+=i){
    			isPrime[j]=0;
    		}
    	}
    }

    
    int final=0;
    for(int j=6;j<=n;j++){
    	int cnt=0;
    	for(int i=2;i<j;i++){
    		if(isPrime[i] and j%i==0){
    			cnt++;
    		}
	    }
	    if(cnt==2){
	    	final++;
	    }
    }
    
    cout<<final<<endl;
    
	return 0;
}