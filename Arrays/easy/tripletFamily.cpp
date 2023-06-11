// Given an array A of integers. Find three numbers such that sum of two elements equals the third element and return the triplet in a container result, if no such triplet is found return the container as empty.

// Input:
// First line of input contains number of testcases. For each testcases there will two lines. First line contains size of array and next line contains array elements.

// Output:
// For each test case output the triplets, if any triplet found from the array, if no such triplet is found, output -1.

// Your Task: Your task is to complete the function to find triplet and return container containing result.

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 103
// 0 <= Ai <= 105

// Example:
// Input:
// 3
// 5
// 1 2 3 4 5
// 3
// 3 3 3
// 6
// 8 10 16 6 15 25

// Output:
// 1
// -1
// 1

// Explanation:
// Testcase 1:
// Triplet Formed: {2, 1, 3}
// Hence 1
// Test Case 2:
// Triplet Formed: {}
// Hence -1
// Test Case 3:
// Triplet Formed: {10, 15, 25}
// Hence 1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> findTriplet(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> res = findTriplet(arr, n);
        if (res.size() != 3)
            cout << "-1\n";
        else
        {
            sort(res.begin(), res.end());
            if (res[0] + res[1] == res[2])
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}
// } Driver Code Ends

// function should return the triplet
// in a vector container defined as "vector<int> result"
// use result.push_back() to insert elements in the
// container
// if no such triplet is found,
// return the container result as empty
// Note: container should be contain 3 elements or 0 elements only.
vector<int> findTriplet(int arr[], int n)
{
    vector<int> result;
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[k] == arr[i] + arr[j])
                {
                    result.push_back(arr[i]);
                    result.push_back(arr[j]);
                    result.push_back(arr[k]);
                    return result;
                }
            }
        }
    }
    // reverse(arr, arr + n);
    // for (int i = 0; i < n; i++)
    // {
    //     int low = i + 1;
    //     int high = n - 1;
    //     while (low < high)
    //     {
    //         if (arr[i] = arr[low] + arr[high])
    //         {
    //             result.push_back(arr[i]);
    //             result.push_back(arr[low]);
    //             result.push_back(arr[high]);
    //         }
    //         else if (arr[i] > arr[low] + arr[high])
    //         {
    //             low++;
    //         }
    //         else
    //         {
    //             high--;
    //         }
    //     }
    // }
    // return result;
}