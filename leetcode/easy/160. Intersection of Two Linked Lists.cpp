/**
 * problem : https://leetcode.com/problems/intersection-of-two-linked-lists/
 * time complexity : O(N+M)
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        
        while(node1 != NULL && node2 != NULL) {
            if(node1 == node2) return node1;
            
            node1 = node1->next;
            node2 = node2->next;
            
            if(node1 == NULL && node2 == NULL) return NULL;
            if(node1 == NULL) node1 = headB;
            if(node2 == NULL) node2 = headA;
        }
        
        return NULL;
    }
};
