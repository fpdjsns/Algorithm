/**
 * problem : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 * time complexity : O(N). N = number of nodes
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
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int answer = 0;
        queue<pair<TreeNode*, int>> q; // {node, max val}
        q.push({root, -1e9});
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int maxVal = q.front().second;
            q.pop();
            
            if(node->val >= maxVal) {
                answer++;
                maxVal = node->val;
            }
            
            if(node->left) q.push({node->left, maxVal});
            if(node->right) q.push({node->right, maxVal});
        }
        return answer;
    }
};
