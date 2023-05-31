// 990. Satisfiability of Equality Equations
// Medium
// 3.4K
// 50
// Companies

// You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

// Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

 

// Example 1:

// Input: equations = ["a==b","b!=a"]
// Output: false
// Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
// There is no way to assign the variables to satisfy both equations.

// Example 2:

// Input: equations = ["b==a","a==b"]
// Output: true
// Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

 

// Constraints:

//     1 <= equations.length <= 500
//     equations[i].length == 4
//     equations[i][0] is a lowercase letter.
//     equations[i][1] is either '=' or '!'.
//     equations[i][2] is '='.
//     equations[i][3] is a lowercase letter.

// Accepted
// 111.7K
// Submissions
// 221.2K
// Acceptance Rate
// 50.5%

class Disjoint{
    vector<int>SIZE, parent;
public:
    Disjoint(int n){
        SIZE.resize(n+1,1);
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
        
        if(SIZE[ulp_u]>SIZE[ulp_v]){
            parent[ulp_v]=ulp_u; 
            SIZE[ulp_u]+=SIZE[ulp_v];
        }else{
            parent[ulp_u]=ulp_v; 
            SIZE[ulp_v]+=SIZE[ulp_u];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        Disjoint *ds = new Disjoint(26);

        vector<string> sortedEqns;
        for(auto eq : equations){
            if(eq[1] == '=')
                sortedEqns.push_back(eq);
        }
        for(auto eq : equations){
            if(eq[1] == '!')
                sortedEqns.push_back(eq);
        }


        int n = sortedEqns.size();
        for(auto eq : sortedEqns){
            int a = eq[0] - 'a';
            int b = eq[3] - 'a';

            if(eq[1] == '='){
                if(ds->findParent(a) == a && ds->findParent(b) == b){
                    ds->unionMerge(a, b);
                    continue;
                }
                
                ds->unionMerge(a, b);
            }else{
                if(ds->findParent(a) == ds->findParent(b)){
                    return false;
                }
            }
        }

        return true;
    }
};
















