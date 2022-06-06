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
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;

     while(nodeA && nodeB) {
            if(nodeA == nodeB) return nodeA;
            nodeA = nodeA->next;
            nodeB = nodeB->next;
            
            if(!nodeA && !nodeB) return NULL;
            if(!nodeA) nodeA = headB;
            if(!nodeB) nodeB = headA;
        }
        return NULL;
    }
};
