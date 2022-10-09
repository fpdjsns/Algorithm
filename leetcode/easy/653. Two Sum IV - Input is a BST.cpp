/**
 * problem : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 * time complexity : O(N)
 * data structure : BST
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
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> dict;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* now = q.front();
            q.pop();
            if(!now) continue;
            if(dict.find(k - now->val) != dict.end()) return true;
            dict.insert(now->val);
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);
        }
        return false;
    }
};
