/*
 * 문제 : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
 * 시간복잡도 : O(N)
 * 알고리즘 : Linked List
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
public:  
    ListNode* removeZeroSumSublists(ListNode* head) {

        // 정답이 될 루트 노드 생성. 헤더는 0으로 세팅한다.
        // 가감산 결과로 0이 나왔을 때 (모든 리스트 삭제) 노드가 없기 때문에 연산이 어려울 수 있기 때문에
        ListNode* root = new ListNode(0);
        root->next = head;
        unordered_map<int, ListNode*> m; // sum, ListNode*
        m.insert({0, root});
        
        int sum = 0;
        
        while (head != NULL) {
            sum += head->val;

            // sum을 가지는 노드가 있는지 map에서 찾는다.
            unordered_map<int, ListNode*>::iterator it = m.find(sum);
            
            if (it == m.end()) { // 없는 경우
                m[sum] = head; 
            }
            else { 
                // 지워진 노드들은 다음 탐색 때 검색되면 안되므로 map에서 삭제되어야 한다
                int tmpSum = sum;
                ListNode* node = m[sum]->next;
                while(node != head) {
                    tmpSum += node->val;
                    if(tmpSum != sum) m.erase(tmpSum);
                    node = node->next;
                }
                
                // next는 현재 탐색 노드의 다음 노드를 가리킴
                m[sum]->next = head->next;
            }

            head = head->next; // 다음 헤더 탐색
        }

        return answer->next;
    }
};
