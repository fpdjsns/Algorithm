/**
 * problem : https://leetcode.com/problems/unique-binary-search-trees-ii/
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
    vector<TreeNode*> makeBST(int l, int r) {
        if(l > r) 
            return {nullptr};
        
        vector<TreeNode*> trees;
        for(int m=l; m<=r; m++){
            vector<TreeNode*> lefts = makeBST(l, m-1);
            vector<TreeNode*> rights = makeBST(m+1, r);
            for(auto left: lefts) {
                for(auto right: rights) {
                    TreeNode* head = new TreeNode(m);
                    head->left = left;
                    head->right = right;
                    trees.push_back(head);                    
                }
            }
        }
        return trees;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return makeBST(1, n);
    }
};
