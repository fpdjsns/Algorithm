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
    ListNode* setNext(ListNode* node, int val) {
        ListNode* newNode = new ListNode(val);
        node->next = newNode;
        return newNode;
    }
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftHeader = new ListNode();
        ListNode* rightHeader = new ListNode();
        ListNode* left = leftHeader;
        ListNode* right = rightHeader;
        
        
        ListNode* node = head;
        while(node != nullptr) {
            if(node->val < x){
                left = setNext(left, node->val);
            } else {
                right = setNext(right, node->val);
            }
            node = node->next;
        }
        
        if(leftHeader->next == nullptr) leftHeader = rightHeader;
        else left->next = rightHeader->next;
        
        return leftHeader->next;
    }
};
