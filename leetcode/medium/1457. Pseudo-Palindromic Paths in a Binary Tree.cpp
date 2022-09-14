/**
 * problem : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
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
    int getCnt(TreeNode* node, vector<int>& cnts) {
        if(node == NULL) return 0;
        cnts[node->val]++;
        
        int ans = 0;
        if (node->left == nullptr && node->right == nullptr) {
            int oddCnt = 0;
            for(auto cnt: cnts) oddCnt += (cnt % 2 == 1);
            ans = oddCnt <= 1;
        } else {
            ans = getCnt(node->left, cnts) + getCnt(node->right, cnts);
        }
        
        cnts[node->val]--;
        return ans;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnts(10, 0);
        return getCnt(root, cnts);
    }
};
