/**
 * problem : https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
 * algorithm : dfs
 * time complexity : O(N). N = Number of node
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
    int answer;
    
    void setSum(TreeNode* root, int sum){
        if(root == nullptr) return;
        
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr){
            answer += sum;
            return;
        }
        setSum(root->left, sum*2);
        setSum(root->right, sum*2);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        answer = 0;
        setSum(root, 0);
        return answer;
    }
};
