/**
 * problem : https://leetcode.com/problems/clone-graph/
 * time complexity : O(N+M) // N = the number of tree's node, M = the number of tree's edge * 2 
 * data structure : Tree
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        queue<pair<Node*, Node*>> q;
        Node* newRoot = new Node(node->val);
        q.push({node, newRoot});
        map<int, Node*> dict;
        dict[newRoot->val] = newRoot;
        
        while(!q.empty()){
            Node* legacy = q.front().first;
            Node* newNode = q.front().second;
            q.pop();
            
            for(auto neighbor: legacy->neighbors){
                if(dict.find(neighbor->val) != dict.end()) {
                    (newNode->neighbors).push_back(dict[neighbor->val]);
                    continue;
                }
                Node* tmp = new Node(neighbor->val);
                (newNode->neighbors).push_back(tmp);
                dict[tmp->val] = tmp;
                q.push({neighbor, tmp});
            }
        }
        return newRoot;
    }
};
