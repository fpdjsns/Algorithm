/**
 * problem : https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 * time complexity : O(N)
 * data structure : queue
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> answer;
        if(root != NULL) q.push(root);
        while(!q.empty()){
            answer.push_back(vector<int>());
            queue<Node*> newQ;
            while(!q.empty()){
                Node* node = q.front(); q.pop();
                answer.back().push_back(node->val);
                if(node == NULL) continue;
                for(auto next : node->children){
                    newQ.push(next);
                }
            }
            q = newQ;
        }
        return answer;
    }
};
