// Find the closest pair from two arrays
// EasyAccuracy: 18.01%Submissions: 32K+Points: 2
// Learn Google Cloud with Curated Lab Assignments. Register, Earn Rewards, Get noticed by experts at Google & Land your Dream Job! 
// 
// Given two sorted arrays arr and brr and a number x, find the pair whose sum is closest to x and the pair has an element from each array. In the case of multiple closest pairs return any one of them.
// Note: Can return the two numbers in any manner.
// 
// Example 1:
// 
// Input : N = 4, M = 4
// arr[ ] = {1, 4, 5, 7}
// brr[ ] = {10, 20, 30, 40} 
// X = 32
// Output : 1
// Explanation:
// The closest pair whose sum is closest
// to 32 is {1, 30} = 31.
// 
// Example 2:
// 
// Input : N = 4, M = 4
// arr[ ] = {1, 4, 5, 7}
// brr[ ] = {10, 20, 30, 40}
// X = 50 
// Output :  3 
// Explanation: 
// The closest pair whose sum is closest
// to 50 is {7, 40} = 47.
// 
// Your Task:
// You only need to complete the function printClosest() that takes an array (arr), another array (brr), size of array arr (N), size of array brr (M), and return the array of two integers whose sum is closest to X. The driver code takes care of the printing of the closest difference.
// 
// Expected Time Complexity: O(N+M).
// Expected Auxiliary Space: O(1).
// 
// Constraints:
// 1 ≤ N, M ≤ 105
// 1 ≤ A[i], B[i] ≤ 109

// Time Complexity : O((N * M) * log(N + M))
// Space Complexity : O(N * M)

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> seen;
        
        pair<int, pair<int, int>> diff = {1e9, {-1, -1}};
        
        pq.push({arr[0] + brr[0], {0, 0}});
        seen.insert({0, 0});
        
        while (!pq.empty()) {
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            
            pq.pop();
            
            int currDiff = abs(x - sum);
            
            if (currDiff < diff.first) {
                diff = {currDiff, {i, j}};
            }
            
            if (i + 1 < n && seen.find({i + 1, j}) == seen.end() && (abs(arr[i + 1] + brr[j] - x) < diff.first)) {
                pq.push({arr[i + 1] + brr[j], {i + 1, j}});
                seen.insert({i + 1, j});
            }
            
            if (j + 1 < m && seen.find({i, j + 1}) == seen.end() && (abs(arr[i] + brr[j + 1] - x) < diff.first)) {
                pq.push({arr[i] + brr[j + 1], {i, j + 1}});
                seen.insert({i, j + 1});
            }
        }
        
        return {arr[diff.second.first], brr[diff.second.second]};
    }
};

// Time Complexity : O(max(N, M))
// Space Complexity : O(1)

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int idx1 = 0, idx2 = m - 1;
        
        int diff = 1e9;
        int i = -1, j = -1;
        
        while (idx1 < n && idx2 >= 0) {
            int currDiff = abs((arr[idx1] + brr[idx2]) - x);
            
            if (currDiff < diff) {
                diff = currDiff;
                i = idx1, j = idx2;
            }
            
            if (arr[idx1] + brr[idx2] > x) {
                idx2--;
            }
            else {
                idx1++;
            }
        }

        return {arr[i], brr[j]};
    }
};