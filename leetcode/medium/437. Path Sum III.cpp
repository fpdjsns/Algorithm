/**
 * problem : https://leetcode.com/problems/path-sum-iii/
 * time/space complexity : O(N)
 * algorithm : back tracking
 **/
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
    int search(TreeNode* node, int targetSum, int sum, map<int, int>& subSums) {
        if(node == NULL) 
            return 0;
        
        sum += node->val;
        int answer = subSums[sum-targetSum];
        
        subSums[sum]++; 
        answer += search(node->left, targetSum, sum, subSums);
        answer += search(node->right, targetSum, sum, subSums);
        subSums[sum]--;
        
        return answer;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        map<int,int> subSums;
        subSums[0] = 1;
        return search(root, targetSum, 0, subSums);
    }
};
