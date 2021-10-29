/**
 * problem : https://leetcode.com/problems/count-complete-tree-nodes/
 * time complexity : O(log2N * log2N)
 * data structure : tree
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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        TreeNode* left = root;
        TreeNode* right = root;
        int lDepth = 1;
        int rDepth = 1;
        
        while(left->left != NULL) { left = left->left; lDepth++; };
        while(right->right != NULL) { right = right->right; rDepth++; };
        
        return lDepth == rDepth ?
            pow(2,lDepth)-1 : // Perfect Binary Tree node cnt
            countNodes(root->left) + countNodes(root->right) + 1;
    }
};
