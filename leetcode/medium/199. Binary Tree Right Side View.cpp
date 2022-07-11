/**
 * problem : https://leetcode.com/problems/binary-tree-right-side-view/
 * time complexity : O(N) // N = |tree|
 * algorithm : binary search tree
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
    void search(TreeNode* node, int depth, vector<int>& answer) {
        if(node == NULL) return;
        if(depth >= answer.size()) answer.push_back(node->val);
        if(node->right) search(node->right, depth+1, answer);
        if(node->left) search(node->left, depth+1, answer);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        search(root, 0, answer);
        return answer;
    }
};
