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


// Time Complexity : O(N * alpha(n))
// Space Complexity : O(N)

 // α(n), also known as the inverse Ackermann function, is an extremely slowly-growing function. 
// for any reasonable value of n (even for astronomical values of n), α(n) is at most 4


#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> size;
    vector<int> parent;

public:
    DSU (int n) {
        size.resize(n, 1);
        parent.resize(n);

        for (int idx = 0; idx < n; idx++) {
            parent[idx] = idx;
        }
    };

    int findParent (int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    bool unionMerge (int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v) {
            return false;
        }

        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        return true;
    }
};

int main(){
	DSU ds(7);
    ds.unionMerge(1,2);
    ds.unionMerge(2,3);
    ds.unionMerge(4,5);
    ds.unionMerge(6,7);
    ds.unionMerge(5,6);

    if(ds.findParent(3) == ds.findParent(7))
    	cout<<"1 : Same\n";
    else cout<<"1 : No\n";

    ds.unionMerge(3,7);

    if(ds.findParent(3) == ds.findParent(7))
    	cout<<"2 : Same\n";
    else cout<<"2 : No\n";

	return 0;
}