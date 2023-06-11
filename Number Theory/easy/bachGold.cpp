// A. Bachgold Problem
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Bachgold problem is very easy to formulate. Given a positive integer n represent it as a sum of maximum possible number of prime numbers. One can prove that such representation exists for any integer greater than 1.

// Recall that integer k is called prime if it is greater than 1 and has exactly two positive integer divisors — 1 and k.

// Input
// The only line of the input contains a single integer n (2 ≤ n ≤ 100 000).

// Output
// The first line of the output contains a single integer k — maximum possible number of primes in representation.

// The second line should contain k primes with their sum equal to n. You can print them in any order. If there are several optimal solution, print any of them.

// Examples
// inputCopy
// 5
// outputCopy
// 2
// 2 3
// inputCopy
// 6
// outputCopy
// 3
// 2 2 2

// We need represent integer number N (1 < N) as a sum of maximum possible number of prime numbers, they don’t have to be different.

// If N is even number, we can represent it as sum of only 2 - minimal prime number. It is minimal prime number, so number of primes in sum is maximal in this case.

// If N is odd number, we can use representing of N - 1 as sum with only 2 and replace last summand from 2 to 3.

// Using of any prime P > 3 as summand is not optimal, because it can be replaced by more than one 2 and 3.

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    cout << n / 2 << endl;

    int i = 1;
    while (i <= ((n / 2) - 1))
    {
        cout << 2 << " ";
        i++;
    }

    if (!(n & 1))
    {
        cout << 2 << endl;
    }
    else
        cout << 3 << endl;

    return 0;
}