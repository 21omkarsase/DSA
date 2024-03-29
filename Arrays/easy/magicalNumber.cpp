// Your friend loves magic and he has coined a new term - "Magical number". To perform his magic, he needs that Magic number. There are N number of people in the magic show, seated according to their ages in an ascending order. Magical number is that seat no. where the person has the same age as that of the given seat number.
// Help your friend in finding out that "Magical number"

// Input:
// The first line of input contains an integer T denoting the number of test cases.
// The first line of each test case is N, size of an array.
// The second line of each test case contains N input A[].

// Output:

// Print "Magical Number"
// Print "-1" when index value does not match with value.

// Constraints:

// 1 ≤ T ≤ 100
// 1 ≤ N ≤ 1000
// -1000 ≤ A[i] ≤ 1000

// Example:
// Input:
// 1
// 10
// -10 -1 0 3 10 11 30 50 100 150

// Output:
// 3

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int low, int high);
int main()
{
	int test = 0;
	cin >> test;
	while (test--)
	{
		int n, i;
		cin >> n;
		int a[n];
		for (i = 0; i < n; i++)
			cin >> a[i];

		cout << binarySearch(a, 0, n - 1) << endl;

		// cout<<"\n\n";
	}
}
// } Driver Code Ends

int binarySearch(int arr[], int low, int high)
{
	// add code here.
	while (low <= high)
	{
		int m = (low + high) / 2;
		if (arr[m] > m)
		{
			high = m - 1;
		}
		else if (arr[m] < m)
		{
			low = m + 1;
		}
		else
		{
			return m;
		}
	}

	return -1;
}