/**
 * problem : https://leetcode.com/problems/merge-k-sorted-lists/
 * time complexity : O(NM). N = k, M = lists[i].length.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* now = nullptr;
        ListNode* next = nullptr; 
        
        while(1) {
            
            int minInd = -1;
            next = nullptr;
            
            for(int i=0; i<lists.size(); i++) {
                ListNode* node = lists[i];
                if(node == nullptr) continue;

                // find minimum node
                if(next == nullptr || node->val < next->val) {
                    next = node;
                    minInd = i;
                }
            }

            if(next == nullptr) break;
            if(now == nullptr) {
                now = next;
                head = now;
            } else {
                now->next = next;                
            }
    
            lists[minInd] = lists[minInd]->next;
            next->next = nullptr;
            now = next;
        }
        
        return head;
    }
};
