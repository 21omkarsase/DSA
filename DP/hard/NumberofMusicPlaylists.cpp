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