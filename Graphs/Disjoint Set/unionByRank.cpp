#include<bits/stdc++.h>
using namespace std;

class Disjoint{
	vector<int>rank, parent;
public:
	Disjoint(int n){
		rank.resize(n+1,0);
		parent.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i]=i;
		}
	}

	int findParent(int node){
		if(parent[node]==node)return node;

		parent[node] = findParent(parent[node]);
		return parent[node];
	}

	void unionByRank(int u,int v){
		int ulp_u=findParent(u);
		int ulp_v=findParent(v);

		if(ulp_u == ulp_v)return ;
        
        //always connect component with smaller rank to larger
		if(rank[ulp_u]>rank[ulp_v]){
			parent[ulp_v]=ulp_u; //path compression
		}else if(rank[ulp_v]>rank[ulp_u]){
			parent[ulp_u]=ulp_v; //path compression
		}else{
			parent[ulp_u]=ulp_v; //path compression
			rank[ulp_v]++;
		}
	}
};

int main(){
	Disjoint ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.findParent(3) == ds.findParent(7))
    	cout<<"1 : Same\n";
    else cout<<"1 : No\n";

    ds.unionByRank(3,7);

    if(ds.findParent(3) == ds.findParent(7))
    	cout<<"2 : Same\n";
    else cout<<"2 : No\n";

	return 0;
}