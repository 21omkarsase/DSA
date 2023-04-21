#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node* arr[26];

	bool containsKey(char ch){
		return (arr[ch - 'a'] != NULL);
	}

	void put(char ch, Node* node){
		arr[ch - 'a'] = node;
	}

	Node* get(char ch){
		return arr[ch - 'a']; 
	}
};

class Trie{
	private : Node* root;
	public : 
	Trie(){
		root = new Node();
	}

	void insert(string s, int &cnt){
		Node * node = root;
		for(int i = 0; i < s.length(); i++){
			if(node->containsKey(s[i])){
				cnt = cnt + 1;
			}else{
				node->put(s[i], new Node());
			}
			node = node->get(s[i]);
		}
	}

};

int countDistinctSubstrings(string &s)
{
   Trie *t = new Trie();
   int cnt = 0;
   t->insert(s, cnt);
   return cnt;
}

int main(){

	return 0;
}