/**
 * problem : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        map<int, vector<int>> m; // level : nodes
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while(!q.empty()){
            int level = q.front().first;
            TreeNode* node = q.front().second;
            q.pop();
            if(node == NULL) continue;
            m[level].push_back(node->val);
            q.push({level + 1, node->left});
            q.push({level + 1, node->right});
        }
        vector<vector<int>> ans;
        for(map<int, vector<int>>::reverse_iterator it = m.rbegin(); it != m.rend(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
