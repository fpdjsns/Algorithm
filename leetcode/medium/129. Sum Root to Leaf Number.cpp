/**
 * problem : https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    int go(TreeNode* node, int now) {
        if(node == NULL) return 0;
        
        now *= 10;
        now += node->val;
        if(node-> left == NULL && node->right == NULL)
            return now;
        
        return go(node->left, now) + go(node->right, now);
    }
public:
    int sumNumbers(TreeNode* root) {
        return go(root, 0);
    }
};
