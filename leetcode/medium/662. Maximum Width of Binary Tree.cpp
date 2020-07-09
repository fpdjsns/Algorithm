/**
 * problem : https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1}); // {node, ind}
        int ans = 0;
        
        while(!q.empty()){
            int cnt = q.size();
            ans = max(ans, (q.back().second - q.front().second) + 1);
            while(cnt--){
                TreeNode* now = q.front().first;
                long ind = q.front().second;
                q.pop();

                if(now->left != nullptr) q.push({now->left, 2*ind - 1});
                if(now->right != nullptr) q.push({now->right, 2*ind});
            }
        }
        return ans;
    }
};
