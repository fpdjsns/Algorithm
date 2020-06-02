/**
 * problem : https://leetcode.com/problems/invert-binary-tree/
 * time complexity : O(V)
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
    TreeNode* invert(TreeNode* search, TreeNode* save) {
        if(search == NULL)
            return NULL;
        save = new TreeNode(search->val);
        save->right = invert(search->left, save->right);
        save->left = invert(search->right, save->left);
        return save;
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        return invert(root, NULL);
    }
};
