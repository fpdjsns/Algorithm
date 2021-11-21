/**
 * problem : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * time complexity : O(N) N = count of nodes
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
    unordered_map<int, int> inorderDict;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int leftIn, int rightIn, int leftPost, int rightPost) {
        if(leftIn > rightIn) return NULL;
        
        int rootVal = postorder[rightPost];
        TreeNode* head = new TreeNode(rootVal);
        int inorderRootIndex = inorderDict[rootVal];
        head->left = buildTree(inorder, postorder, leftIn, inorderRootIndex-1, leftPost, leftPost+ inorderRootIndex-leftIn-1);
        head->right = buildTree(inorder, postorder, inorderRootIndex+1, rightIn, leftPost+ inorderRootIndex-leftIn, rightPost-1);
        return head;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i < inorder.size(); i++) inorderDict[inorder[i]] = i;
        return buildTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
