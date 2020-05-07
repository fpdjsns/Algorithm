/**
 * problem : https://leetcode.com/problems/cousins-in-binary-tree/
 * data structure : tree
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
    // parent.val, depth
    pair<int,int> a;
    pair<int,int> b;
    void isCousins(TreeNode* node, TreeNode* parent, int x, int y, int depth) {
        if(node == NULL) return;
        if(parent == NULL) parent = node;
        if(node->val == x) a = {parent->val, depth};
        if(node->val == y) b = {parent->val, depth};
        isCousins(node->left, node, x, y, depth+1);
        isCousins(node->right, node, x, y, depth+1);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        isCousins(root, NULL, x, y, 0);
        return a.second == b.second && a.first != b.first;
    }
};
