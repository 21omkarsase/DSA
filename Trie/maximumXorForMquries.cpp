#include<bits/stdc++.h>
using namespace std;

class Node{
private : 
    Node* links[2];
public : 
    Node(){
        this->links[0] = NULL;
        this->links[1] = NULL;
    }

    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
private : 
    Node* root;
public : 
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
        int mx = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit)){
                mx = mx + (1 << i);
                node = node->get(!bit);
            }else{
                node = node->get(bit);
            }
        }
        return mx;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();

        vector<int> ans(m, -1);
        
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> offQueries;
        for(int i = 0; i < m; i++){
            offQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(offQueries.begin(), offQueries.end());
        
        int j = 0;

        Trie* t = new Trie();

        for(int i = 0; i < m; i++){
            int limit = offQueries[i].first;
            int num = offQueries[i].second.first;
            int idx = offQueries[i].second.second;
            
            if(nums[0] > limit){
                ans[idx] = -1;
                continue;
            }

            while(j < n && nums[j] <= limit){
                t->insert(nums[j]);
                j++;
            }
            
            if(j == 0) ans[idx] = -1;
            else ans[idx] = t->getMax(num);
        }

        return ans;
    }
};


int main(){
    int n, m;
    cin >> n >> m;

    vector<int> nums(n, 0);
    vector<vector<int>> queries(m, vector<int>(2, 0));

    for(auto &e : nums)
        cin >> e;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < 2; j++){
            cin >> queries[i][j];
        }
    }

    Solution* s = new Solution();


    vector<int> ans =  s->maximizeXor(nums, queries);

    for(auto e : ans)
        cout<<e<<" --> ";
    cout<<"\n";

    return 0;
}