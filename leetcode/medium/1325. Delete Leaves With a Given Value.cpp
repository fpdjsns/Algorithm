/**
 * problem: https://leetcode.com/problems/delete-leaves-with-a-given-value/
 * time complexity: O(NlogN)
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL) return NULL;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        // reaf node
        if(root->left == NULL && root->right == NULL){
            if(root->val == target) return NULL;
            else return root;
        }
        return root;
    }
};
