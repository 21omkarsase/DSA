// 1203. Sort Items by Groups Respecting Dependencies
// Hard
// 1K
// 166
// Companies

// There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.

// Return a sorted list of the items such that:

//     The items that belong to the same group are next to each other in the sorted list.
//     There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).

// Return any solution if there is more than one solution and return an empty list if there is no solution.

 

// Example 1:

// Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
// Output: [6,3,4,1,5,2,0,7]

// Example 2:

// Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
// Output: []
// Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.

 

// Constraints:

//     1 <= m <= n <= 3 * 104
//     group.length == beforeItems.length == n
//     -1 <= group[i] <= m - 1
//     0 <= beforeItems[i].length <= n - 1
//     0 <= beforeItems[i][j] <= n - 1
//     i != beforeItems[i][j]
//     beforeItems[i] does not contain duplicates elements.

// Accepted
// 23.9K
// Submissions
// 41K
// Acceptance Rate
// 58.3%

// Time Complexity : O(N^2)
// Space Complexity : O(N + M)

class Solution {
    vector<int> getTopoOrder(int n, vector<int> &indegree, vector<int> graph[]) {
        stack<int> st;
        vector<int> visited;

        for (int node = 0; node < indegree.size(); node++) {
            if (indegree[node] == 0) {
                st.push(node);
            }
        }

        while (!st.empty()) {
            int currNode = st.top();
            st.pop();

            visited.push_back(currNode);

            for (auto adjNode : graph[currNode]) {
                indegree[adjNode]--;

                if (indegree[adjNode] == 0) {
                    st.push(adjNode);
                }
            }
        }

        if (visited.size() != n) {
            return vector<int>();
        }

        return visited;
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupId = m;

        for (int item = 0; item < n; item++) {
            if (group[item] == -1) {
                group[item] = groupId++;
            }
        }

        vector<int> itemGraph[n], groupGraph[groupId];   
        vector<int> groupIndegree(groupId, 0), itemIndegree(n, 0);

        for (int item = 0; item < n; item++) {
            for (auto prevItem : beforeItems[item]) {
                itemGraph[prevItem].push_back(item);
                itemIndegree[item]++;

                if (group[item] != group[prevItem]) {
                    groupGraph[group[prevItem]].push_back(group[item]); 
                    // prevItem groupItem should be iterated before iterating current group items
                    groupIndegree[group[item]]++;
                }
            }
        }

        vector<int> itemOrder = getTopoOrder(n, itemIndegree, itemGraph);
        vector<int> groupOrder = getTopoOrder(groupId, groupIndegree, groupGraph);

        if (itemOrder.size() == 0 || groupOrder.size() == 0) {
            return vector<int>();
        }

        vector<int> orderedGroups[groupId];

        for (int item : itemOrder) {
            orderedGroups[group[item]].push_back(item);
        }

        vector<int> finalOrder;

        for (int currGroup : groupOrder) {
            for (int item : orderedGroups[currGroup]) {
                finalOrder.push_back(item);
            }
        }

        return finalOrder;
    }
};