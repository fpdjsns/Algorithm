/**
 * problem : https://leetcode.com/problems/insert-into-a-binary-search-tree/
 * data structure : BST
 * time complexity : O(logN)
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        TreeNode* newNode = new TreeNode(val);
        
        while(node != NULL){
            TreeNode* next = node->val < val ? node->right : node->left;
            if(next == NULL){
                if(node->val < val) node->right = newNode;
                else node->left = newNode;
                break;
            }
            node = next;
        }
        
        return root == NULL ? newNode : root;
    }
};
