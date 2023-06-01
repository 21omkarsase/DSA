// The time complexity of union-find operations depends on the specific implementation of the data structure. The two primary operations in the union-find data structure are find and union.

//     Find Operation:
//         The find operation is used to find the representative (or root) of the set that an element belongs to.
//         In most efficient implementations, such as using path compression and rank heuristics, the find operation has an amortized time complexity of nearly O(1).
//         Amortized analysis considers the overall cost of a sequence of operations and averages it out, resulting in an average cost of nearly constant time per find operation.

//     Union Operation:
//         The union operation is used to merge two sets by making one representative the parent of the other.
//         In most efficient implementations, such as using union by rank or union by size heuristics, the union operation also has an amortized time complexity of nearly O(1).
//         The heuristics help optimize the union operation by keeping the height or size of the resulting set small.

// Therefore, in a well-implemented union-find data structure that employs path compression and either union by rank or union by size heuristics, both the find and union operations have an amortized time complexity of nearly O(1).

// It's important to note that the time complexity analysis assumes that the data structure is balanced and the operations are performed on a reasonably balanced tree. However, in the worst-case scenario, where the tree becomes degenerate (e.g., a long chain), the time complexity can become linear.

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

	void unionMerge(int u,int v){
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