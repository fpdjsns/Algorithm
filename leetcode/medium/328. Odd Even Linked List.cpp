/**
 * problem : https://leetcode.com/problems/odd-even-linked-list/
 * data structure : tree
 * time complexity : O(N)
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* root = new ListNode(head->val);
        ListNode* node = root;
        ListNode* tmp = head;
        while(tmp != NULL){
            if(tmp->next == NULL || tmp->next->next == NULL) break;
            tmp = tmp->next->next;
            node->next = new ListNode(tmp->val);
            node = node->next;
        }
        tmp = head->next;
        while(tmp != NULL){
            node->next = new ListNode(tmp->val);
            node = node->next;
            if(tmp->next == NULL || tmp->next->next == NULL) break;
            tmp = tmp->next->next;
        }
        return root;
    }
};
