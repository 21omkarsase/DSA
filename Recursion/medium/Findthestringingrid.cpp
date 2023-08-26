// Find the string in grid
// MediumAccuracy: 22.88%Submissions: 57K+Points: 4
// Win from a prize pool of INR 15K and get exciting merch! Register your team for Hack-A-Thon today!

// Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down, and 4 diagonal directions.

// Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions starting from the same coordinates, the list should contain the coordinates only once. 

// Example 1:

// Input: 
// grid = {{a,b,c},{d,r,f},{g,h,i}},
// word = "abc"
// Output: 
// {{0,0}}
// Explanation: 
// From (0,0) we can find "abc" in horizontally right direction.

// Example 2:

// Input: 
// grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
// word = "abe"
// Output: 
// {{0,0},{0,2},{1,0}}
// Explanation: 
// From (0,0) we can find "abe" in right-down diagonal. 
// From (0,2) we can find "abe" in left-down diagonal. 
// From (1,0) we can find "abe" in horizontally right direction.

// Your Task:
// You don't need to read or print anything, Your task is to complete the function searchWord() which takes grid and word as input parameters and returns a list containing the positions from where the word originates in any direction. If there is no such position then returns an empty list.

// Expected Time Complexity: O(n*m*k) where k is constant
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= n <= m <= 50
// 1 <= |word| <= 15

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    bool isPossibleToFormWord(int idx, string temp, int rdir, int cdir, int row, int col, const int &n, const int &m, const int &len, 
                              const string &word, const vector<vector<char>> &grid) {
        if (idx >= len) {
            return true;
        }

        if (idx == len - 1 && word[idx] == grid[row][col]) {
        	return true;
        }

        cout<<temp<<" --> ";
	    cout<<idx<<" -> "<<grid[row][col]<<" : "<<word[idx]<<" :: "<<rdir<<" :: "<<cdir<<"\n";
        
        if (word[idx] != grid[row][col]) {
            return false;
        }

         
        for (int idx1 = -1; idx1 <= 1; idx1++) {
            for (int idx2 = -1; idx2 <= 1; idx2++) {
            	if (idx1 == 0 && idx2 == 0) {
                	continue;
                }
                
                int nrow = row + idx1, ncol = col + idx2;
                
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && 
                	((rdir == 2 && cdir == 2) || (rdir == idx1 && cdir == idx2))) {
                    if(isPossibleToFormWord(idx + 1, temp + grid[row][col], idx1, idx2, nrow, ncol, n, m, len, word, grid)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int n = grid.size(), m = grid[0].size(), len = word.size();
	    
	    vector<vector<int>> ans;
	    
	    for (int row = 0; row < n; row++) {
	        for (int col = 0; col < m; col++) {
	            if (isPossibleToFormWord(0, "", 2, 2, row, col, n, m, len, word, grid)) {
	                ans.push_back({row, col});
	            }
	        }
	    }
	    
	    sort(ans.begin(), ans.end());
	    
	    return ans;
	}
};



//{ Driver Code Starts.
int main(){

	int n, m;
	cin >> n >> m;
	vector<vector<char>>grid(n, vector<char>(m,'x'));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> grid[i][j];
	}
	string word;
	cin >> word;
	Solution obj;
	vector<vector<int>>ans = obj.searchWord(grid, word);
	if(ans.size() == 0)
	{
	    cout<<"-1\n";
	}
	else
	{
	    for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	    }
	}
	
	
	return 0;
}
// } Driver Code Ends