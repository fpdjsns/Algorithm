/**
 * problem : https://leetcode.com/problems/kth-largest-element-in-an-array/
 * time complexity : O(NlogK)
 * data structure : priority queue
 */
 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto num: nums) {
            q.push(-num);
            if(q.size() > k) {
                q.pop();
            }
        }
        return -q.top();
    }
};
