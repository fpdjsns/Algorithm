/**
 * problem : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 * time complexity : O(N)
 * algorithm : DFS
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* before;
    void dfs(Node* now) {
        if(now == nullptr) 
            return;
        
        Node* next = now->next;
        Node* child = now->child;
        
        if(before != nullptr){
            now->prev = before;
            before->next = now;
        }
        now->child = nullptr;
        
        before = now;
        
        dfs(child);
        dfs(next);
    }
public:
    Node* flatten(Node* head) {
        before = nullptr;
        dfs(head);
        return head;
    }
};
