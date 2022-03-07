/**
 * problem : https://leetcode.com/problems/merge-two-sorted-lists/
 * time complexity : O(|list1| + |list2|)
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
    ListNode* set(ListNode* src, ListNode* next) {
        ListNode* last = next->next;
        src->next = next;
        next->next = nullptr;
        return last;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* now = head;
        while(list1 && list2) {
            if(list1->val < list2->val) list1 = set(now, list1);
            else list2 = set(now, list2);
            now = now->next;
        }
        while(list1) { list1 = set(now, list1); now = now->next; }
        while(list2) { list2 = set(now, list2); now = now->next; }
        return head->next;
    }
};
