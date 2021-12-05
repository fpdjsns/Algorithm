/**
 * problem : https://leetcode.com/problems/house-robber-iii/
 * time complexity : O(N)
 * algorithm : DP
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, int> dp;
        
public:
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        
        if(dp.find(root) != dp.end()) 
            return dp[root];
        
        int& ret = dp[root];
        ret = root->val;
        
        int sum = 0;
        if(root->left) sum += rob(root->left);
        if(root->right) sum += rob(root->right);
        ret = max(ret, sum);
        
        sum = root->val;
        if(root->left) sum += rob(root->left->left) + rob(root->left->right);
        if(root->right) sum += rob(root->right->left) + rob(root->right->right);
        ret = max(ret, sum);
        
        return ret;
    }
};
