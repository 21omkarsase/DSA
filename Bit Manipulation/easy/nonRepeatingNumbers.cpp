

// Non Repeating Numbers
// EasyAccuracy: 49.85%Submissions: 41067Points: 2
// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers.

// Example 1:

// Input:
// N = 2
// arr[] = {1, 2, 3, 2, 1, 4}
// Output:
// 3 4
// Explanation:
// 3 and 4 occur exactly once.
// Example 2:

// Input:
// N = 1
// arr[] = {2, 1, 3, 2}
// Output:
// 1 3
// Explanation:
// 1 3 occur exactly once.

// Your Task:
// You do not need to read or print anything. Your task is to complete the function singleNumber() which takes the array as input parameter and returns a list of two numbers which occur exactly once in the array. The list must be in ascending order.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= length of array <= 106
// 1 <= Elements in array <= 5 * 106

// View Bookmarked Problems
// Company Tags
// AccoliteAmazonFactSetGoogleMakeMyTripMicrosoftQualcommSamsung

// ********************without using xor****************
//{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// } Driver Code Ends
// class Solution
// {
// public:
//     vector<int> singleNumber(vector<int> nums)
//     {
//         // Code here.
//         sort(nums.begin(), nums.end());
//         vector<int> ans;
//         int i = 0;
//         while (i < nums.size() - 1)
//         {
//             if (nums[i] == nums[i + 1])
//                 i += 2;
//             else
//             {
//                 ans.push_back(nums[i]);
//                 i++;
//             }
//         }
//         if (nums[nums.size() - 1] != nums[nums.size() - 2])
//             ans.push_back(nums[nums.size() - 1]);
//         return ans;
//     }
// };

// //{ Driver Code Starts.
// int main()
// {
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         int n;
//         cin >> n;
//         vector<int> v(2 * n + 2);
//         for (int i = 0; i < 2 * n + 2; i++)
//             cin >> v[i];
//         Solution ob;
//         vector<int> ans = ob.singleNumber(v);
//         for (auto i : ans)
//             cout << i << " ";
//         cout << "\n";
//     }
//     return 0;
// }
// } Driver Code Ends

// ******************using xor******************
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        vector<int> ans;
        int xr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xr = xr ^ nums[i];
        }
        int n = xr, i = 0, idx = 1;
        while (n)
        {
            if (n & 1)
            {
                idx = i;
                break;
            }
            i++;
            n = n >> 1;
        }
        int n1 = 0, n2 = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] & (1 << idx))
                n1 = n1 ^ nums[j];
            else
                n2 = n2 ^ nums[j];
        }

        ans.push_back(min(n1, n2));
        ans.push_back(max(n1, n2));
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n + 2);
        for (int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.singleNumber(v);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends