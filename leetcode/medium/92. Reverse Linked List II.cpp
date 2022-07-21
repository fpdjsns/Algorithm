/**
 * problem : https://leetcode.com/problems/reverse-linked-list-ii/
 * time complexity : O(N)
 * data structure : stack, linked-list
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start, end;
        ListNode* tmpHead = new ListNode(0, head);
        ListNode* node = tmpHead;
        ListNode* prev;
        ListNode* leftNode;
        ListNode* rightNode;
        ListNode* next;
        
        stack<ListNode*> st;
        for(int i=1; i<=right; i++){
            if(i == left) {
                prev = node;
            }
            node = node->next;
            if(i == left) leftNode = node;
            if(i == right) {
                rightNode = node;
            }
            if(i >= left && i <= right) {
                st.push(node);
            }
        }
        next = rightNode->next;
        
        node = prev;
        while(!st.empty()){
            node->next = st.top();
            st.pop();
            node = node->next;
        }
        prev->next = rightNode;
        leftNode->next = next;
        return tmpHead->next;
    }
};
