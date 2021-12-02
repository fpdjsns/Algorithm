/**
 * problem : https://leetcode.com/problems/rotate-list/
 * time complexity : O(N)
 * data structure : linked list
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        
        int cnt = 1; // include head node
        ListNode* lastNode = head;
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
            cnt++;
        }
        k %= cnt;
        if(k == 0) return head;
        
        k = cnt - k;
        ListNode* node = head;
        ListNode* prev = NULL;
        while(k--) {
            prev = node;
            node = node->next;
        }
        lastNode->next = head;
        if(prev) prev->next = NULL;
        return node;
    }
};
