// B. Ordinary Numbers
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Let's call a positive integer n ordinary if in the decimal notation all its digits are the same. For example, 1, 2 and 99 are ordinary numbers, but 719 and 2021 are not ordinary numbers.

// For a given number n, find the number of ordinary numbers among the numbers from 1 to n.

// Input
// The first line contains one integer t (1≤t≤104). Then t test cases follow.

// Each test case is characterized by one integer n (1≤n≤109).

// Output
// For each test case output the number of ordinary numbers among numbers from 1 to n.

// Example
// inputCopy
// 6
// 1
// 2
// 3
// 4
// 5
// 100
// outputCopy
// 1
// 2
// 3
// 4
// 5
// 18

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;cin>>n;
	int cnt=0;
	for(ll i=1;i<=n;i=i*10+1){  //i*=i+1 !== i=i*i+1
		for(int d=1;d<=9;d++){
			if(i*d<=n)cnt++;
		}
	}
	cout<<cnt<<endl;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--){
		solve();
	}
    return 0;
}