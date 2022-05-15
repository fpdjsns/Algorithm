/**
 * problem : https://leetcode.com/problems/deepest-leaves-sum/
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
    int deep;
    int answer;
    void search(TreeNode* node, int depth) {
        if(node == nullptr) return;
        if(depth > deep) {
            deep = depth;
            answer = 0;
        }
        if(depth == deep) answer+= node->val;
        
        search(node->left, depth+1);
        search(node->right, depth+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        answer = 0;
        deep = 0;
        search(root, 0);
        return answer;
    }
};
