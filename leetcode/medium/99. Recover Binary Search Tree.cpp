/**
 * problem : https://leetcode.com/problems/recover-binary-search-tree/
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
    pair<TreeNode*, TreeNode*> willBeChanged;
    TreeNode* prev;
    // left -> root -> right
    void inorder(TreeNode* node) {
        if(node == nullptr) return;
        
        inorder(node->left);
        
        if(prev != nullptr && node->val < prev->val){
            if(willBeChanged.first == nullptr) 
                willBeChanged.first = prev;
            willBeChanged.second = node;
        }
        prev = node;
        
        inorder(node->right);
    }
public:
    void recoverTree(TreeNode* root) {
        willBeChanged = pair<TreeNode*, TreeNode*>();
        inorder(root);
        swap(willBeChanged.first->val, willBeChanged.second->val);
    }
};
