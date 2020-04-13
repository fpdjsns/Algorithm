/**
 * problem : https://leetcode.com/problems/last-stone-weight/
 * algorithm : Heap
 * time complexity : O(NlogN)
 */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i=0;i<stones.size();i++)
            q.push(stones[i]);
        while(q.size() > 1){
            int tmp = q.top(); q.pop();
            tmp = tmp - q.top(); q.pop();
            if(tmp != 0) q.push(tmp);
        }
        return q.empty() ? 0 : q.top();
    }
};
