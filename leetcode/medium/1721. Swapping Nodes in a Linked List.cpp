/**
 * problem : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
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
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        ListNode* node = head;
        while(node != nullptr) {
            length++; node = node->next;
        }
        if(length<=1) return head;
        ListNode* a = head;
        ListNode* b = head;
        int index = 1;
        node = head;
        while(node != nullptr) {
            if(index == k) a = node;
            if(index == (length-k+1)) b = node;
            index++;
            node = node->next;
        }
        swap(a->val, b->val);
        return head;
    }
};
