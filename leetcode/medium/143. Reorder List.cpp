/**
 * problem : https://leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        int cnt = 0;
        stack<ListNode*> st;
        ListNode* tmp = head;
        while(tmp != nullptr) {
            st.push(tmp);
            tmp = tmp->next;
            cnt++;
        }
        ListNode* startNode = head;
        ListNode* lastNode;
        for(int i=0; i < (cnt+1)/2; i++){
            tmp = startNode->next;
            lastNode = st.top();
            st.pop();
            startNode->next = lastNode;
            lastNode->next = tmp;
            startNode = tmp;
        }
        lastNode->next = nullptr;
    }
};
