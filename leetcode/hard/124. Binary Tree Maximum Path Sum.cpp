/**
 * problem : https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * data structure : Tree
 * time complexity : O(N). N = number of nodes
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
    int ans = -1e9;
    int maxSum(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = root->val;
        
        int left = max(0, maxSum(root->left));
        int right = max(0, maxSum(root->right));
        ans = max(ans, sum + left + right);
        sum += max(left, right);
        ans = max(ans, sum);
        return sum;
    }
public:
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ans;
    }
};
