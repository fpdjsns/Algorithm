/**
 * problem : https://leetcode.com/problems/binary-tree-tilt/
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
    int answer = 0;
    
    int getSum(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = getSum(root->left);
        int right = getSum(root->right);
        answer += abs(left - right);
        return left + right + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        answer = 0;
        getSum(root);
        return answer;
    }
};
