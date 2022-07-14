/**
 * problem : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * time complexity : O(N)
 * data structure : binary tree
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                  int preStart, int inStart, int inEnd) {
        if(inStart > inEnd) return nullptr;
        
        int root = preorder[preStart];
        TreeNode* node = new TreeNode(root);
        int inRootIndex = find(inorder.begin(), inorder.end(), root) - inorder.begin();
        int size = (root == inorder[inStart]) ? 1 : inRootIndex - inStart + 1;
        
        node->left = buildTree(preorder, inorder, preStart + 1, inStart, inRootIndex-1);
        node->right = buildTree(preorder, inorder, preStart + size, inRootIndex + 1, inEnd);
        
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, 0, inorder.size()-1);
    }
};
