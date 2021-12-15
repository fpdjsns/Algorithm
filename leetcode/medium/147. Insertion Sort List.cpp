/**
 * problem : https://leetcode.com/problems/insertion-sort-list/
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
	ListNode* insertionSortList(ListNode* head) {
		ListNode* newHead = new ListNode();
		ListNode* originNode = head;

		while(originNode != NULL){
			ListNode* originNext = originNode->next;
		    ListNode* newPrev = newHead;
            
            // find correct position in sorted list
			while(newPrev->next != NULL && newPrev->next->val < originNode->val)
				newPrev= newPrev->next;
            
            // newPrev -> originNode -> (newPrev->next)
			originNode->next = newPrev->next;
			newPrev->next = originNode;
            
			originNode = originNext;
		}
		return newHead->next;
	}
};
