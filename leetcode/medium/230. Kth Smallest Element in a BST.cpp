/**
 * problem : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * data structure : Tree
 * time complexity : O(k)
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
    int ans = 0;
    int cnt;
    void solve(TreeNode* node){
        if(node == NULL) return;
        if(cnt < 0) return;
        
        solve(node->left);
        cnt--;
        if(cnt == 0) {
            ans = node->val;
        }
        solve(node->right);
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        solve(root);
        return ans;
    }
};
