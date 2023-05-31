// 399. Evaluate Division
// Medium
// 8.1K
// 719
// Companies

// You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

// You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

// Return the answers to all queries. If a single answer cannot be determined, return -1.0.

// Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

// Example 1:

// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation: 
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

// Example 2:

// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output: [3.75000,0.40000,5.00000,0.20000]

// Example 3:

// Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output: [0.50000,2.00000,-1.00000,-1.00000]

 

// Constraints:

//     1 <= equations.length <= 20
//     equations[i].length == 2
//     1 <= Ai.length, Bi.length <= 5
//     values.length == equations.length
//     0.0 < values[i] <= 20.0
//     1 <= queries.length <= 20
//     queries[i].length == 2
//     1 <= Cj.length, Dj.length <= 5
//     Ai, Bi, Cj, Dj consist of lower case English letters and digits.

// Accepted
// 374K
// Submissions
// 610K
// Acceptance Rate
// 61.3%


class Solution {
    void dfs(string curr, string &dest, unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &vis, double &ans, double temp){
        if(vis.find(curr) != vis.end()) 
            return;
        vis.insert(curr);

        if(curr == dest){
            ans = temp;
            return;
        }

        for(auto node : graph[curr]){
            dfs(node.first, dest, graph, vis, ans, temp * node.second);
        }
    }


    unordered_map<string, unordered_map<string, double>> buildGraph(const vector<vector<string>>& equations, const vector<double>& values){
        unordered_map<string, unordered_map<string, double>> graph;

        int n = equations.size();
        for(int i = 0; i < n; i++){
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];
            double reciprocal = 1.0 / val;

            graph[a][b] = val;
            graph[b][a] = reciprocal;
        }

        return graph;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph = buildGraph(equations, values);
        
        vector<double> queryValues;
        for(auto query : queries){
            string a = query[0], b = query[1];
            if(graph.find(a) == graph.end() || graph.find(b) == graph.end()){
            queryValues.push_back(-1.0);
            }else{
                unordered_set<string> vis;
                double ans = -1.0;
                double temp = 1.0 ;

                dfs(a, b, graph, vis, ans, temp);
                queryValues.push_back(ans);
            }
        }
        return queryValues;
    }
};