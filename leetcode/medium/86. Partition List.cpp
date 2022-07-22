/**
 * problem : https://leetcode.com/problems/partition-list/
 * time complexity : O(N)
 * data structure : ListNode
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
    ListNode* set(ListNode* node, ListNode* next) {
        node->next = next;
        return node->next;
    }
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftHead = new ListNode();
        ListNode* rightHead = new ListNode();
        ListNode* left = leftHead;
        ListNode* right = rightHead;
        
        ListNode* node = head;
        while(node) {
            if(node->val < x) left = set(left, node);
            else right = set(right, node);
            node = node->next;
        }
        right->next = nullptr;
        set(left, rightHead->next);
        
        return leftHead->next;
    }
};
