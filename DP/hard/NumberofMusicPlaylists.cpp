// 920. Number of Music Playlists
// Hard
// 1.3K
// 125
// Companies

// Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:

//     Every song is played at least once.
//     A song can only be played again only if k other songs have been played.

// Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: n = 3, goal = 3, k = 1
// Output: 6
// Explanation: There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].

// Example 2:

// Input: n = 2, goal = 3, k = 0
// Output: 6
// Explanation: There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], and [1, 2, 2].

// Example 3:

// Input: n = 2, goal = 3, k = 1
// Output: 2
// Explanation: There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].

 

// Constraints:

//     0 <= k < n <= goal <= 100

// Accepted
// 33K
// Submissions
// 58.9K
// Acceptance Rate
// 56.0%

// Time Complexity : O(goal * n^2)
// space complexity : O(goal * n) + O(n)

class Solution {
    int MOD = 1e9 + 7;

    int calculateTotalNumberOfPlaylists(int nums, const int &n, const int &goal, const int &k, unordered_map<int, set<int, greater<int>>> &tracker, vector<vector<int>>& dp) {
        if (nums == goal) {
            return tracker.size() >= n;
        }

        if (dp[nums][tracker.size()] != -1) {
            return dp[nums][tracker.size()];
        }

        int playlists = 0;

        for (int idx = 1; idx <= n; idx++) {
            if ((nums < goal && tracker.find(idx) == tracker.end()) || (nums - *(tracker[idx].begin()) > k)) {
                tracker[idx].insert(nums);

                playlists = (playlists % MOD + calculateTotalNumberOfPlaylists(nums + 1, n, goal, k, tracker, dp) % MOD) % MOD;

                tracker[idx].erase(nums);

                if (tracker[idx].size() == 0) {
                    tracker.erase(idx);
                }
            }
        }

        dp[nums][tracker.size()] = playlists;
        return playlists;
    }

public:
    int numMusicPlaylists(int n, int goal, int k) {
        unordered_map<int, set<int, greater<int>>> tracker;
        vector<vector<int>> dp(goal + 1, vector<int>(goal + 1, -1));

        return calculateTotalNumberOfPlaylists(0, n, goal, k, tracker, dp);
    }
};



// Time Complexity : O(N ^ Goal)
// Space Complexity : O(N * Goal) + O(N)
class Solution {
    int calculateTotalNumberOfPlaylists(int nums, int time, const int &n, const int &goal, const int &k, unordered_map<int, set<int, greater<int>>> &tracker) {
        if (nums == goal) {
            return tracker.size() >= n;
        }
        
        int playlists = 0;

        for (int idx = 1; idx <= n; idx++) {
            if ((nums < goal && tracker.find(idx) == tracker.end()) || (time - *(tracker[idx].begin()) > k)) {
                tracker[idx].insert(time);

                playlists += calculateTotalNumberOfPlaylists(nums + 1, time + 1, n, goal, k, tracker);
           
                tracker[idx].erase(time);

                if(tracker[idx].size() == 0) {
                    tracker.erase(idx);
                }
            }
        }

        return playlists;
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        unordered_map<int, set<int, greater<int>>> tracker;

        return calculateTotalNumberOfPlaylists(0, 1, n, goal, k, tracker);
    }
};

// Time Complexity : O
Space Complexity : O


class Solution {
    int MOD = 1e9 + 7;
    
    int calculateTotalPlaylists(int playlistLength, int songsCount, int k, vector<vector<int>> &dp) {
        if (playlistLength == 0 && songsCount == 0) {
            return 1;
        }

        if (playlistLength == 0 || songsCount == 0) {
            return 0;
        }

        if (dp[playlistLength][songsCount] != -1) {
            return dp[playlistLength][songsCount];
        }

        int takeNewSong = ((long long) calculateTotalPlaylists(playlistLength - 1, songsCount - 1, k, dp) * songsCount) % MOD;
        int previousSong = ((long long) calculateTotalPlaylists(playlistLength - 1, songsCount, k, dp) * max(0, songsCount - k)) % MOD;
        
        return dp[playlistLength][songsCount] = (takeNewSong + previousSong) % MOD;
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(goal + 1, vector<int>(n + 1, -1));
        return calculateTotalPlaylists(goal, n, k, dp);
    }
};