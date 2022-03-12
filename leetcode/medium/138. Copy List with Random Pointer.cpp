/**
 * problem : https://leetcode.com/problems/copy-list-with-random-pointer/
 * time/space complexity : O(N) // N = |head|
 */
 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = new Node(0);
        Node* node = newHead;
        Node* searchNode = head;
        unordered_map<Node*, Node*> dict;
        
        // set next
        while(searchNode) {
            Node* newNode = new Node(searchNode->val);
            node->next = newNode;
            node = node->next;
            dict[searchNode] = newNode;
            searchNode = searchNode->next;
        }
        
        // set random
        searchNode = head;
        while(searchNode) {
            if(searchNode->random)
                dict[searchNode]->random = dict[searchNode->random];
            searchNode = searchNode->next;
        }
        
        return newHead->next;
    }
};
