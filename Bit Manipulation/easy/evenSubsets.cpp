//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*Function to count subset with even sum
 * arr : array input
 * N : size of array
 */
class Solution
{
public:
    int countSumSubsets(int arr[], int N)
    {
        int len = pow(2, N) - 1;
        vector<vector<int>> subsets;
        for (int i = 1; i <= len; i++)
        {
            int j = 0;
            vector<int> subset;
            while (i)
            {
                if (i & (1 << j))
                {
                    subset.push_back(arr[j]);
                }
                j++;
            }
            subsets.push_back(subset);
        }
        int ans = 0;
        for (auto it : subsets)
        {
            int sum = 0;
            for (auto i : it)
            {
                sum += i;
            }
            if (!(sum & 1))
                ans++;
        }
        cout << "lajdflk" << endl;
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code to test columnWithMaxZeros function
int main()
{

    // int testcase;

    // cin >> testcase;

    // while (testcase--)
    // {
    int N;
    cin >> N;

    int arr[N];

    // Taking elements input into the matrix
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    Solution obj;
    cout << obj.countSumSubsets(arr, N) << " asdfsdf" << endl;
    // }

    return 0;
}
// } Driver Code Ends