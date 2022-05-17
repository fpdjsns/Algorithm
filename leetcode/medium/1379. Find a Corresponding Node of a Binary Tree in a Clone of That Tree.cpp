/**
 * problem : https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
 * time complexity : O(N)
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == nullptr) return nullptr;
        if(original->val == target->val) return cloned;
        
        TreeNode* ans = nullptr;
        ans = getTargetCopy(original->left, cloned->left, target);
        if(ans) return ans;
        return getTargetCopy(original->right, cloned->right, target);
    }
};
