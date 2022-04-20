/**
 * problem : https://leetcode.com/problems/binary-search-tree-iterator/
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
class BSTIterator {
    stack<TreeNode*> st;
    
    void push(TreeNode* node) {
        while(node) {
            st.push(node);
            node=node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        st = stack<TreeNode*>();
        push(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        push(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
