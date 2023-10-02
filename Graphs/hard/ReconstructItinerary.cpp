// 332. Reconstruct Itinerary
// Hard
// Topics
// Companies

// You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

// All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

//     For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

// You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

 

// Example 1:

// Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
// Output: ["JFK","MUC","LHR","SFO","SJC"]

// Example 2:

// Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

 

// Constraints:

//     1 <= tickets.length <= 300
//     tickets[i].length == 2
//     fromi.length == 3
//     toi.length == 3
//     fromi and toi consist of uppercase English letters.
//     fromi != toi

// Accepted
// 393K
// Submissions
// 901.7K
// Acceptance Rate
// 43.6%

class Solution {
   void dfs(int node, map<string, int> &nodeTracker, map<int, string> &locationTracker, vector<string> &ans, map<int, vector<string>> &adj) {      
        for (int idx = 0; idx < adj[node].size(); idx++) {
            if (adj[node][idx] != "") {
                string temp = adj[node][idx];

                adj[node][idx] = "";

                dfs(nodeTracker[temp], nodeTracker, locationTracker, ans, adj);
            }
        }

        ans.push_back(locationTracker[node]);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();

        map<string, int> nodeTracker;
        map<int, string> locationTracker;
        
        int idx = 0;

        nodeTracker["JFK"] = idx;
        locationTracker[idx++] = "JFK";

        for (auto ticket : tickets) {
            if (nodeTracker.find(ticket[0]) == nodeTracker.end()) {
                nodeTracker[ticket[0]] = idx;
                locationTracker[idx] = ticket[0];

                idx++;
            }
           
            if (nodeTracker.find(ticket[1]) == nodeTracker.end()) {
                nodeTracker[ticket[1]] = idx;
                locationTracker[idx] = ticket[1];

                idx++;
            }
        }

        vector<string> ans;
        map<int, vector<string>> adj;

        for (auto ticket : tickets) {
            int u = nodeTracker[ticket[0]];

            adj[u].push_back(ticket[1]);
        }

        for (auto &vec : adj) {
            sort(vec.second.begin(), vec.second.end());
        }

        for (auto p : adj) {
            cout<<p.first<<" --> ";
            for (auto e : p.second) {
                cout<<e<<" : ";
            }
            cout<<"\n";
        }
        
        dfs(0, nodeTracker, locationTracker, ans, adj);
      
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// Time Complexity : O(V + E)
// Space Complexity : O(V + E)


class Solution {
  void dfs(string node, vector<string> &ans, unordered_map<string, vector<string>> &graph) {
    while (graph[node].size() > 0) {
      string adjNode = graph[node].back();

      graph[node].pop_back();

      dfs(adjNode, ans, graph);
    }

    ans.push_back(node);
  }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();

        unordered_map<string, vector<string>> graph;

        for (auto ticket : tickets) {
          auto u = ticket[0], v = ticket[1];

          graph[u].push_back(v);
        }

        for (auto &p : graph) {
          sort(p.second.rbegin(), p.second.rend());
        }

        vector<string> ans;

        dfs("JFK", ans, graph);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Iterative
// Time Complexity : O((V + E) * log(E)) + O(E)
// Space Complexity : O(V + E)

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();

        unordered_map<string, vector<string>> graph;

        for (auto ticket : tickets) {
          auto u = ticket[0], v = ticket[1];

          graph[u].push_back(v);
        }

        for (auto &p : graph) {
          sort(p.second.begin(), p.second.end(), greater<string>());
        }

        vector<string> ans;

        stack<string> st;
        st.push("JFK");

        while (!st.empty()) {
            string curr = st.top();

            if (graph.find(curr) != graph.end() && graph[curr].size() > 0) {
                string temp = graph[curr].back();
                graph[curr].pop_back();

                st.push(temp);
            }
            else {
                ans.push_back(curr);
                st.pop();
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};