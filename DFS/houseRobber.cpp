// 337. House Robber III
// Medium
// 7.7K
// 116
// Companies

// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 

// Example 1:

// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

// Example 2:

// Input: root = [3,4,5,1,3,null,1]
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 104].
//     0 <= Node.val <= 104

// Accepted
// 337K
// Submissions
// 624.7K
// Acceptance Rate
// 54.0%

class Solution {
    pair<int, int> getRobbedMoney(TreeNode* root){
        if(!root) return {0, 0};

        pair<int, int> leftMoney = getRobbedMoney(root->left);
        pair<int, int> rightMoney = getRobbedMoney(root->right);

        int take = root->val + leftMoney.second + rightMoney.second;
        int notTake = max(rightMoney.first, rightMoney.second) + max(leftMoney.first, leftMoney.second);

        return {take, notTake};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> robbedMoney = getRobbedMoney(root);

        return max(robbedMoney.first, robbedMoney.second);
    }
};
 

class Solution {
    int getRobbedMoney(TreeNode* root, bool flag, unordered_map<string, int>& dp) {
        if (!root) return 0;

        string key = to_string((intptr_t)root) + "_" + to_string(flag);
        
        if (dp.count(key))
            return dp[key];
        
        int pick = 0, notPick = 0;
        if (flag) {
            pick = getRobbedMoney(root->left, false, dp) + root->val;
            pick += getRobbedMoney(root->right, false, dp);
        }
        
        notPick = getRobbedMoney(root->left, true, dp);
        notPick += getRobbedMoney(root->right, true, dp);
        
        dp[key] = max(pick, notPick);
        
        return dp[key];
    }
public:
    int rob(TreeNode* root) {
        unordered_map<string, int> dp;
        return getRobbedMoney(root, true, dp);
    }
};




struct DPKey {
    TreeNode* node;
    bool flag;

    bool operator==(const DPKey& other) const {
        return node == other.node && flag == other.flag;
    }
};

struct DPKeyHash {
    std::size_t operator()(const DPKey& key) const {
        auto hash1 = std::hash<TreeNode*>{}(key.node);
        auto hash2 = std::hash<bool>{}(key.flag);
        return hash1 ^ hash2;
    }
};

class Solution {
    int getRobbedMoney(TreeNode* root, bool flag, unordered_map<DPKey, int, DPKeyHash>& dp) {
        if (!root) return 0;

        DPKey key = {root, flag};
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int pick = 0, notPick = 0;
        if (flag) {
            cout << root->val << " --> ";
            pick = getRobbedMoney(root->left, false, dp) + root->val;
            pick += getRobbedMoney(root->right, false, dp);
        }

        notPick = getRobbedMoney(root->left, true, dp);
        notPick += getRobbedMoney(root->right, true, dp);

        return dp[key] = max(pick, notPick);
    }

public:
    int rob(TreeNode* root) {
        unordered_map<DPKey, int, DPKeyHash> dp;
        return getRobbedMoney(root, true, dp);
    }
};
