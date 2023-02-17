/**
 * problem : https://leetcode.com/problems/minimum-distance-between-bst-nodes/
 * time complexity : O(NlogN)
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
public:
    int minDiffInBST(TreeNode* root) {
        set<int> nums;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            nums.insert(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        int answer = 1e9;
        int lastNum = 1e9;
        for(auto num: nums){
            if(lastNum != 1e9) answer = min(num - lastNum, answer);
            lastNum = num;
        }

        return answer;
    }
};
