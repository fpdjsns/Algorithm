/**
 * problem: https://leetcode.com/problems/linked-list-cycle-ii/
 * time complexity : O(NlogN)
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
    set<ListNode*> s;
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        
        set<ListNode*>::iterator it = s.find(head);
        if(it != s.end())
            return *it;
        if(head!=NULL) s.insert(head);
        
        ListNode* ans = detectCycle(head->next);
        return ans;
    }
};
