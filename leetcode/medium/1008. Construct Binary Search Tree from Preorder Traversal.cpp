/**
 * problem : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
 * time complexity : O(NlogN)
 * algorithm : Divide and Conquer
 */
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<pair<TreeNode*, pair<int, int>>> st;
        st.push({root, {1, preorder.size()}});
        while(!st.empty()){
            TreeNode* node = st.top().first;
            // [left, right)
            int left = st.top().second.first;
            int right = st.top().second.second;
            st.pop();
            
            if(left >= right) continue;
            int m = left;
            while(m < right && node->val > preorder[m]) m++;
            if(m > left) { // exist left child
                node->left = new TreeNode(preorder[left]);
                st.push({node->left, {left+1, m}});
            }
            if(m < right) { // exist right child
                node->right = new TreeNode(preorder[m]);
                st.push({node->right, {m+1, right}});
            }
        }
        return root;
    }
};
