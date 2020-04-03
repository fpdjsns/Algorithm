/**
 * problem : https://leetcode.com/problems/reverse-linked-list/
 * time complexity : O(N)
 * data structure : Linked list
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* prev = head;
        head = head->next;
        prev->next = NULL;
        while(head != NULL){
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};
