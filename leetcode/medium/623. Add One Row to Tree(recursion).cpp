/**
 * problem : https://leetcode.com/problems/add-one-row-to-tree/
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
    void addOneRow(TreeNode* root, int val, int depth, int nowDepth) {
        if(!root) return;
        if(nowDepth == depth - 1) {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
        }
        addOneRow(root->left, val, depth, nowDepth+1);
        addOneRow(root->right, val, depth, nowDepth+1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* head = new TreeNode(0, root, nullptr);
        addOneRow(head, val, depth, 0);
        return head->left;
    }
};
