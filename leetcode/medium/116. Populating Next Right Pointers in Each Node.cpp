/**
 * problem : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * time complexity : O(N)
 * algorithm : DFS (preorder)
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    map<int, Node*> m;
    
    void connect(Node* root, int depth) {
        if(root == NULL) return;
        if(m[depth] != NULL){
            m[depth]->next = root;
        }
        m[depth] = root;
        
        connect(root->left, depth+1);
        connect(root->right, depth+1);
    }
public:
    Node* connect(Node* root) {
        connect(root, 0);
        return root;
    }
};
