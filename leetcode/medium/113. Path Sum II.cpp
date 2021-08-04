/**
 * problem : https://leetcode.com/problems/path-sum-ii/
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
    vector<vector<int>> answer;
    void setSum(TreeNode* node, int targetSum, int sum, vector<int>& path) {
        if(node == NULL) return;
        
        sum += node->val;
        path.push_back(node->val);
        
        if(node->left == nullptr && node->right == nullptr) { // leaf
            if(sum == targetSum)
                answer.push_back(path);
        } else {
            setSum(node->left, targetSum, sum, path);
            setSum(node->right, targetSum, sum, path);
        }
    
        path.pop_back();
    }
  
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        answer.clear();
        vector<int> path;
        setSum(root, targetSum, 0, path);
        return answer;
    }
};
