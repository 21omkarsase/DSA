// 721. Accounts Merge
// Medium
// 5.6K
// 955
// Companies

// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

// Example 1:

// Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Explanation:
// The first and second John's are the same person as they have the common email "johnsmith@mail.com".
// The third John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

// Example 2:

// Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
// Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]

 

// Constraints:

//     1 <= accounts.length <= 1000
//     2 <= accounts[i].length <= 10
//     1 <= accounts[i][j].length <= 30
//     accounts[i][0] consists of English letters.
//     accounts[i][j] (for j > 0) is a valid email.

// Accepted
// 311.1K
// Submissions
// 552.3K
// Acceptance Rate
// 56.3%

// Time Complexity : O(N^2*M)
// Space Complexity : O(N)

class DSU{
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int node = 0; node < n; node++) {
            parent[node] = node;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        parent[node] = findParent(parent[node]);

        return parent[node];
    }

    void unionMerge(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v) {
            return;
        }

        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void getMergedAccounts(vector<vector<string>> &accounts, vector<vector<string>> &mergedAccounts) {
        int n = accounts.size();
        vector<bool> visited(n, 0);

        for (int idx1 = 0; idx1 < n; idx1++) {
            int parent1 = findParent(idx1);

            if (!visited[idx1]) {
                set<string> mails;

                for (int idx2 = idx1; idx2 < n; idx2++) {
                    int parent2 = findParent(idx2);
                    
                    if (parent1 == parent2) {
                        for (int mail = 1; mail < accounts[idx2].size(); mail++) {
                            mails.insert(accounts[idx2][mail]);
                        }
                        
                        visited[idx2] = 1;
                    }
                }

                vector<string> mergedAccount = {accounts[idx1][0]};

                for (auto mail : mails) {
                    mergedAccount.push_back(mail);
                }

                mergedAccounts.push_back(mergedAccount);
            }
        }
    }


};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int>mail;

        DSU ds(n);

        for(int idx1 = 0; idx1 < n; idx1++){
            for(int idx2 = 1; idx2 < accounts[idx1].size(); idx2++){
                if(mail.find(accounts[idx1][idx2]) == mail.end()){
                    mail[accounts[idx1][idx2]] = idx1; 
                }
                else{
                    ds.unionMerge(mail[accounts[idx1][idx2]], idx1);
                }
            }
        }
        
        vector<vector<string>> mergedAccounts;
        ds.getMergedAccounts(accounts, mergedAccounts);

        return mergedAccounts;
    }
};










