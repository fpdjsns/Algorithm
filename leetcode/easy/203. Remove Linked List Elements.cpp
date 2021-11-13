/**
 * problem : https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* before = nullptr;
        ListNode* now = head;
        while(now != nullptr){
            if(now->val != val) {
                before = now;
                now = now->next;
                continue;
            }
            
            if(before == nullptr) head = now->next;
            else before->next = now->next;
            now = now->next;
        }
        return head;
    }
};
