/**
 * problem : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
 * time complexity : O(N + M) // N = |root1|, M = |root2|
 * data structure : binary search tree
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
    queue<int> q;
    void search(queue<int>& q, TreeNode* node) {
        if(node == nullptr) return;
        search(q, node->left);
        q.push(node->val);
        search(q, node->right);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        queue<int> q1, q2;
        search(q1, root1);
        search(q2, root2);
        
        vector<int> answer;
        while(!q1.empty() && !q2.empty()) {
            if(q1.front() < q2.front()) {
                answer.push_back(q1.front());
                q1.pop();
            } else {
                answer.push_back(q2.front());
                q2.pop();
            }
        }
        while(!q1.empty()) {answer.push_back(q1.front()); q1.pop();}
        while(!q2.empty()) {answer.push_back(q2.front()); q2.pop();}
        return answer;
    }
};
