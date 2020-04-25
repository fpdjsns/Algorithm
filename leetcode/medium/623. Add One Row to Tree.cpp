/**
 * problem : https://leetcode.com/problems/add-one-row-to-tree/
 * data structure : tree
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
    void insert(TreeNode* now, int v) {
        TreeNode* tmp = now->left;
        TreeNode* newNode = new TreeNode(v);
        newNode->left = tmp;
        now->left = newNode;
                
        tmp = now->right;
        TreeNode* newNode2 = new TreeNode(v);
        newNode2->right = tmp;
        now->right = newNode2;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        stack<pair<TreeNode*, int>> st; // {node, depth} 
        st.push({root, 1});
        
        while(!st.empty()) {
            TreeNode* now = st.top().first;
            int depth = st.top().second + 1;
            st.pop();
            
            if(depth == d) {
                insert(now, v);
            } else {
                if(now->left != NULL) st.push({now->left, depth});
                if(now->right != NULL) st.push({now->right, depth});
            }
        }
        return root;
    }
};
