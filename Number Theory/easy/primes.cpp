// B. Primes
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// A prime number is a natural number greater than 1 and has exactly 2 divisors which are 1 and the number itself.

// You are given a prime number n, find any 2 prime numbers a and b such that a+b=n or state that no such pair of primes exists.

// Input
// The input contains a single prime number n(2≤n≤107).

// Output
// If there doesn't exist any 2 primes such that their summation is equal to n then print -1, otherwise print the 2 primes on a single line separated by a space.

// Examples
// inputCopy
// 5
// outputCopy
// 2 3
// inputCopy
// 11
// outputCopy
// -1

#include<bits/stdc++.h>
using namespace std;

#define N 10000001

int main(){
	int n;cin>>n;

	// vector<bool>isPrime(N,0);
	// isPrime[0]=isPrime[1]=1;
	// for(int i=0;i*i<=n;i++){
	// 	if(!isPrime[i]){
	// 		for(int j=i*i;j<=n;j+=i){
	// 			isPrime[j]=1;
	// 		}
	// 	}
	// }

 //    int s=1,e=n-1;
 //    bool flag=false;
	// while(s<=e){
	// 	if(!isPrime[s] and !isPrime[e] and s+e==n){
	// 		flag=true;
	// 		cout<<s<<" "<<e<<endl;
	// 		break;
	// 	}else if(s+e>n)e--,s++;
	// 	else s++,e--;
	// }

	// if(!flag)cout<<-1<<endl;

	//OPTIMAL

	// PRIME NOs
	// 2 --> EVEN
	// REST ALL --> ODD

	// ODD=EVEN+ODD

	// THE ONLY EVEN PRIME NUMBER WE HAVE IS 2
	// SO WE CHECK IS (N-2) IS PRIME OR NOT
    
    bool flag=true;

	for(int i=2;i*i<=(n-2);i++){
		if((n-2)%i==0){
			flag=false;
			break;
		}
	}

	if(flag and (n-2)>2)cout<<2<<" "<<n-2<<endl;
	else cout<<-1<<endl;


	return 0;
}