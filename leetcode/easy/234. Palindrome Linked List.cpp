/**
 * problem : https://leetcode.com/problems/palindrome-linked-list/
 * time complexity : O(N)
 * extra space complexity : O(1)
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
    bool isPalindrome(ListNode* head) {
        ListNode* node = head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr;
        while(slow) {
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        
        slow = prev;
        node = head;
        while(node && slow) {
            // cout << node->val << " " << slow->val << endl;
            if(node->val != slow->val) return false;
            node=node->next;
            slow = slow->next;
        }
        
        return true;
    }
};
