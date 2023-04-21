#include<bits/stdc++.h>
using namespace std;

class Node{
private :
    Node* links[2];
    
public :
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
private : Node * root;
public : 
    Trie(){
        root = new Node();
    }
public :
    void insert(int n){
        Node* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (n >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int n){
        Node* node = root;
        int mx = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (n >> i) & 1;
            if(node->containsKey(!bit)){
                mx = mx + (1 << i);
                node = node->get(!bit);
            }else
                node = node->get(bit);
        } 
        return mx;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* t = new Trie();

        for(auto ele : nums){
            t->insert(ele);
        }

        int mx = 0;

        for(auto ele : nums){
            mx = max(mx, t->getMax(ele));
        }

        return mx;
    }
};

int main(){
    int n;cin>>n;
    vector<int> nums(n, 0);

    Solution *s = new Solution();

    for(auto &e : nums){
        cin >> e;
    }

    cout<<s->findMaximumXOR(nums)<<"\n";
    return 0;
}
