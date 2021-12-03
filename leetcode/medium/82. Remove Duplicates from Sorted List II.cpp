/**
 * problem : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * time complexity : O(N). N = |linked list|
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        ListNode* newHead = NULL;
        ListNode* prev = NULL;
        while(node != NULL) {
            if(node->next != NULL && node->val == node->next->val) {
                // delete nodes
                int tmp = node->val;
                while(node != NULL && node->val == tmp) 
                    node = node->next;
            } else {
                if(prev != NULL) 
                    prev->next = node;
                prev = node;
                if(newHead == NULL)
                    newHead = prev;
                node = node->next;
                prev->next = NULL;
            }
        }
        return newHead;
    }
};
