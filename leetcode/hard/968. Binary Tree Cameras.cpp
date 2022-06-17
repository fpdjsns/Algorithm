/**
 * problem : https://leetcode.com/problems/binary-tree-cameras/
 * time complexity : O(V+E)
 * algorithm : DFS, Greedy
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
    const int NOT_MONITORED = 0;
    const int MONITORED = 1;
    const int SET_CAMERA = 2;
    
    int answer = 0;
    int dfs(TreeNode* node) {
        if(node == nullptr) return MONITORED;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        int res = NOT_MONITORED;
        if(left == NOT_MONITORED || right == NOT_MONITORED) {
            res = SET_CAMERA;
        } else if(left == SET_CAMERA || right == SET_CAMERA) {
            res = MONITORED;
        }
        answer += (res == SET_CAMERA);
        return res;
    }
public:
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == NOT_MONITORED) answer++;
        return answer;
    }
};
