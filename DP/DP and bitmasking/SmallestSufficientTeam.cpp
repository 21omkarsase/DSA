// 1125. Smallest Sufficient Team
// Hard
// 1.8K
// 47
// Companies

// In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.

// Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

//     For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].

// Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.

// It is guaranteed an answer exists.

 

// Example 1:

// Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
// Output: [0,2]

// Example 2:

// Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
// Output: [1,2]

 

// Constraints:

//     1 <= req_skills.length <= 16
//     1 <= req_skills[i].length <= 16
//     req_skills[i] consists of lowercase English letters.
//     All the strings of req_skills are unique.
//     1 <= people.length <= 60
//     0 <= people[i].length <= 16
//     1 <= people[i][j].length <= 16
//     people[i][j] consists of lowercase English letters.
//     All the strings of people[i] are unique.
//     Every skill in people[i] is a skill in req_skills.
//     It is guaranteed a sufficient team exists.

// Accepted
// 50K
// Submissions
// 87.9K
// Acceptance Rate
// 56.9%

// Time Complexity : O(2 ^ N * K)
// Space Complexity : O(N + M + K)

class Solution {e
    void getSmallestTeamCount(int idx, vctor<int> &currTeam, vector<int> &finalTeam, unordered_set<string> &seen, vector<vector<string>> &people) {
        if (seen.size() == 0) {
            if (finalTeam.size() == 0) {
                finalTeam = currTeam;
            } else if (currTeam.size() < finalTeam.size())
                finalTeam = currTeam;
            
            return;
        }

        if (idx < 0) {
            return;
        }

        unordered_set<string> skillsRemoved;
        for (auto skill : people[idx]) {
            if (seen.find(skill) != seen.end()) {
                seen.erase(skill);
                skillsRemoved.insert(skill);
            }
        }
        currTeam.push_back(idx);
        getSmallestTeamCount(idx - 1, currTeam, finalTeam, seen, people);
        
        currTeam.pop_back();
        for (auto skill : skillsRemoved) {
            seen.insert(skill);
        }

        getSmallestTeamCount(idx - 1, currTeam, finalTeam, seen, people);
    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size();  

        vector<int> currTeam, finalTeam;      
        unordered_set<string> seen(req_skills.begin(), req_skills.end());

        getSmallestTeamCount(n - 1, currTeam, finalTeam, seen, people);

        return finalTeam;
    }
};

// Time Complexity : O(M * 2^N), where m is the number of people and n is the number of required skills.

//top down

class Solution {
    int calculateSmallestTeamCount(int idx, int mask, int n, int m, vector<int> &maskedSkills,  vector<vector<int>> &skillsAdded,  vector<vector<int>> &dp) {
        if (mask == (1 << n) - 1)
            return 0;
        
        if (idx == m) {
            return 1e9;
        }
        
        int &ans = dp[idx][mask];
        if (ans != -1)
            return ans;

        int take = calculateSmallestTeamCount(idx + 1, mask | maskedSkills[idx], n, m, maskedSkills, skillsAdded, dp) + 1;
        
        int notTake = calculateSmallestTeamCount(idx + 1, mask, n, m, maskedSkills, skillsAdded, dp);

        if (take < notTake) {
            skillsAdded[mask][idx] = 1;
        }

        return ans = min(take, notTake);
    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size();

        unordered_map<string, int> skillNumbered;
        
        for (int idx = 0; idx < n; idx++) {
            skillNumbered[req_skills[idx]] = n - idx - 1;
        }

        vector<int> maskedSkills;

        for (int idx = 0; idx < m; idx++) {
            int mask = 0;

            for (auto skill : people[idx]) {
                mask = mask | (1 << skillNumbered[skill]);
            }

            maskedSkills.push_back(mask);
        }
        
        vector<vector<int>> dp(m, vector<int>(1 << n, - 1));
        vector<vector<int>> skillsAdded((1 << n), vector<int>(m, 0));
        
        calculateSmallestTeamCount(0, 0, n, m, maskedSkills, skillsAdded, dp);
        
        int mask = 0;
        vector<int>ans;

        for (int idx = 0; idx < m; idx++) {
            if (skillsAdded[mask][idx]) {
                mask |= maskedSkills[idx];
                ans.push_back(idx);
            }

            if (mask == (1 << n) - 1)
                break;
        }

        return ans;
    }
};


// bottom up


class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size();

        unordered_map<string, int> skillNumbered;
        
        for (int idx = 0; idx < n; idx++) {
            skillNumbered[req_skills[idx]] = n - idx - 1;
        }

        vector<int> maskedSkills;

        for (int idx = 0; idx < m; idx++) {
            int mask = 0;

            for (auto skill : people[idx]) {
                mask = mask | (1 << skillNumbered[skill]);
            }

            maskedSkills.push_back(mask);
        }
        
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, 1e9));
        vector<vector<int>> skillsAdded((1 << n), vector<int>(m, 0));
        

        for (int idx = 0; idx <= m; idx++) {
            dp[idx][(1 << n) - 1] = 0;
        }

        for (int idx = m - 1; idx >= 0; idx--) {
            for (int mask = (1 << n) - 2; mask >= 0; mask--) {
                int take = dp[idx + 1][mask | maskedSkills[idx]] + 1;
        
                int notTake = dp[idx + 1][mask];

                if (take < notTake) {
                    skillsAdded[mask][idx] = 1;
                }

                dp[idx][mask] = min(take, notTake);
            }
        }
        
        int mask = 0;
        vector<int>ans;

        for (int idx = 0; idx < m; idx++) {
            if (skillsAdded[mask][idx]) {
                mask |= maskedSkills[idx];
                ans.push_back(idx);
            }

            if (mask == (1 << n) - 1)
                break;
        }

        return ans;
    }
};


