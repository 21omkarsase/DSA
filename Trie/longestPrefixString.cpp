#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return (this -> links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        this -> links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return this -> links[ch - 'a'];
    }

    void setEnd(){
        this-> flag = true;
    }

    bool getEnd(){
        return this -> flag;
    }
};

class Trie{
private : Node* root;
public :
    Trie(){
        root = new Node();
    }

    void insert(string s){
        Node* node = root;
        for(int i = 0; i < s.size(); i++){
            if(!node->containsKey(s[i])){
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->setEnd();
    }


    bool checkIfPrefixExists(string s){
        Node* node = root;
        for(int i = 0; i < s.size(); i++){
            if(node->containsKey(s[i])){
                node = node->get(s[i]);
                if(node->getEnd() == false){
                    return false;
                }
            }else return false;
        }
        return true;
    }


};

string completeString(int n, vector<string> &s){
    Trie* t = new Trie();

    for(int i = 0; i < n; i++){
        t->insert(s[i]);
    }

    string longest = "";
    for(auto &it : s){
        if(t->checkIfPrefixExists(it)){
            if(it.size() > longest.size()){
                longest = it;
            }else if(it.size() == longest.size() && it < longest){
                longest = it;
            }
        }
    }



    if(longest.size() == 0) return "None";
    return longest;
}

int main(){
    int n;
    cin >> n;

    vector<string> s(n, "");
    for(auto &e : s) 
        cin >> e;

    cout<<completeString(n, s)<<"\n";
    return 0;
}









