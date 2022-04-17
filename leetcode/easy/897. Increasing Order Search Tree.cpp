/**
 * problem : 
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
    TreeNode* head;
    TreeNode* now;
    
    void set(TreeNode* root) {
        if(root->left != nullptr) {
            set(root->left);
            root->left = nullptr;
        }
        
        if(head == nullptr)
            head = root;
        if(now != nullptr){
            now->right = root;
        }
        now = root;
        if(root->right != nullptr)
            set(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr) 
            return nullptr;
        set(root);
        return head;
    }
};
