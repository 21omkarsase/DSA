#include<bits/stdc++.h>
using namespace std;

class Disjoint{
	vector<int>size, parent;
public:
	Disjoint(int n){
		size.resize(n+1,1);
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

	void unionBySize(int u,int v){
		int ulp_u=findParent(u);
		int ulp_v=findParent(v);

		if(ulp_u == ulp_v)return ;
        
		if(size[ulp_u]>size[ulp_v]){
			parent[ulp_v]=ulp_u; 
			size[ulp_u]+=size[ulp_v];
		}else{
			parent[ulp_u]=ulp_v; 
			size[ulp_v]+=size[ulp_u];
		}
	}
};

int main(){
	Disjoint ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.findParent(3) == ds.findParent(7))
    	cout<<"1 : Same\n";
    else cout<<"1 : No\n";

    ds.unionBySize(3,7);

    if(ds.findParent(3) == ds.findParent(7))
    	cout<<"2 : Same\n";
    else cout<<"2 : No\n";

	return 0;
}