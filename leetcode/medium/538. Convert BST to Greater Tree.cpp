/**
 * problem : https://leetcode.com/problems/convert-bst-to-greater-tree/
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
    // right -> root -> left
    void convert(TreeNode* node, int& sum) {
        if(node==nullptr) return;
        convert(node->right, sum);
        sum += node->val;
        node->val = sum;
        convert(node->left, sum);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root, sum);
        return root;
    }
};
