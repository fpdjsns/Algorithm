/**
 * problem : https://leetcode.com/problems/binary-tree-pruning/
 * time complexity : O(N)
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
    bool hasOneNode(TreeNode* node) {
        if(node == NULL) return false;
        bool left = hasOneNode(node->left);
        if(!left) node->left = nullptr;
        bool right = hasOneNode(node->right);
        if(!right) node->right = nullptr;
        return node->val == 1 || left || right;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return hasOneNode(root) ? root : NULL;
    }
};
