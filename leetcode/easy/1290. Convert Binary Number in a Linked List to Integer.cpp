/**
 * problem : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    int getDecimalValue(ListNode* head) {
        int answer = 0;
        while(head) {
            answer = answer * 2 + (head->val);
            head = head->next;
        }
        return answer;
    }
};
