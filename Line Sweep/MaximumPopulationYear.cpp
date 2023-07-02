
// 1854. Maximum Population Year
// Easy
// 1K
// 171
// Companies

// You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

// The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

// Return the earliest year with the maximum population.

 

// Example 1:

// Input: logs = [[1993,1999],[2000,2010]]
// Output: 1993
// Explanation: The maximum population is 1, and 1993 is the earliest year with this population.

// Example 2:

// Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
// Output: 1960
// Explanation: 
// The maximum population is 2, and it had happened in years 1960 and 1970.
// The earlier year between them is 1960.

 

// Constraints:

//     1 <= logs.length <= 100
//     1950 <= birthi < deathi <= 2050

// Accepted
// 50.5K
// Submissions
// 84.1K
// Acceptance Rate
// 60.1%


// Time Complexity : O(max year - min year)
// Space Complexity : O(N)

//using brute force

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();

        int maxPopulation = INT_MIN, maxPopulationYear = 0;

        map<int, int> tracker;

        for (int idx = 0; idx < n; idx++) {
            for (int year = logs[idx][0]; year < logs[idx][1]; year++) {
                tracker[year]++;
            }
        }

        for (auto it : tracker) {
            if (it.second > maxPopulation) {
                maxPopulation = it.second;
                maxPopulationYear = it.first; 
            }    
        }

        return maxPopulationYear;
    }
};

// Time Complexity : O(N * LogN)  Log(N) for seraching key postion
// Space Complexity : O(N)

//using line sweep algo


class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();

        int maxPopulation = INT_MIN, maxPopulationYear = 0;

        map<int, int> tracker;

        for (int idx = 0; idx < n; idx++) {
            tracker[logs[idx][0]]++;
            tracker[logs[idx][1]]--;
        }
        
        int sum = 0;

        for (auto it : tracker) {
            sum += it.second;

            if (sum > maxPopulation) {
                maxPopulation = sum;
                maxPopulationYear = it.first; 
            }    
        }

        return maxPopulationYear;
    }
};